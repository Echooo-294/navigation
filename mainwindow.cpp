#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPainter>
#include <bits/stdc++.h>
#include <QMouseEvent>
//#include <QDebug>
#include <QColor>
#include "Graph.h"
#include "mythread.h"
MyThread mythread;//线程
const int pointnum=10000;//点数
bool vispath1[50005];//最短路占用边标记
bool vispath2[50005];//最近点占用边标记
bool vispoint1[10005];//最短路占用点标记
bool vispoint2[10005];//最近点占用点标记
QGraphicsLineItem *litem[50005];//边图元
QGraphicsEllipseItem *ellipseitem[50005];//点图元
Graph Gp(pointnum);//构造图
MyGraphicsView *graphicsView;//视图指针
std::vector<int> shortestpath;//最短路存储
std::vector<int> nearpoint;//最近点存储

//主窗口构造函数
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);//ui绑定
    m_scene=new QGraphicsScene;//场景创建
    graphicsView=new MyGraphicsView(this);//视图创建绑定主窗口
    graphicsView->resize(680,680);//视图大小设定
    graphicsView->setScene(m_scene);//场景塞进视图
    graphicsView->setSceneRect(0,0,680,680);//场景大小设定
    srand(time(0));
    Gp.StartRandFlow();//随机边流量线程启动
    auto edgenum=Gp.GetEdgeNums();//获取边数
    //初始化边图元并塞入场景
    for(int i=0;i<(int)edgenum;i++)
    {
        litem[i]=new QGraphicsLineItem;
        QGraphicsLineItem *item=litem[i];
        item->setPos(0,0);
        //除50适应实际大小
        item->setLine(Gp.P[Gp.E[i].P1].x/50,Gp.P[Gp.E[i].P1].y/50,Gp.P[Gp.E[i].P2].x/50,Gp.P[Gp.E[i].P2].y/50);
        m_scene->addItem(item);//加入边图元
    }
    //刷新边流量
    updatepath();
    //初始化点塞入场景
    for(int i=1;i<=pointnum;i++)
    {
        ellipseitem[i]=new QGraphicsEllipseItem;
        QGraphicsEllipseItem *item=ellipseitem[i];
        item->setPos(0,0);
        item->setPen(QPen(Qt::black));
        item->setBrush(Qt::black);
        item->setRect(QRect(Gp.P[i].x/50,Gp.P[i].y/50,1,1));
        m_scene->addItem(item);
    }
    //不同流量比例提示颜色
    ui->toolButton_2->setStyleSheet("background-color: rgb(60,179,113)");
    ui->toolButton_3->setStyleSheet("background-color: rgb(255,255,0)");
    ui->toolButton_4->setStyleSheet("background-color: rgb(165,42,42)");
    ui->toolButton_5->setStyleSheet("background-color: rgb(139,0,0)");
    ui->toolButton->setStyleSheet("background-color: rgb(128,0,0)");
    //定时刷新边显示线程启动
    mythread.start();
}
//获取最近100个点
void MainWindow::setnearpoint(double x,double y)
{
    //将之前存储的置零
    for(int i=1;i<(int)nearpoint.size();i++)
    {
        for(auto [_,eg]:Gp.G[nearpoint[i]])
        {
            int num=eg,num2=eg^1;
            vispath2[num]=vispath2[num2]=0;
        }
        vispoint2[nearpoint[i]]=0;
    }
    //刷新一下刷掉之前的
    updatepath();
    updatepoint();
    Point tmp;
    tmp.x=x,tmp.y=y;
    //调用最近点函数
    nearpoint=(Gp.GetClosestPoints(tmp));
    //染色
    for(int i=1;i<(int)nearpoint.size();i++)
    {
        for(auto [_,eg]:Gp.G[nearpoint[i]])
        {
            int num=eg,num2=eg^1;//
            vispath2[num]=vispath2[num2]=1;
            litem[num]->setPen(QPen(QColor("#4169e1"),2));
            litem[num2]->setPen(QPen(QColor("#4169e1"),2));
        }
        vispoint2[nearpoint[i]]=1;
        QGraphicsEllipseItem *item=ellipseitem[nearpoint[i]];
        item->setPen(QPen(Qt::blue));
        item->setBrush(Qt::blue);
    }
    //获取点编号并展示在列表里
    QStringList strlist;
    QStandardItemModel *ItemModel =new QStandardItemModel(this);
    for(int i=1;i<(int)nearpoint.size();i++)
    {
        QString string=QString::number(nearpoint[i]);
        QStandardItem *item=new QStandardItem(string);
        ItemModel->appendRow(item);
    }
    ui->listView->setModel(ItemModel);
    return;
}
//最短路函数
void MainWindow::setshortestpath(int x,int y,int time)
{
    //将之前最短路置零
    for(int i=0;i<(int)shortestpath.size();i++)
    {
        int &num=shortestpath[i];
        int num2=num^1;
        int p1num=Gp.E[num].P1,p2num=Gp.E[num].P2;
        vispath1[num]=vispath1[num2]=0;
        vispoint1[p1num]=vispoint1[p2num]=0;
    }
    //刷掉
    updatepath();
    updatepoint();
    double totdistance,tottime;//记录距离和时间
    shortestpath=Gp.dij(x,y,&Gp,time,totdistance,tottime);//调用最短路函数
    //最短路染色
    for(int i=0;i<(int)shortestpath.size();i++)
    {
        int &num=shortestpath[i];
        int num2=num^1;
        int p1num=Gp.E[num].P1,p2num=Gp.E[num].P2;
        vispath1[num]=vispath1[num2]=1;
        vispoint1[p1num]=vispoint1[p2num]=1;
        litem[num]->setPen(QPen(QColor("#006400"),2));
        litem[num2]->setPen(QPen(QColor("#006400"),2));
        ellipseitem[p1num]->setPen(QPen(Qt::blue,2));
        ellipseitem[p1num]->setBrush(Qt::blue);
        ellipseitem[p2num]->setBrush(Qt::blue);
        ellipseitem[p2num]->setPen(QPen(Qt::blue,2));
    }
    //展示时间和距离
    QString tme="时间：";
    tme+=QString::number(tottime,'f',2);
    tme+="s";
    ui->toolButton_7->setText(tme);
    QString dis="距离：";
    dis+=QString::number(totdistance,'f',2);
    dis+="m";
    ui->toolButton_6->setText(dis);
}
//刷新边
void MainWindow::updatepath()
{
    auto edgenum=Gp.GetEdgeNums();
    //对所有边遍历
    for(int i=0;i<(int)edgenum;i++)
    {
        QGraphicsLineItem *item=litem[i];
        if(vispath1[i])
        {
            item->setPen(QPen(QColor("#006400"),2));
            continue;
        }
        else if(vispath2[i])
        {
            item->setPen(QPen(QColor("#4169e1"),2));
            continue;
        }
        //根据流量比例染色
        double fdc=1.0*Gp.E[i].flow/Gp.E[i].capacity;
        if(fdc<=0.5)item->setPen(QColor("#3CB371"));
        else if(fdc<=0.8)item->setPen(QColor("#ffff00"));
        else if(fdc<=1.0)item->setPen(QColor("#A52A2A"));
        else if(fdc<=1.5)item->setPen(QColor("#8B0000"));
        else item->setPen(QColor("#800000"));
    }
}
//刷新点
void MainWindow::updatepoint()
{
    //根据标记染色
    for(int i=1;i<=(int)pointnum;i++)
    {
        if(vispoint1[i]||vispoint2[i])continue;
        QGraphicsEllipseItem *item=ellipseitem[i];
        item->setPen(QPen(Qt::black));
        item->setBrush(Qt::black);
    }
}
//析构ui界面
MainWindow::~MainWindow()
{
    delete ui;
}

