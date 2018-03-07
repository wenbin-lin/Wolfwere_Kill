#include "login.h"

LogIn::LogIn(QWidget *parent) : QDialog(parent)
{

    loginDia = new QDialog;
    loginDia->setWindowTitle(tr("Login"));
    loginDia->setFixedSize(400,300);
    port = new QLineEdit(loginDia);
    userName = new QLineEdit(loginDia);
    portLabel = new QLabel(tr("地址"),loginDia);
    userNameLabel = new QLabel(tr("用户名"),loginDia);
    connect = new QPushButton(tr("连接"),loginDia);
    QGridLayout* layout = new QGridLayout(loginDia);
    layout->addWidget(port,0,0,1,4);
    layout->addWidget(portLabel,0,4,1,1);
    layout->addWidget(userName,1,0,1,5);
    layout->addWidget(userName,1,4,1,1);
    layout->addWidget(connect,2,2,1,1);
    loginDia->setLayout(layout);
    loginDia->show();
}

void LogIn::on_connect_clicked()
{
    cout<<"clicked"<<endl;
}
