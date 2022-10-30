#ifndef MODBUS_H
#define MODBUS_H

#include <QObject>

class Modbus : public QObject
{
    Q_OBJECT
public:
    explicit Modbus(QObject *parent = nullptr, qint8 SlaveAddress = 1);

    void ReadIunputRegisterPacket();
    void ProcessModbusSlavePacket(QByteArray SlavePaclet);
    quint16 ExtractU16(int index);
    QVector<quint16> ExtractU16Array();

    QByteArray getPacket() const;
    void setSlaveAddress(quint8 SlaveAddress);
    void setMemoryAddress(quint16 MemoryAddress);
    void setDataLength(quint16 DataLength);
    QVector<quint16> getU16DataArray();
    int getErrorCode();

    enum ModBusFcnCode
    {
       ReadCoil = 1,
       ReadDiscreteInput = 2,
       ReadHoldingRegisters = 3,
       ReadInputRegisters = 4,
       WriteSingleCoil = 5,
       WriteSingleHoldingRegister = 6,
       WriteMultipleCoils = 15,
       WriteMultipleHoldingRegisters = 16
    };

 private:
    quint8 _err_code;
    quint8 _slv_addr;
    quint8 _fcn_code;
    quint16 _mem_add;
    quint16 _len_data;
    quint8 _len_pkt;
    quint8 _crc_h;
    quint8 _crc_l;
    quint16 _crc;
    bool _is_float;
    QVector<quint8> _send_pkt;
    QVector<quint8> _rec_pkt;
    uint8_t _rec_pkt_len;
    QVector<quint16> _data_u16_array;
    quint8 _data_u16_len;

    quint8 _len_data_slv;

    void ConvertToQuint8(QByteArray Packet);
    void MakeCRC();
    bool check_modbus_crc();
    bool process_packet_parameters();

signals:

};

#endif // MODBUS_H
