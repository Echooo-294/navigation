#include "mainwindow.h"
#include <iostream>
#include <QApplication>
//#include <qdebug.h>


int main(int argc, char *argv[])
{
    //创建程序
    QApplication a(argc, argv);
    //创建主窗口
    MainWindow w;
    //主窗口大小
    w.resize(950,800);
    //主窗口展示
    w.show();
    return a.exec();
}
