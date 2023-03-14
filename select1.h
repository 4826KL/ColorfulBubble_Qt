#ifndef SELECT1_H
#define SELECT1_H

#include <QWidget>
#include<QPainter>
#include"mouse_1.h"   //鼠标练习页面头文件
#include"game_1.h"    //游戏区页面头文件
#include"info.h"      //泡泡信息页面头文件
namespace Ui {
class select1;
}

class select1 : public QWidget
{
    Q_OBJECT

public:
    explicit select1(QWidget *parent = nullptr);
    ~select1();
    void paintEvent(QPaintEvent *event);    //绘图事件  用于绘制背景图片

private slots:    //各个按钮点击所对应的槽函数
    void on_pushButton_clicked();    //跳转到鼠标练习页面
    void on_btn_one_clicked();       //跳转到泡泡机游戏页面
    void on_btn_info_clicked();      //跳转到泡泡的信息显示页面

private:
    Ui::select1 *ui;
    mouse_1 mouse;     //鼠标练习页面
    Game_1 game1;      //泡泡机游戏页面
    info information;  //泡泡信息页面
};

#endif // SELECT1_H
