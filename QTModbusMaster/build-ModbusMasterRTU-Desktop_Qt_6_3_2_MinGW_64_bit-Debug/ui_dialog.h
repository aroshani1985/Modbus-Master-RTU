/********************************************************************************
** Form generated from reading UI file 'dialog.ui'
**
** Created by: Qt User Interface Compiler version 6.3.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOG_H
#define UI_DIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Dialog
{
public:
    QVBoxLayout *verticalLayout_6;
    QGroupBox *groupBox;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout;
    QComboBox *cbx_spx;
    QPushButton *btn_find_spx;
    QPushButton *btn_connect;
    QPushButton *btn_disconnect;
    QGroupBox *groupBox_2;
    QPushButton *btn_send_test;
    QWidget *layoutWidget_2;
    QHBoxLayout *horizontalLayout_2;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QComboBox *cbx_modbus_fcn;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_2;
    QSpinBox *nud_slv_add;
    QVBoxLayout *verticalLayout_3;
    QLabel *label_3;
    QSpinBox *nud_mem_add;
    QVBoxLayout *verticalLayout_4;
    QLabel *label_4;
    QSpinBox *nud_data_len;
    QVBoxLayout *verticalLayout_5;
    QLabel *label_5;
    QCheckBox *checkBox;
    QPushButton *btn_clear_txt;
    QGroupBox *groupBox_3;
    QTextEdit *txt_sts;

    void setupUi(QDialog *Dialog)
    {
        if (Dialog->objectName().isEmpty())
            Dialog->setObjectName(QString::fromUtf8("Dialog"));
        Dialog->resize(800, 600);
        Dialog->setMinimumSize(QSize(800, 600));
        Dialog->setMaximumSize(QSize(800, 600));
        QIcon icon;
        icon.addFile(QString::fromUtf8("../../../../Dev14010704/qtconsole14010802/images/spicon.png"), QSize(), QIcon::Normal, QIcon::Off);
        Dialog->setWindowIcon(icon);
        verticalLayout_6 = new QVBoxLayout(Dialog);
        verticalLayout_6->setObjectName(QString::fromUtf8("verticalLayout_6"));
        groupBox = new QGroupBox(Dialog);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setMaximumSize(QSize(5000, 80));
        QFont font;
        font.setPointSize(10);
        font.setBold(true);
        groupBox->setFont(font);
        layoutWidget = new QWidget(groupBox);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(10, 30, 761, 42));
        horizontalLayout = new QHBoxLayout(layoutWidget);
        horizontalLayout->setSpacing(12);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        cbx_spx = new QComboBox(layoutWidget);
        cbx_spx->setObjectName(QString::fromUtf8("cbx_spx"));
        cbx_spx->setMinimumSize(QSize(300, 40));
        cbx_spx->setMaximumSize(QSize(200, 16777215));

        horizontalLayout->addWidget(cbx_spx);

        btn_find_spx = new QPushButton(layoutWidget);
        btn_find_spx->setObjectName(QString::fromUtf8("btn_find_spx"));
        btn_find_spx->setMinimumSize(QSize(0, 40));

        horizontalLayout->addWidget(btn_find_spx);

        btn_connect = new QPushButton(layoutWidget);
        btn_connect->setObjectName(QString::fromUtf8("btn_connect"));
        btn_connect->setMinimumSize(QSize(0, 40));

        horizontalLayout->addWidget(btn_connect);

        btn_disconnect = new QPushButton(layoutWidget);
        btn_disconnect->setObjectName(QString::fromUtf8("btn_disconnect"));
        btn_disconnect->setMinimumSize(QSize(0, 40));

        horizontalLayout->addWidget(btn_disconnect);


        verticalLayout_6->addWidget(groupBox);

        groupBox_2 = new QGroupBox(Dialog);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        groupBox_2->setFont(font);
        btn_send_test = new QPushButton(groupBox_2);
        btn_send_test->setObjectName(QString::fromUtf8("btn_send_test"));
        btn_send_test->setGeometry(QRect(10, 190, 201, 40));
        btn_send_test->setMinimumSize(QSize(0, 40));
        layoutWidget_2 = new QWidget(groupBox_2);
        layoutWidget_2->setObjectName(QString::fromUtf8("layoutWidget_2"));
        layoutWidget_2->setGeometry(QRect(10, 30, 761, 91));
        horizontalLayout_2 = new QHBoxLayout(layoutWidget_2);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        label = new QLabel(layoutWidget_2);
        label->setObjectName(QString::fromUtf8("label"));
        label->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(label);

        cbx_modbus_fcn = new QComboBox(layoutWidget_2);
        cbx_modbus_fcn->setObjectName(QString::fromUtf8("cbx_modbus_fcn"));
        cbx_modbus_fcn->setMinimumSize(QSize(200, 40));

        verticalLayout->addWidget(cbx_modbus_fcn);


        horizontalLayout_2->addLayout(verticalLayout);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        label_2 = new QLabel(layoutWidget_2);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setAlignment(Qt::AlignCenter);

        verticalLayout_2->addWidget(label_2);

        nud_slv_add = new QSpinBox(layoutWidget_2);
        nud_slv_add->setObjectName(QString::fromUtf8("nud_slv_add"));
        nud_slv_add->setMinimumSize(QSize(100, 40));
        nud_slv_add->setAlignment(Qt::AlignCenter);
        nud_slv_add->setReadOnly(false);
        nud_slv_add->setMinimum(1);
        nud_slv_add->setMaximum(255);

        verticalLayout_2->addWidget(nud_slv_add);


        horizontalLayout_2->addLayout(verticalLayout_2);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        label_3 = new QLabel(layoutWidget_2);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setAlignment(Qt::AlignCenter);

        verticalLayout_3->addWidget(label_3);

        nud_mem_add = new QSpinBox(layoutWidget_2);
        nud_mem_add->setObjectName(QString::fromUtf8("nud_mem_add"));
        nud_mem_add->setMinimumSize(QSize(100, 40));
        nud_mem_add->setAlignment(Qt::AlignCenter);
        nud_mem_add->setReadOnly(false);
        nud_mem_add->setMinimum(1);
        nud_mem_add->setMaximum(10000);

        verticalLayout_3->addWidget(nud_mem_add);


        horizontalLayout_2->addLayout(verticalLayout_3);

        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        label_4 = new QLabel(layoutWidget_2);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setAlignment(Qt::AlignCenter);

        verticalLayout_4->addWidget(label_4);

        nud_data_len = new QSpinBox(layoutWidget_2);
        nud_data_len->setObjectName(QString::fromUtf8("nud_data_len"));
        nud_data_len->setMinimumSize(QSize(100, 40));
        nud_data_len->setAlignment(Qt::AlignCenter);
        nud_data_len->setReadOnly(false);
        nud_data_len->setMinimum(1);
        nud_data_len->setMaximum(255);
        nud_data_len->setValue(1);

        verticalLayout_4->addWidget(nud_data_len);


        horizontalLayout_2->addLayout(verticalLayout_4);

        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        label_5 = new QLabel(layoutWidget_2);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setAlignment(Qt::AlignCenter);

        verticalLayout_5->addWidget(label_5);

        checkBox = new QCheckBox(layoutWidget_2);
        checkBox->setObjectName(QString::fromUtf8("checkBox"));
        checkBox->setMinimumSize(QSize(100, 40));

        verticalLayout_5->addWidget(checkBox);


        horizontalLayout_2->addLayout(verticalLayout_5);

        btn_clear_txt = new QPushButton(groupBox_2);
        btn_clear_txt->setObjectName(QString::fromUtf8("btn_clear_txt"));
        btn_clear_txt->setGeometry(QRect(570, 190, 201, 40));
        btn_clear_txt->setMinimumSize(QSize(0, 40));

        verticalLayout_6->addWidget(groupBox_2);

        groupBox_3 = new QGroupBox(Dialog);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        groupBox_3->setFont(font);
        txt_sts = new QTextEdit(groupBox_3);
        txt_sts->setObjectName(QString::fromUtf8("txt_sts"));
        txt_sts->setGeometry(QRect(10, 30, 761, 211));
        QPalette palette;
        QBrush brush(QColor(255, 255, 255, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Button, brush);
        palette.setBrush(QPalette::Active, QPalette::Midlight, brush);
        QBrush brush1(QColor(127, 127, 127, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Dark, brush1);
        QBrush brush2(QColor(170, 170, 170, 255));
        brush2.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Mid, brush2);
        QBrush brush3(QColor(0, 0, 0, 255));
        brush3.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Base, brush3);
        palette.setBrush(QPalette::Active, QPalette::Window, brush);
        palette.setBrush(QPalette::Active, QPalette::Shadow, brush3);
        palette.setBrush(QPalette::Active, QPalette::AlternateBase, brush3);
        QBrush brush4(QColor(240, 240, 240, 255));
        brush4.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Inactive, QPalette::Button, brush4);
        QBrush brush5(QColor(227, 227, 227, 255));
        brush5.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Inactive, QPalette::Midlight, brush5);
        QBrush brush6(QColor(160, 160, 160, 255));
        brush6.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Inactive, QPalette::Dark, brush6);
        palette.setBrush(QPalette::Inactive, QPalette::Mid, brush6);
        palette.setBrush(QPalette::Inactive, QPalette::Base, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Window, brush4);
        QBrush brush7(QColor(105, 105, 105, 255));
        brush7.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Inactive, QPalette::Shadow, brush7);
        QBrush brush8(QColor(233, 231, 227, 255));
        brush8.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush8);
        palette.setBrush(QPalette::Disabled, QPalette::Button, brush);
        palette.setBrush(QPalette::Disabled, QPalette::Midlight, brush);
        palette.setBrush(QPalette::Disabled, QPalette::Dark, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Mid, brush2);
        palette.setBrush(QPalette::Disabled, QPalette::Base, brush);
        palette.setBrush(QPalette::Disabled, QPalette::Window, brush);
        palette.setBrush(QPalette::Disabled, QPalette::Shadow, brush3);
        QBrush brush9(QColor(247, 247, 247, 255));
        brush9.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush9);
        txt_sts->setPalette(palette);

        verticalLayout_6->addWidget(groupBox_3);


        retranslateUi(Dialog);

        QMetaObject::connectSlotsByName(Dialog);
    } // setupUi

    void retranslateUi(QDialog *Dialog)
    {
        Dialog->setWindowTitle(QCoreApplication::translate("Dialog", "Modbus Master RTU ", nullptr));
        groupBox->setTitle(QCoreApplication::translate("Dialog", "Serial Poer Selection", nullptr));
        btn_find_spx->setText(QCoreApplication::translate("Dialog", "Find Serial Ports", nullptr));
        btn_connect->setText(QCoreApplication::translate("Dialog", "Connect", nullptr));
        btn_disconnect->setText(QCoreApplication::translate("Dialog", "Disconnect", nullptr));
        groupBox_2->setTitle(QCoreApplication::translate("Dialog", "Control Panel", nullptr));
        btn_send_test->setText(QCoreApplication::translate("Dialog", "Send Modbus Request", nullptr));
        label->setText(QCoreApplication::translate("Dialog", "Select Modbus Command", nullptr));
        label_2->setText(QCoreApplication::translate("Dialog", "Slave Address", nullptr));
        label_3->setText(QCoreApplication::translate("Dialog", "Memory Address", nullptr));
        label_4->setText(QCoreApplication::translate("Dialog", "Data Length", nullptr));
        label_5->setText(QCoreApplication::translate("Dialog", "Enable Floating Point", nullptr));
        checkBox->setText(QCoreApplication::translate("Dialog", "Single Precision", nullptr));
        btn_clear_txt->setText(QCoreApplication::translate("Dialog", "Clear ", nullptr));
        groupBox_3->setTitle(QCoreApplication::translate("Dialog", "Monitoring Panel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Dialog: public Ui_Dialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOG_H
