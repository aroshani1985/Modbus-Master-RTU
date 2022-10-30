#ifndef SP_H
#define SP_H

#include <QObject>

#include <QSerialPort>
#include <QSerialPortInfo>

#include <QVector>

class sp : public QObject
{
    Q_OBJECT
public:
    explicit sp(QObject *parent = nullptr);

    void find_available_serial_ports();
    void open(int sp_index);
    void open(QString sp_name);
    void close();

    int getSPCount() const;
    QVector<QString> getSPNames() const;

private:
     int _err_code;
     QString _err_msg;
     int _sp_count;
     QVector<QString> _sp_names;
     int _sp_selected_idx;
     QSerialPort _spx;


signals:

};

#endif // SP_H
