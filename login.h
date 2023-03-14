#ifndef LOGIN_H
#define LOGIN_H

#include <QWidget>
#include<QPainter>   //绘图工具   画笔 画刷
#include<QString>    //字符串
#include<QDebug>     //调试，输出打印
#include<QMessageBox>   //确认是否退出
#include"select1.h"   //功能选择页面
#include"select.h"
#include<QMediaPlayer>  //用于播放bgm

QT_BEGIN_NAMESPACE
namespace Ui { class Login; }
QT_END_NAMESPACE

class Login : public QWidget
{
    Q_OBJECT

public:
    Login(QWidget *parent = nullptr);
    ~Login();
    void paintEvent(QPaintEvent *event);   //背景图片的绘制  drawpixmap
private slots:
    void on_Login_button_clicked();

    void on_Login_return_Button_2_clicked();

private:
    Ui::Login *ui;
    select1 s1;    //功能选择页面对象
    select s;

};
#endif // LOGIN_H
