#ifndef MUSIC_H
#define MUSIC_H
#include<QMediaPlayer>
#include <QWidget>
//废弃
namespace Ui {
class music;
}

class music : public QWidget
{
    Q_OBJECT

public:
    explicit music(QWidget *parent = nullptr);
    ~music();

private:
    QMediaPlayer * player = new QMediaPlayer;
    Ui::music *ui;
};

#endif // MUSIC_H
