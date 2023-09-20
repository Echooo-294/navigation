#ifndef MYTHREAD_H
#define MYTHREAD_H
#include <QThread>
#include <QTimeLine>
#include <QTime>
#include <QTimer>
//线程子类，用于定时刷新
class MyThread : public QThread
{
    Q_OBJECT
public:
    //构造函数
    MyThread(){}
    //执行函数，用定时器启动刷新
    void run() override
    {
        timer=new QTimer();
        //定时间隔10000ms
        timer->setInterval(10000);
        //绑定定时器和刷新函数
        connect(timer,&QTimer::timeout,this,&MyThread::wode);
        //启动定时器
        timer->start();
        this->exec();
    }
    //析构函数
    ~ MyThread() override{
        this->wait();
    }
    //定时器
    QTimer *timer;
public slots:
    //刷新函数,实现在mywindow.cpp中
    void wode();
};

#endif // MYTHREAD_H
