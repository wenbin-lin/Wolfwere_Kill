#include "mainwindow.h"
#include "gameinfo.h"
#include "Client.h"
#include "login.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.setStyleSheet("QMainWindow{border-image: url(:/image/background.jpg)}");
    w.show();

    //string a = "下卓凡";
    //cout<<a<<endl;
    return a.exec();
}
