#include "bubble.h"
#include "ui_bubble.h"

Bubble::Bubble(int r,int x1,int y1,int newV,int newR,int newG,int newB,QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Bubble),
    R(newR),
    G(newG),
    B(newB),
    v(newV),
    x(x1),
    y(y1),
    radius(r)
{
    ui->setupUi(this);   //初始化UI
    count++;
    this->setFixedSize(QSize(80,80));   //设置泡泡所在窗口的最大值，从而限定泡泡的大小


    //设置窗口标志（属性）
    this->setWindowFlags(Qt::FramelessWindowHint | Qt::Tool);  //去除泡泡所在窗口的标题栏
    this->setAttribute(Qt::WA_TranslucentBackground);  //使泡泡所在窗口(已去除标题栏）背景透明化，只出现泡泡的图形

    this->bubbleAnimation=new QPropertyAnimation(this,"pos");   //初始化泡泡动画    参数分别为动画作用的对象：泡泡  涉及更改的属性：位置  position
//    this->bubbleAnimation2=new QPropertyAnimation(this,"pos");  //初始化泡泡动画    参数分别为动画作用的对象：泡泡  涉及更改的属性：位置  position
//    this->bubbleAnimation3=new QPropertyAnimation(this,"pos");  //初始化泡泡动画    参数分别为动画作用的对象：泡泡  涉及更改的属性：位置  position
//    this->bubbleAnimation4=new QPropertyAnimation(this,"pos");  //初始化泡泡动画    参数分别为动画作用的对象：泡泡  涉及更改的属性：位置  position

}

Bubble::~Bubble()
{
    count--;
    delete ui;
}

void Bubble::setColor(QColor color)  //改变泡泡的颜色
{
    this->bubbleColor=color;
}

void Bubble::paintEvent(QPaintEvent *event)
{

    QPainter painter(this);  //创建画笔，作用于自身
    painter.setRenderHint(QPainter::Antialiasing);    //固定语法，用于图形反走样
    painter.setPen(bubbleColor);  //设置画笔，勾勒泡泡，颜色通过随机RGB通道值产生

    QPainterPath bubblePath;  //泡泡绘制路径 QPainterPath提供容器用于绘制路径
    //ellipse椭圆
    //参数为圆心的坐标  半径的大小  圆心坐标由鼠标点击的位置决定  半径为随机产生
    bubblePath.addEllipse(QPoint(40,40),radius,radius);   //在绘制路径中生成圆形泡泡在窗口的初始位置，后期随机生成半径
    painter.drawPath(bubblePath);  //绘制泡泡路径   进行绘制

}

