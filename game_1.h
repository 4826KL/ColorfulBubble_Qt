#ifndef GAME_1_H
#define GAME_1_H

#include <QWidget>
#include"bubble.h"   //泡泡的绘制实现
#include<QMessageBox>    //文件
#include<QTextStream>    //文件
#include<QThread>
#include<QVector>    //创建泡泡动态数组

namespace Ui {
class Game_1;
}

class Game_1 : public QWidget
{
    Q_OBJECT

public:
    explicit Game_1(QWidget *parent = nullptr);
    ~Game_1();
    void mousePressEvent(QMouseEvent *event);   //鼠标事件
    void paintEvent(QPaintEvent *event);   //设置背景图

private slots:
    void on_btn_update_clicked();   //更改背景图按钮对应的槽函数


    void on_clear_btn_clicked();

private:
    Ui::Game_1 *ui;
    QVector<Bubble*>P;   //动态vector  用于存储每一个泡泡
    int bcg=0;    //背景图片的控制变量
};

#endif // GAME_1_H
