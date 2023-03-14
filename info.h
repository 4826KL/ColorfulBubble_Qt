#ifndef INFO_H
#define INFO_H

#include <QWidget>
#include<QPaintEvent>
#include<QPainter>
#include<QMessageBox>
#include<QDebug>
namespace Ui {
class info;
}

class info : public QWidget
{
    Q_OBJECT

public:
    explicit info(QWidget *parent = nullptr);
    ~info();
    void paintEvent(QPaintEvent *event);   //设置背景图

private:
    Ui::info *ui;
};

#endif // INFO_H
