#include "mygraphicsview.h"
#include <QWheelEvent>
#include <QPoint>
//#include <QDebug>
//构造函数
MyGraphicsView::MyGraphicsView(QWidget *parent)
    : QGraphicsView(parent)
{
    m_scalingOffset=1;
}
//析构函数
MyGraphicsView::~MyGraphicsView()
{

}
//上界判断
void MyGraphicsView::magnify()
{
    if(m_scalingOffset>=10)
    {m_scalingOffset=10; return;}

    m_scalingOffset+=1;
    scaling(1.25);
}
//下界判断
void MyGraphicsView::shrink()
{
    if(m_scalingOffset<=1)
    {m_scalingOffset=1; return;}

    m_scalingOffset-=1;
    scaling(0.8);
}
//根据传入的放缩比例放缩
void MyGraphicsView::scaling(qreal scaleFactor)
{
    scale(scaleFactor,scaleFactor);
}
//鼠标滚轮启动上下界判断然后放缩
void MyGraphicsView::wheelEvent(QWheelEvent *event)
{
    QPoint sroll=event->angleDelta();
    sroll.y()>0?magnify():shrink();

}
//鼠标点击函数，获取初始坐标
void MyGraphicsView::mousePressEvent(QMouseEvent *event)
{
    if(event->button()!=Qt::LeftButton)return;
    QGraphicsView::mousePressEvent(event);
    if(this->scene() == nullptr)
    {
        return;
    }
    centerAnchor = mapToScene(event->pos()) - event->pos() + QPointF(width() / 2, height() / 2);
    posAnchor = event->pos();
    isMousePressed = true;
}
//鼠标移动函数，用于放缩
void MyGraphicsView::mouseMoveEvent(QMouseEvent *event)
{
    QGraphicsView::mouseMoveEvent(event);
    QPointF offsetPos = event->pos() - posAnchor;
    if(isMousePressed){
        setTransformationAnchor(QGraphicsView::AnchorUnderMouse);
        centerOn(centerAnchor - offsetPos);
    }
}
//鼠标释放函数
void MyGraphicsView::mouseReleaseEvent(QMouseEvent *event)
{
    if(event->button()!=Qt::LeftButton)return;
    QGraphicsView::mouseReleaseEvent(event);
    isMousePressed = false;
}
