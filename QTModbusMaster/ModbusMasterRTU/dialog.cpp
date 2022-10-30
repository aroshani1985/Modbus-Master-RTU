#include "dialog.h"
#include "ui_dialog.h"
#include <QDateTime>

Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dialog)
{
    ui->setupUi(this);
    update_sp_combo_box();

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

void Dialog::init_sp_receive_event()
{
    connect(&_spx.getSPObject(), &QSerialPort::readyRead, this, &Dialog::on_sp_receive);
}

void Dialog::on_pushButton_clicked()
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
    QByteArray data = QByteArray::fromHex("01040000000131ca");
    _spx.send(data);
    QString DataAsString = QString::number(data.length()) + " Bytes sent to " + _spx.getSPNames().at(_sp_selected_idx);
    update_txt_status(DataAsString , Qt::green);
    DataAsString = data.toHex('-').toUpper();
    update_txt_status(DataAsString , Qt::red);
}

void Dialog::on_sp_receive()
{
    int rec_data_len = _spx.getSPObject().bytesAvailable();
    QByteArray data = _spx.getSPObject().readAll();
    QString DataAsString = QString::number(rec_data_len) + " Bytes Received from " +  _spx.getSPNames().at(_sp_selected_idx);
    update_txt_status(DataAsString, Qt::white);
    update_txt_status(data.toHex('-').toUpper(), Qt::yellow);
}

