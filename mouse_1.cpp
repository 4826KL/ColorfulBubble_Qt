#include "mouse_1.h"
#include "ui_mouse_1.h"

mouse_1::mouse_1(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::mouse_1)
{
    ui->setupUi(this);
}

mouse_1::~mouse_1()
{
    delete ui;
}

void mouse_1::mousePressEvent(QMouseEvent *event)
{
    //QMouseEvent *event  event是一个鼠标点击的事件
    //event->pos()  返回一个QPoint类型的对象（说白了就是一个点的位置）
    //pos()->x()   返回对应点的X坐标
   // QPoint currentPos=event->pos();
    if(event->button()==Qt::LeftButton)
    {
        qDebug()<<"按下左键"<<"("<<event->pos().x()<<","<<event->pos().y()<<")";
    }

}
