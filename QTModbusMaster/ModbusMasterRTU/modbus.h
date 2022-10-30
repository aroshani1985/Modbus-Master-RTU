#ifndef MODBUS_H
#define MODBUS_H

#include <QObject>

class Modbus : public QObject
{
    Q_OBJECT
public:
    explicit Modbus(QObject *parent = nullptr, qint8 SlaveAddress = 1);

    QByteArray ReadIunputRegisterPacket();
    QByteArray ReadIunputRegisterPacket(qint16 MemoryAddress, qint16 Length);

    QByteArray getPacket() const;
    void setSlaveAddress(quint8 SlaveAddress);
    void setMemoryAddress(quint16 MemoryAddress);
    void setDataLength(quint16 DataLength);

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
    quint8 _slv_addr;
    quint8 _fcn_code;
    quint16 _mem_add;
    quint16 _len_data;
    quint8 _len_pkt;
    quint8 _crc_h;
    quint8 _crc_l;
    quint16 _crc;
    QByteArray _pkt;
    void MakeCRC(QByteArray& Packet);

signals:

};

#endif // MODBUS_H
