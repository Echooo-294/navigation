#ifndef MAINWINDOW_H
#define MAINWINDOW_H
//mainwindow头文件定义
#include <QMainWindow>
#include "mygraphicsview.h"
#include <QGraphicsRectItem>
#include <QGraphicsLineItem>
#include <QGraphicsEllipseItem>
#include <QStringListModel>
#include <QStandardItemModel>
#include <QModelIndex>
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE
//鼠标移动
class QMouseEvent;
class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    //构造析构函数
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    //最近100个点
    void setnearpoint(double x,double y);
    //最短路
    void setshortestpath(int x,int y,int time);
    //刷新路径
    void updatepath();
    //刷新点
    void updatepoint();
    /*double NowAmplification=1;
    double NowLeft=0,NowTop=0;
    bool m_bDrag;
    QPoint mouseStartPoint;
    QPoint windowTopLeftPoint;
    */
    //场景
    QGraphicsScene *m_scene;
protected:
    //右键双击槽函数
    void mouseDoubleClickEvent(QMouseEvent *event);
private slots:
    //最近100个点按钮
    void on_nearpt_clicked();
    //最短路按钮
    void on_shortpt_clicked();
    //时间最短路按钮
    void on_pushButton_clicked();

private:
    //ui界面
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
