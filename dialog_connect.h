#ifndef DIALOG_CONNECT_H
#define DIALOG_CONNECT_H

#include <QDialog>


namespace Ui {
class Dialog_connect;
}

class Dialog_connect : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog_connect(QWidget *parent = 0);
    ~Dialog_connect();

private slots:
    void on_pushButton_open_clicked();

    void on_pushButton_closeall_clicked();


private:
    Ui::Dialog_connect *ui;
    void init();
};

#endif // DIALOG_CONNECT_H
