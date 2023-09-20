#ifndef MYGRAPHICSVIEW_H
#define MYGRAPHICSVIEW_H
//qgraphicsview继承子类重写（用于构造场景）
#include <QObject>
#include <QGraphicsView>

QT_BEGIN_NAMESPACE
//滚轮事件，用于缩放
class QWheelEvent;
QT_END_NAMESPACE

class MyGraphicsView : public QGraphicsView
{
    Q_OBJECT
public:
    //构造析构函数
    explicit MyGraphicsView(QWidget *parent = 0);
    ~MyGraphicsView();
    //鼠标是否按下
    bool isMousePressed=0;
    //视图中心点，位置点
    QPointF centerAnchor,posAnchor;
protected:
    //滚轮缩放
    void wheelEvent(QWheelEvent *event) Q_DECL_OVERRIDE;
    //上界
    void magnify();
    //下界
    void shrink();
    //放缩函数
    void scaling(qreal scaleFactor);
    //鼠标按下
    void mousePressEvent(QMouseEvent *event)override;
    //鼠标移动
    void mouseMoveEvent(QMouseEvent *event)override;
    //鼠标释放
    void mouseReleaseEvent(QMouseEvent *event)override;
private:
    //记录放缩累计，用于限制上下界
    int m_scalingOffset;
};

#endif // MYGRAPHICSVIEW_H
