#ifndef SP_H
#define SP_H

#include <QObject>

#include <QSerialPort>
#include <QSerialPortInfo>

class sp : public QObject
{
    Q_OBJECT
public:
    explicit sp(QObject *parent = nullptr);


signals:

};

#endif // SP_H
