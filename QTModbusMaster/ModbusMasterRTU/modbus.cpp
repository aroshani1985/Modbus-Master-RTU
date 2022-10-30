#include "modbus.h"

Modbus::Modbus(QObject *parent, qint8 SlaveAddress)
    : QObject{parent}
{
    _slv_addr = SlaveAddress;
}

QByteArray Modbus::ReadIunputRegisterPacket()
{
    _len_pkt = 8;
    _pkt.resize(8);
    _pkt[0] = _slv_addr;
    _pkt[1] = ModBusFcnCode::ReadInputRegisters;
    _pkt[2] = _mem_add>>8 & 0xFF;
    _pkt[3] = _mem_add & 0xFF;
    _pkt[4] = _len_data>>8 & 0xFF;
    _pkt[5] = _len_data & 0xFF;
    MakeCRC(_pkt);
    return _pkt;
}
QByteArray Modbus::ReadIunputRegisterPacket(qint16 MemoryAddress, qint16 Length)
{
    _len_pkt = 8;
    _pkt.resize(8);
    _pkt[0] = _slv_addr;
    _pkt[1] = ModBusFcnCode::ReadInputRegisters;
    _mem_add =MemoryAddress - 1;
    _pkt[2] = _mem_add>>8 & 0xFF;
    _pkt[3] = _mem_add & 0xFF;
    _len_data = Length;
    _pkt[4] = _len_data>>8 & 0xFF;
    _pkt[5] = _len_data & 0xFF;
    MakeCRC(_pkt);
    return _pkt;
}

void Modbus::MakeCRC(QByteArray& Packet)
{
    _crc = 0xFFFF;
    int len = Packet.length() - 2;
    for (int pos = 0; pos < len; pos++)
    {
        _crc ^= (quint16)Packet[pos];          // XOR byte into least sig. byte of crc

        for (int i = 8; i != 0; i--)
        {    // Loop over each bit
            if ((_crc & 0x0001) != 0)
            {      // If the LSB is set
                _crc >>= 1;                    // Shift right and XOR 0xA001
                _crc ^= 0xA001;
            }
            else                            // Else LSB is not set
                _crc >>= 1;                    // Just shift right
        }
    }
    // Note, this number has low and high bytes swapped, so use it accordingly (or swap bytes)
    _crc_h = (quint8)((_crc >> 8) & 0xFF);
    _crc_l = (quint8)(_crc & 0xFF); // comes first
    Packet[Packet.length() - 2] = _crc_l;
    Packet[Packet.length() - 1] = _crc_h;
}

QByteArray Modbus::getPacket() const
{
    return _pkt;
}

void Modbus::setSlaveAddress(quint8 SlaveAddress)
{
    _slv_addr = SlaveAddress;
}

void Modbus::setMemoryAddress(quint16 MemoryAddress)
{
    _mem_add = MemoryAddress - 1;
}

void Modbus::setDataLength(quint16 DataLength)
{
    _len_data = DataLength;
}
