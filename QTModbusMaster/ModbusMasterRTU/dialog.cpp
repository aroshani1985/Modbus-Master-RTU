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

