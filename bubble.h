#ifndef BUBBLE_H
#define BUBBLE_H

//泡泡的具体绘制实现


#include <QWidget>
#include<QPropertyAnimation>    //属性动画 泡泡漂浮
#include<QPainter>   //绘图工具
#include<QDebug>   //调试信息输出打印
#include<QPainterPath>   //绘图路径（笔画）   生成圆形泡泡
#include<QTime>    //获得时间   用于获得随机数
#include<QMouseEvent>    //鼠标点击事件
namespace Ui {
class Bubble;
}

class Bubble : public QWidget
{
    Q_OBJECT

public:
    //radius
    explicit Bubble(int r,int x1,int y1,int newV,int newR,int newG,int newB,QWidget *parent = nullptr);    //参数分别为半径、横纵坐标、速度大小
    ~Bubble();
    void setColor(QColor color);    //用于设置泡泡线条的颜色
    void paintEvent(QPaintEvent *event);   //绘图事件 用于绘制泡泡
    void own_show();   //自己写的展示函数
    static int getCount();  //操作静态成员count  返回泡泡的个数

    QString getColor();   //返回颜色信息
    QString getRadius();  //返回半径信息
    QString getPos();     //返回坐标位置信息


private:
    Ui::Bubble *ui;
    int exc_x;
    QPropertyAnimation *bubbleAnimation;    //泡泡漂浮的动画 向右上方漂浮的动画
    static int count;   //静态数据成员   在构造和析构时更新  在类外初始化
    int x;  //泡泡横坐标  点击的位置
    int y;  //泡泡纵坐标  点击的位置
    int R;
    int G;
    int B;
    int radius;  //泡泡半径  随机
    int v;    //泡泡的漂浮速度（也就是动画持续的时间）  周期  生存期  随机
    QColor bubbleColor;   //泡泡的颜色

};

#endif // BUBBLE_H
