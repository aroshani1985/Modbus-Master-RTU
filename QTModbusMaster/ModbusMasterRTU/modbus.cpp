#include "modbus.h"

Modbus::Modbus(QObject *parent, qint8 SlaveAddress)
    : QObject{parent}
{
    _slv_addr = SlaveAddress;
    _is_float = false;
}

void Modbus::ReadIunputRegisterPacket()
{
    _send_pkt.resize(8);
    _len_pkt = 8;
    _send_pkt[0] = _slv_addr;
    _send_pkt[1] = ModBusFcnCode::ReadInputRegisters;
    _send_pkt[2] = _mem_add>>8 & 0xFF;
    _send_pkt[3] = _mem_add & 0xFF;
    _send_pkt[4] = _len_data>>8 & 0xFF;
    _send_pkt[5] = _len_data & 0xFF;
    MakeCRC();
}

void Modbus::ProcessModbusSlavePacket(QByteArray SlavePaclet)
{
    _err_code = 0;
    ConvertToQuint8(SlavePaclet);
    if(_rec_pkt_len < 5){
           _err_code = 1;
           return;
    }
    if (_rec_pkt[0] != _slv_addr){
           _err_code = 2;
           return;
    }
    if(!check_modbus_crc())
    {
        _err_code = 3;
        return;
    }
    if (!process_packet_parameters()){
        _err_code = 4;
        return;
    }
    if(_rec_pkt[1] == ModBusFcnCode::ReadInputRegisters){
        if(_is_float){
            ExtractFloatArray();
        }
        else{
            ExtractU16Array();
        }
    }
    else {
        _err_code = 5;
        return;
    }
}

void Modbus::MakeCRC()
{
    _crc = 0xFFFF;
    for (int pos = 0; pos < (_len_pkt-2); pos++)
    {
        _crc ^= (quint16)_send_pkt[pos];          // XOR byte into least sig. byte of crc

        for (int i = 8; i != 0; i--)
        {    // Loop over each bit
            if ((_crc & 0x0001) != 0)
            {      // If the LSB is set
                _crc >>= 1;                    // Shift right and XOR 0xA001
                _crc ^= 0xA001;
            }
            else                            // Else LSB is not set
                _crc >>=1;                    // Just shift right
        }
    }
    // Note, this number has low and high bytes swapped, so use it accordingly (or swap bytes)
    _crc_h = (quint8)((_crc >> 8) & 0xFF);
    _crc_l = (quint8)(_crc & 0xFF); // comes first

    _send_pkt[_len_pkt - 2] = _crc_l;
    _send_pkt[_len_pkt - 1] = _crc_h;
}

bool Modbus::check_modbus_crc()
{
    _crc = 0xFFFF;
    for (int pos = 0; pos < (_rec_pkt_len-2); pos++)
    {
        _crc ^= (quint16)_rec_pkt[pos];          // XOR byte into least sig. byte of crc

        for (int i = 8; i != 0; i--)
        {    // Loop over each bit
            if ((_crc & 0x0001) != 0)
            {      // If the LSB is set
                _crc >>= 1;                    // Shift right and XOR 0xA001
                _crc ^= 0xA001;
            }
            else                            // Else LSB is not set
                _crc >>=1;                    // Just shift right
        }
    }
    // Note, this number has low and high bytes swapped, so use it accordingly (or swap bytes)
    if (((_crc >> 8) & 0xFF) == _rec_pkt[_rec_pkt_len- 1] && (_crc & 0xFF) == _rec_pkt[_rec_pkt_len- 2])
        return true;
    else
        return false;
}

bool Modbus::process_packet_parameters()
{
    _len_data_slv = _rec_pkt[2];
    if (_len_data > 255)
        return false;

    return true;
}

void Modbus::ConvertToQuint8(QByteArray Packet){
    _rec_pkt_len = Packet.length();
    _rec_pkt.resize(_rec_pkt_len);
    for(int i = 0; i< _rec_pkt_len; i++)
    {
         _rec_pkt[i] = static_cast<quint8>(Packet[i]);
    }
}

//le little endian
float  Modbus::ExtractFloat(int index, bool is_le){
    QByteArray ba;
    ba.resize(4);
    if(is_le){
            //little endian  LSRF modscan
            ba[0] = _rec_pkt[4*index + 4];
            ba[1] = _rec_pkt[4*index + 3];
            ba[2] = _rec_pkt[4*index + 6];
            ba[3] = _rec_pkt[4*index + 5];
    }
    else{

        //big endian   MSRF modscan
        ba[0] = _rec_pkt[4*index + 6];
        ba[1] = _rec_pkt[4*index + 5];
        ba[2] = _rec_pkt[4*index + 4];
        ba[3] = _rec_pkt[4*index + 3];
    }
    float number =  *(reinterpret_cast<const float*>(ba.constData()));
    return number;
}

quint16 Modbus::ExtractU16(int index){
    quint16 val  = _rec_pkt[2*index + 3];
    val<<=8;
    val |= _rec_pkt[2*index + 1+3];
    return val;
}

QVector<quint16> Modbus::ExtractU16Array(){
    _data_u16_array.clear();
    _data_u16_len = _len_data_slv/2;
    for(int i = 0; i<_data_u16_len; i++){
        _data_u16_array.push_back(ExtractU16(i));
    }

    return _data_u16_array;
}

QVector<float> Modbus::ExtractFloatArray(){
    _data_float_array.clear();
    _data_float_len = _len_data_slv/4;
    for(int i = 0; i<_data_float_len; i++){
        _data_float_array.push_back(ExtractFloat(i, false));
    }

    return _data_float_array;
}

QByteArray Modbus::getPacket() const
{
    QByteArray pkt;
    pkt.resize(_len_pkt);
    for(int i =0; i<_len_pkt; i++){
        pkt[i] = _send_pkt[i];
    }
    return pkt;
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

void Modbus::setFloat(bool IsFloat)
{
    _is_float = IsFloat;
}

bool Modbus::getFloat()
{
    return _is_float;
}

QVector<quint16> Modbus::getU16DataArray()
{
    return _data_u16_array;
}

QVector<float> Modbus::getFloatDataArray()
{
    return _data_float_array;
}

int Modbus::getErrorCode()
{
    return _err_code;
}