//最近100个点按钮
void MainWindow::on_nearpt_clicked()
{
    double x=ui->inputx->text().toDouble();
    double y=ui->inputy->text().toDouble();
    if(x<0||x>32767||y<0||y>32767)return;//
    MainWindow::setnearpoint(x,y);
}
//最短路按钮
void MainWindow::on_shortpt_clicked()
{
    int x=ui->inputx_2->text().toInt();
    int y=ui->inputy_2->text().toInt();
    if(x>10000||x<1||y>10000||y<1)return;//
    MainWindow::setshortestpath(x,y,0);
}
//时间最短路按钮
void MainWindow::on_pushButton_clicked()
{
    int x=ui->inputx_2->text().toInt();
    int y=ui->inputy_2->text().toInt();
    if(x>10000||x<1||y>10000||y<1)return;//
    MainWindow::setshortestpath(x,y,1);
}
//右键双击函数
void MainWindow::mouseDoubleClickEvent(QMouseEvent *event)
{
    if(event->button()!=Qt::RightButton)return;
    QPointF nowAnchor=graphicsView->mapToScene(event->pos());//获取的是视图的坐标要下沉到场景去获取真实坐标
    double x=nowAnchor.x()*50,y=nowAnchor.y()*50;
    if(x<0||x>32767||y<0||y>32767)return;//边界判断
    else
    {
        ui->inputx->setText(QString::number(x));
        ui->inputy->setText(QString::number(y));
        setnearpoint(x,y);
    }
}
//刷新边函数同上（由于线程隔开类的调用）
void MyThread::wode()
{
    auto edgenum=Gp.GetEdgeNums();
    for(int i=0;i<(int)edgenum;i++)
    {
        QGraphicsLineItem *item=litem[i];
        if(vispath1[i])
        {
            item->setPen(QPen(QColor("#006400"),2));
            continue;
        }
        else if(vispath2[i])
        {
            item->setPen(QPen(QColor("#4169e1"),2));
            continue;
        }
        double fdc=1.0*Gp.E[i].flow/Gp.E[i].capacity;
        if(fdc<=0.5)item->setPen(QColor("#3CB371"));
        else if(fdc<=0.8)item->setPen(QColor("#ffff00"));
        else if(fdc<=1.0)item->setPen(QColor("#A52A2A"));
        else if(fdc<=1.5)item->setPen(QColor("#8B0000"));
        else item->setPen(QColor("#800000"));
    }
}