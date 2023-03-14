#ifndef MOUSE_1_H
#define MOUSE_1_H

#include <QWidget>
#include<QMouseEvent>  //QMouseEvent类包含了用于描述鼠标事件的参数。
#include<QDebug>

namespace Ui {
class mouse_1;
}

class mouse_1 : public QWidget
{
    Q_OBJECT

public:
    explicit mouse_1(QWidget *parent = nullptr);
    ~mouse_1();
    void mousePressEvent(QMouseEvent *event);


private:
    Ui::mouse_1 *ui;
};

#endif // MOUSE_1_H
