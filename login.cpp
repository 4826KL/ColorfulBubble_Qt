#include "login.h"
#include "ui_login.h"


Login::Login(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Login)
{
    ui->setupUi(this);
    this->ui->zh_checkBox->setChecked(true);     //默认勾选了记住账号
     this->ui->key_checkBox->setChecked(true);     //默认勾选了记住密码
}

Login::~Login()
{
    delete ui;
}
void Login::paintEvent(QPaintEvent *event)  //重载基类中的绘画事件
{

    //背景图设置
    QPainter p(this);
    //pixmap
    p.drawPixmap(0,0,width(),height(),QPixmap(":/images/c.jpg")); //绘制图片
    p.end();

}

void Login::on_Login_button_clicked()
{
    QString id="mxdxcd";
    QString key="4826";

    QString input_ID=this->ui->login_zh_Edit->text();    //获得单行编辑框的文本值
    QString input_KEY=this->ui->login_key_Edit->text();
    if(input_ID==id&&input_KEY==key)
    {
        qDebug()<<"登录成功" <<endl;
        //获得当前时间
        QDateTime current_date_time =QDateTime::currentDateTime();
        QString time=current_date_time.toString("yyyy.MM.dd hh:mm:ss.zzz ddd")+"登录成功";


        //将登陆时间写入配置文件
        QFile file("C://Users//fuqilingbuxiu//Desktop//课设//泡泡信息N.txt");
        if(! file.open(QIODevice::Append|QIODevice::Text))  //append追加，不会覆盖之前的文件
        {
            qDebug()<<"打开失败";
        }
        QTextStream out(&file);//写入
        out<<time<<endl;
        out<<endl;
        file.close();


        //BGM的播放设置
        QMediaPlayer * player = new QMediaPlayer;  //创建文件对象，播放bgm
        //player->setMedia(QUrl::fromLocalFile("C:\\Users\\fuqilingbuxiu\\Desktop\\music\\y.mp3")); //绝对路径设置媒体文件
        player->setMedia(QUrl::fromLocalFile("./y.mp3")); //相对路径设置媒体文件   .表示程序当前运行目录  ..表示上一级目录
        player->setVolume(30);  //设置音量
        player->play();   //播放


        this->hide();


        s1.setWindowTitle("功能选择");
        s1.setFixedSize(800,600);   //设置固定大小
        s1.setWindowIcon(QIcon(":/images/bubble.png"));
        s1.show();
    }


    else{

        s.show();
    }
}

void Login::on_Login_return_Button_2_clicked()
{
    int res = QMessageBox::question(this,"提示","是否要关闭窗口？");  //弹出对话框进行确认是否退出
    if (res == QMessageBox::Yes){
        this->close();
    }
    else {
        this->show();
    }
}
