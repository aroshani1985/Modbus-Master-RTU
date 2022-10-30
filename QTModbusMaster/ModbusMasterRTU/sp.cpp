#include "sp.h"

sp::sp(QObject *parent)
    : QObject{parent}
{
    find_available_serial_ports();
}

void sp::find_available_serial_ports()
{
    _sp_count = 0;
    _sp_names.clear();

    Q_FOREACH(QSerialPortInfo port, QSerialPortInfo::availablePorts()) {
        _sp_names.push_back(port.portName());
        _sp_count++;
    }
}

void sp::open(int sp_index)
{
    if(sp_index >= _sp_count){
        _err_code = 1;
        return;
    }

    if(_spx.isOpen()){
        _spx.close();
    }

    _spx.setPortName(_sp_names[sp_index]);
    _spx.setBaudRate(QSerialPort::Baud9600);
    _spx.setDataBits(QSerialPort::Data8);
    _spx.setStopBits(QSerialPort::OneStop);
    _spx.setParity(QSerialPort::EvenParity);
    _spx.setFlowControl(QSerialPort::NoFlowControl);

    _spx.open(QIODevice::ReadWrite);
    //init_sp_receive();
}

void sp::open(QString sp_name)
{
    bool is_spn_exist = false;
    for(auto spn : _sp_names){
        if(spn == sp_name){
            is_spn_exist = true;
            break;
        }
    }
    if(!is_spn_exist){
        _err_code = 2;
        return;
    }
    if(_spx.isOpen()){
        _spx.close();
    }
    _spx.setPortName(sp_name);
    _spx.setBaudRate(QSerialPort::Baud9600);
    _spx.setDataBits(QSerialPort::Data8);
    _spx.setStopBits(QSerialPort::OneStop);
    _spx.setParity(QSerialPort::EvenParity);
    _spx.setFlowControl(QSerialPort::NoFlowControl);

    _spx.open(QIODevice::ReadWrite);
    //init_sp_receive();
}

void sp::close()
{
    if(_spx.isOpen()){
        _spx.close();
    }
}

int sp::getSPCount() const
{
    return _sp_count;
}

QVector<QString> sp::getSPNames() const
{
    return _sp_names;
}
