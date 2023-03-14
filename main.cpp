#include "login.h"
#include<QIcon>

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Login w;    //创建登录页面对象
    w.setWindowTitle("登录");   //设置页面标题
    w.setWindowIcon(QIcon(":/images/bubble.png"));  //更改页面的图标
    w.show();   //展示页面
    return a.exec();   //防止页面一闪而过
}
