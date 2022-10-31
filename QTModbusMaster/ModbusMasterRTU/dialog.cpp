#include "dialog.h"
#include "ui_dialog.h"
#include <iostream>
#include <QDateTime>

Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dialog)
{
    ui->setupUi(this);
    update_sp_combo_box();
    update_modbus_fcn_combo_box();
    _mb.setSlaveAddress(1);
    init_sp_timer();
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::update_txt_status(QString Msg, QColor c)
{
    ui->txt_sts->setTextColor(c);
    QString dt_str = QDateTime::currentDateTime().toString("hh:mm:ss:zzz");
    ui->txt_sts->append("[" + dt_str + "] " + Msg);
    //ui->txt_sts->append("\n");
}

void Dialog::update_sp_combo_box()
{
    if(_spx.getSPCount() == 0){
        update_txt_status("No COM Port Available", Qt::red);
    }
    else
    {
        _spx.find_available_serial_ports();
        ui->cbx_spx->clear();
        QString str = " Available COM Ports:  ";
        for(auto spn : _spx.getSPNames()){
            ui->cbx_spx->addItem(spn);
            str+= spn;
            str+= "\t";
        }
        update_txt_status(QString::number(_spx.getSPCount()) + str, Qt::green);
    }
}

void Dialog::update_modbus_fcn_combo_box()
{
    ui->cbx_modbus_fcn->clear();
    ui->cbx_modbus_fcn->addItem("Read Input Register (4)");
}

void Dialog::init_sp_receive_event()
{
    connect(&_spx.getSPObject(), &QSerialPort::readyRead, this, &Dialog::on_sp_receive);
}

void Dialog::update_modbus_params()
{
    _mb.setSlaveAddress((quint8) ui->nud_slv_add->value());
    _mb.setMemoryAddress((quint16) ui->nud_mem_add->value());
    _mb.setDataLength((quint16) ui->nud_data_len->value());
}

void Dialog::init_sp_timer()
{
    _sp_tim.setInterval(600);
    connect(&_sp_tim, &QTimer::timeout, this, &Dialog::on_sp_timer_tick);
}

void Dialog::on_btn_find_spx_clicked()
{
    update_sp_combo_box();

}

void Dialog::on_btn_connect_clicked()
{
    if(_spx.getSPCount() != 0)
    {
        _spx.open(_spx.getSPNames().at(_sp_selected_idx));
        init_sp_receive_event();
        update_txt_status("Connected to "+ _spx.getSPNames().at(_sp_selected_idx), Qt::green);
    }
    else
    {
         update_txt_status("No COM Port Available", Qt::red);
    }
}

void Dialog::on_btn_disconnect_clicked()
{
    if(_spx.IsSPOpen()){
        _spx.close();
         update_txt_status("Disconnected from "+ _spx.getSPNames().at(_sp_selected_idx), Qt::yellow);
    }
    else
    {
        update_txt_status("No COM Port Is Open", Qt::red);
    }
}

void Dialog::on_cbx_spx_currentIndexChanged(int index)
{
    if(_spx.getSPCount()!= 0){
       _sp_selected_idx = index;
       QString str_buff = _spx.getSPNames().at(index) + " is selected.";
       update_txt_status(str_buff, Qt::yellow);
    }
}

void Dialog::on_btn_send_test_clicked()
{
    //QByteArray data = QByteArray::fromHex("01040000000131ca");
    update_modbus_params();
    _mb.ReadIunputRegisterPacket();
    _spx.send(_mb.getPacket());
    _sp_tim.setInterval(600);
    _sp_tim.setSingleShot(true);
    _sp_tim.start();
    QString DataAsString = QString::number(_mb.getPacket().length()) + " Bytes sent to " + _spx.getSPNames().at(_sp_selected_idx);
    update_txt_status(DataAsString , Qt::green);
    DataAsString = _mb.getPacket().toHex('-').toUpper();
    update_txt_status(DataAsString , Qt::yellow);
}

void Dialog::on_sp_receive()
{
     _sp_tim.stop();
    int rec_data_len = _spx.getSPObject().bytesAvailable();
    QByteArray data = _spx.getSPObject().readAll();
    if(data.length() != 0){
        QString DataAsString = QString::number(rec_data_len) + " Bytes Received from " +  _spx.getSPNames().at(_sp_selected_idx);
        update_txt_status(DataAsString, Qt::white);
        update_txt_status(data.toHex('-').toUpper(), Qt::yellow);

        _mb.ProcessModbusSlavePacket(data);
        if(_mb.getErrorCode() == 0){
            QVector<quint16> rec_u16 = _mb.getU16DataArray();
            QString rec_data_str = "Received U16 Array: ";
            for(int i = 0; i<rec_u16.length(); i++){
                //rec_data_str+= QString::number(rec_u16[i], 16 ).toUpper();
                rec_data_str+= QString("%1").arg(rec_u16[i], 4, 16,(QChar)'0').toUpper().prepend("0x");
                rec_data_str+= " - ";
            }
            update_txt_status(rec_data_str, Qt::white);
        }
        else{
            update_txt_status("Invalid packet, Errcode: " + QString::number(_mb.getErrorCode(), 16 ), Qt::red);
        }
    }

}

void Dialog::on_btn_clear_txt_clicked()
{
    ui->txt_sts->clear();
}

void Dialog::on_sp_timer_tick()
{
    update_txt_status("Modbus receive timeout!", Qt::red);
}

