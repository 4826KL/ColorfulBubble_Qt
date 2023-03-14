#include "select1.h"
#include "ui_select1.h"

select1::select1(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::select1)
{
    ui->setupUi(this);
}

select1::~select1()
{
    delete ui;
}

void select1::paintEvent(QPaintEvent *event)
{
    //背景图设置
    QPainter p(this);
    //pixmap
    p.drawPixmap(0,0,width(),height(),QPixmap(":/images/l.jpg"));    //查到的   采用资源文件
    p.end();
}

void select1::on_pushButton_clicked()
{
    mouse.setWindowIcon(QIcon(":/images/bubble.png"));
    mouse.setWindowTitle("鼠标事件");
    mouse.show();
}

void select1::on_btn_one_clicked()
{
    game1.setWindowIcon(QIcon(":/images/bubble.png"));
    game1.setWindowTitle("彩色泡泡机");
    //game1.showMaximized();     //最大化展开
    game1.show();
}

void select1::on_btn_info_clicked()
{
    information.setWindowIcon(QIcon(":/images/bubble.png"));
    information.setWindowTitle("泡泡信息");
    information.setFixedSize(900,800);
    information.show();
}
