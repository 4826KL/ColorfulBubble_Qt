#ifndef RETURN_H
#define RETURN_H

#include <QDialog>

namespace Ui {
class return;
}

class return : public QDialog
{
    Q_OBJECT

public:
    explicit return(QWidget *parent = nullptr);
    ~return();

private:
    Ui::return *ui;
};

#endif // RETURN_H
