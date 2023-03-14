#include "game_1.h"
#include "ui_game_1.h"

int Bubble::count=0;    //初始化

Game_1::Game_1(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Game_1)
{
    ui->setupUi(this);
}

Game_1::~Game_1()
{
    delete ui;
}
void Game_1::mousePressEvent(QMouseEvent *event)    //点击时自动调用
{
    QPoint Pos=event->pos();  //用坐标形式显示鼠标点击的位置（即泡泡产生的位置）
    qDebug()<<"泡泡产生的位置是"<<Pos;

    QTime time;
    time=QTime::currentTime();
    qsrand(time.msec()+time.second()*1000);
    int r=20+qrand()%20;    //随机的半径
    int R=qrand()%255;      //随机的R通道值
    int G=qrand()%255;   //RGB颜色通道，通过改变数值调整颜色[0,255]
    int B=qrand()%255;      //随机的B通道值
    int v=2000+qrand()%3000;   //获得泡泡随机速度

    qDebug()<<"泡泡颜色（RGB值）为：("<<R<<","<<G<<","<<B<<")"<<endl;
    qDebug()<<"泡泡大小(半径）为："<<r<<endl;

    if(Bubble::getCount()<100)    //如果泡泡的个数没有超过100
    {
        qDebug()<<"当前泡泡数量："<<Bubble::getCount();
        Bubble * bubble1=new Bubble(r,Pos.x(),Pos.y(),v,R,G,B);    //动态申请一个泡泡类对象
        bubble1->move(this->mapToGlobal(Pos));    //将泡泡直接移动到鼠标在页面点击的位置
        bubble1->setColor(QColor(R,G,B));   //设置颜色  RGB规则
        bubble1->own_show();   //展示泡泡
        P.push_back(bubble1);   //将泡泡对象压入vector
        this->ui->lineEdit->setText("当前泡泡数量为:"+QString::number(Bubble::getCount()));   //显示泡泡的个数

        //将泡泡的信息写入文件
        QFile file("C://Users//fuqilingbuxiu//Desktop//课设//泡泡信息N.txt");
        if(! file.open(QIODevice::Append|QIODevice::Text))  //append追加，不会覆盖之前的文件
        {
            qDebug()<<"打开失败";
        }
        QTextStream out(&file);//写入信息
        out<<bubble1->getPos()<<endl;
        out<<bubble1->getColor()<<endl;
        out<<bubble1->getRadius()<<endl;
        out<<endl;
        file.close();
    }
    else
    {
        qDebug()<<"泡泡数量达到阈值";
    }
}
void Game_1::paintEvent(QPaintEvent *event)
{
    //背景图设置
    //paintEvent事件函数在窗体构建和每次刷新时（update)自动调用
    //bcg为游戏类内的私有数据成员 用于控制背景图片的切换

    QPainter p(this);
    if(this->bcg==0)
    {
        p.drawPixmap(0,0,width(),height(),QPixmap(":/images/d.jpg"));    //绘制背景图片   CSDN
        p.end();
        this->bcg+=1;
    }
    else if(this->bcg==1)
    {
        p.drawPixmap(0,0,width(),height(),QPixmap(":/images/snow.jpg"));
        p.end();
        this->bcg+=1;
    }
    else if(this->bcg==2)
    {
        p.drawPixmap(0,0,width(),height(),QPixmap(":/images/mount.jpg"));
        p.end();
        this->bcg=3;
    }
    else if(this->bcg==3)
    {
        p.drawPixmap(0,0,width(),height(),QPixmap(":/images/snow.jpg"));
        p.end();
        this->bcg=0;
    }
}

void Game_1::on_btn_update_clicked()
{
    this->update();   //因为paintEvent函数会在页面刷新时自动调用
}

void Game_1::on_clear_btn_clicked()
{
    qDebug()<<"请空前vector大小:"<<P.size();
    qDebug()<<"清空前泡泡数目："<<Bubble::getCount();

    for(int i=0;i<P.size();++i)   //P.size（）返回vector的大小
    {
        delete P[i];   //只清空内存 在vector中仍然存在  需要对vector进行clear
    }

    P.clear();   //清空vector
    qDebug()<<"请空后vector大小:"<<P.size();
    qDebug()<<"清空后泡泡数目："<<Bubble::getCount();
}