void Bubble::own_show()   //展示泡泡颜色，大小，漂浮速度，方向
{
    QWidget::show();      //显示泡泡
    // 产生随机
    QTime time;
    time=QTime::currentTime();   //获得当前时间用以产生随机数
    qsrand(time.msec()+time.second()*1000);
    exc_x=400+qrand()%1000;
    v=40000+qrand()%100000;


    //右上方漂浮

//    this->bubbleAnimation->setStartValue(QPoint(x,y));   //设置动画的开始位置   泡泡产生的位置即鼠标点击的位置  两点确定一线
//    this->bubbleAnimation->setEndValue(QPoint(x+exc_x,30));   //设置结束位置    随机的偏移量
//    qDebug()<<"右上";

    //采用帧动画进行设置  anim->setKeyValueAt(%,pos)   参数依次为百分比位置  坐标
    qDebug()<<"动画"<<Bubble::getCount();

    if(Bubble::getCount()%2==0)
    {
        qDebug()<<"偶数";
        if(x<850)    //左侧
        {
            //左侧产生的泡泡动画
            qDebug()<<"左侧";
            this->bubbleAnimation->setDuration(v);        //用随机速度设置动画时长（同随机）  设置动画的时长
            this->bubbleAnimation->setKeyValueAt(0,QPoint(x,y));
            this->bubbleAnimation->setKeyValueAt(0.05,QPoint(600,30));
            this->bubbleAnimation->setKeyValueAt(0.15,QPoint(1800,500));
            this->bubbleAnimation->setKeyValueAt(0.2,QPoint(900,900));

            this->bubbleAnimation->setKeyValueAt(0.25,QPoint(0,300));
            this->bubbleAnimation->setKeyValueAt(0.3,QPoint(800,30));
            this->bubbleAnimation->setKeyValueAt(0.35,QPoint(1800,300));
            this->bubbleAnimation->setKeyValueAt(0.4,QPoint(900,900));

            this->bubbleAnimation->setKeyValueAt(0.45,QPoint(0,400));
            this->bubbleAnimation->setKeyValueAt(0.5,QPoint(800,30));
            this->bubbleAnimation->setKeyValueAt(0.55,QPoint(1800,450));
            this->bubbleAnimation->setKeyValueAt(0.6,QPoint(900,900));

            this->bubbleAnimation->setKeyValueAt(0.65,QPoint(0,300));
            this->bubbleAnimation->setKeyValueAt(0.7,QPoint(800,30));
            this->bubbleAnimation->setKeyValueAt(0.75,QPoint(1800,450));
            this->bubbleAnimation->setKeyValueAt(0.8,QPoint(900,900));

            this->bubbleAnimation->setKeyValueAt(0.85,QPoint(0,300));
            this->bubbleAnimation->setKeyValueAt(0.9,QPoint(800,30));
            this->bubbleAnimation->setKeyValueAt(0.95,QPoint(1800,450));
            this->bubbleAnimation->setKeyValueAt(1,QPoint(-200,-500));

            this->bubbleAnimation->start();   //动画开始
        }
        else if(x==850)
        {
            qDebug()<<"中间";
            this->bubbleAnimation->setDuration(v);        //用随机速度设置动画时长（同随机）  设置动画的时长
            this->bubbleAnimation->setKeyValueAt(0,QPoint(x,y));
            this->bubbleAnimation->setKeyValueAt(0.25,QPoint(800,30));
            this->bubbleAnimation->setKeyValueAt(0.75,QPoint(800,900));
            this->bubbleAnimation->setKeyValueAt(0.75,QPoint(800,-900));
            this->bubbleAnimation->start();
        }
        else
        {   //左侧产生的泡泡动画
            qDebug()<<"右侧";
            this->bubbleAnimation->setDuration(v);        //用随机速度设置动画时长（同随机）  设置动画的时长
            this->bubbleAnimation->setKeyValueAt(0,QPoint(x,y));
            this->bubbleAnimation->setKeyValueAt(0.05,QPoint(800,30));
            this->bubbleAnimation->setKeyValueAt(0.15,QPoint(0,450));
            this->bubbleAnimation->setKeyValueAt(0.2,QPoint(900,900));

            this->bubbleAnimation->setKeyValueAt(0.25,QPoint(1800,300));
            this->bubbleAnimation->setKeyValueAt(0.3,QPoint(800,30));
            this->bubbleAnimation->setKeyValueAt(0.35,QPoint(0,450));
            this->bubbleAnimation->setKeyValueAt(0.4,QPoint(900,900));

            this->bubbleAnimation->setKeyValueAt(0.45,QPoint(1800,300));
            this->bubbleAnimation->setKeyValueAt(0.5,QPoint(800,30));
            this->bubbleAnimation->setKeyValueAt(0.55,QPoint(0,450));
            this->bubbleAnimation->setKeyValueAt(0.6,QPoint(900,900));

            this->bubbleAnimation->setKeyValueAt(0.65,QPoint(1800,300));
            this->bubbleAnimation->setKeyValueAt(0.7,QPoint(800,30));
            this->bubbleAnimation->setKeyValueAt(0.75,QPoint(0,450));
            this->bubbleAnimation->setKeyValueAt(0.8,QPoint(900,900));

            this->bubbleAnimation->setKeyValueAt(0.85,QPoint(1800,300));
            this->bubbleAnimation->setKeyValueAt(0.9,QPoint(800,30));
            this->bubbleAnimation->setKeyValueAt(0.95,QPoint(0,450));
            this->bubbleAnimation->setKeyValueAt(1,QPoint(2000,-500));

            this->bubbleAnimation->start();   //动画开始

        }
    }
    else
    {
        qDebug()<<"奇数";
        if(x<850)    //左侧
        {
            //左侧产生的泡泡动画
            qDebug()<<"左侧";
            this->bubbleAnimation->setDuration(v);        //用随机速度设置动画时长（同随机）  设置动画的时长
            this->bubbleAnimation->setKeyValueAt(0,QPoint(x,y));
            this->bubbleAnimation->setKeyValueAt(0.05,QPoint(1000,30));
            this->bubbleAnimation->setKeyValueAt(0.15,QPoint(1800,600));
            this->bubbleAnimation->setKeyValueAt(0.2,QPoint(700,900));

            this->bubbleAnimation->setKeyValueAt(0.25,QPoint(0,500));
            this->bubbleAnimation->setKeyValueAt(0.3,QPoint(600,30));
            this->bubbleAnimation->setKeyValueAt(0.35,QPoint(1800,700));
            this->bubbleAnimation->setKeyValueAt(0.4,QPoint(1000,900));

            this->bubbleAnimation->setKeyValueAt(0.45,QPoint(0,800));
            this->bubbleAnimation->setKeyValueAt(0.5,QPoint(800,30));
            this->bubbleAnimation->setKeyValueAt(0.55,QPoint(1800,300));
            this->bubbleAnimation->setKeyValueAt(0.6,QPoint(600,900));

            this->bubbleAnimation->setKeyValueAt(0.65,QPoint(0,500));
            this->bubbleAnimation->setKeyValueAt(0.7,QPoint(800,30));
            this->bubbleAnimation->setKeyValueAt(0.75,QPoint(1800,450));
            this->bubbleAnimation->setKeyValueAt(0.8,QPoint(900,900));

            this->bubbleAnimation->setKeyValueAt(0.85,QPoint(0,300));
            this->bubbleAnimation->setKeyValueAt(0.9,QPoint(800,30));
            this->bubbleAnimation->setKeyValueAt(0.95,QPoint(1800,450));
            this->bubbleAnimation->setKeyValueAt(1,QPoint(800,1200));    //下方消失

            this->bubbleAnimation->start();   //动画开始
        }
        else if(x==850)
        {
            qDebug()<<"中间";
            this->bubbleAnimation->setDuration(v);        //用随机速度设置动画时长（同随机）  设置动画的时长
            this->bubbleAnimation->setKeyValueAt(0,QPoint(x,y));
            this->bubbleAnimation->setKeyValueAt(0.25,QPoint(800,30));
            this->bubbleAnimation->setKeyValueAt(0.75,QPoint(800,900));
            this->bubbleAnimation->setKeyValueAt(0.75,QPoint(800,-900));
            this->bubbleAnimation->start();
        }
        else
        {   //左侧产生的泡泡动画
            qDebug()<<"右侧";
            this->bubbleAnimation->setDuration(v);        //用随机速度设置动画时长（同随机）  设置动画的时长
            this->bubbleAnimation->setKeyValueAt(0,QPoint(x,y));
            this->bubbleAnimation->setKeyValueAt(0.05,QPoint(800,30));
            this->bubbleAnimation->setKeyValueAt(0.15,QPoint(0,450));
            this->bubbleAnimation->setKeyValueAt(0.2,QPoint(900,900));

            this->bubbleAnimation->setKeyValueAt(0.25,QPoint(1800,300));
            this->bubbleAnimation->setKeyValueAt(0.3,QPoint(800,30));
            this->bubbleAnimation->setKeyValueAt(0.35,QPoint(0,450));
            this->bubbleAnimation->setKeyValueAt(0.4,QPoint(900,900));

            this->bubbleAnimation->setKeyValueAt(0.45,QPoint(1800,300));
            this->bubbleAnimation->setKeyValueAt(0.5,QPoint(800,30));
            this->bubbleAnimation->setKeyValueAt(0.55,QPoint(0,450));
            this->bubbleAnimation->setKeyValueAt(0.6,QPoint(900,900));

            this->bubbleAnimation->setKeyValueAt(0.65,QPoint(1800,300));
            this->bubbleAnimation->setKeyValueAt(0.7,QPoint(800,30));
            this->bubbleAnimation->setKeyValueAt(0.75,QPoint(0,450));
            this->bubbleAnimation->setKeyValueAt(0.8,QPoint(900,900));

            this->bubbleAnimation->setKeyValueAt(0.85,QPoint(1800,300));
            this->bubbleAnimation->setKeyValueAt(0.9,QPoint(800,30));
            this->bubbleAnimation->setKeyValueAt(0.95,QPoint(0,450));
            this->bubbleAnimation->setKeyValueAt(1,QPoint(2000,-500));

            this->bubbleAnimation->start();   //动画开始

        }
    }

}

int Bubble::getCount()
{
    return count;
}



QString Bubble::getColor()
{
    return "颜色：RGB("+QString::number(R)+","+QString::number(G)+","+QString::number(B)+")";
}

QString Bubble::getRadius()
{
    return "半径为："+QString::number(radius);
}

QString Bubble::getPos()
{
    return "坐标为:("+QString::number(x)+","+QString::number(y)+")";
}

