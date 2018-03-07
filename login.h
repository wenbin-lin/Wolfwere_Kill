#ifndef LOGIN_H
#define LOGIN_H

#include <QMainWindow>
#include <QtWidgets>
#include <QGridLayout>
#include <iostream>

using namespace std;

class LogIn : public QDialog
{
    Q_OBJECT
public:
    explicit LogIn(QWidget *parent = 0);

private:
    QDialog* loginDia;
    QLineEdit* port;
    QLineEdit* userName;
    QLabel* portLabel;
    QLabel* userNameLabel;
    QPushButton* connect;

signals:

public slots:
    void on_connect_clicked();
};

#endif // LOGIN_H
