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

private:
    Ui::Dialog *ui;
    sp _spx;
};
#endif // DIALOG_H
