#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include "sp.h"

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

private slots:
    void on_pushButton_clicked();

    void on_btn_connect_clicked();

    void on_btn_disconnect_clicked();

    void on_cbx_spx_currentIndexChanged(int index);

    void on_btn_send_test_clicked();

private:
    Ui::Dialog *ui;
    sp _spx;
    int _sp_selected_idx;
};
#endif // DIALOG_H
