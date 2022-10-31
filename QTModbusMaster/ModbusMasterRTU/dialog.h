#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QTimer>
#include "sp.h"
#include "modbus.h"

QT_BEGIN_NAMESPACE
namespace Ui { class Dialog; }
QT_END_NAMESPACE

class Dialog : public QDialog
{
    Q_OBJECT

public:
    Dialog(QWidget *parent = nullptr);
    ~Dialog();
    void update_txt_status(QString Msg, QColor c);
    void update_sp_combo_box();
    void update_modbus_fcn_combo_box();
    void init_sp_receive_event();
    void init_sp_receive_event(void(Dialog::* slotName )());
    void init_sp_receive_event(void(*slotName )());
    void init_sp_receive_event(QObject *Receiver,void(*ReceiverSlot )());
    void update_modbus_params();
    void init_sp_timer();

private slots:
    void on_btn_find_spx_clicked();

    void on_btn_connect_clicked();

    void on_btn_disconnect_clicked();

    void on_cbx_spx_currentIndexChanged(int index);

    void on_btn_send_test_clicked();

    void on_sp_receive();

    void on_btn_clear_txt_clicked();

    void on_sp_timer_tick();

    void on_checkBox_stateChanged(int arg1);

private:
    Ui::Dialog *ui;
    sp _spx;
    int _sp_selected_idx;
    Modbus _mb;
    QTimer _sp_tim;
};
#endif // DIALOG_H
