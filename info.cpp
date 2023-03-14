#include "info.h"
#include "ui_info.h"
#include<QFile>
#include<QTextStream>

info::info(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::info)
{
    ui->setupUi(this);
    this->ui->info_clear->hide();
    ui->textEdit->setText("");
    QFile file2("C://Users//fuqilingbuxiu//Desktop//课设//泡泡信息N.txt");
    if(!file2.open(QIODevice::ReadOnly | QIODevice::Text))//只读
    {
        ui->textEdit->append("文件打开失败");
        return;
    }
    QTextStream readStream(&file2);

    ui->textEdit->append("文件内容:");
    while(!readStream.atEnd())	//没有读到文件末尾
    {
        ui->textEdit->append(readStream.readLine());
    }
    file2.close();
}
void info::paintEvent(QPaintEvent *event)
{
    //背景图设置
    QPainter p(this);
    //pixmap
    p.drawPixmap(0,0,width(),height(),QPixmap(":/images/j.jpg"));
    p.end();

}
info::~info()
{
    qDebug()<<"析构";
    delete ui;
}





