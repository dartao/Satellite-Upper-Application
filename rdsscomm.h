#ifndef RDSSCOMM_H
#define RDSSCOMM_H

#include <QWidget>

namespace Ui {
class RdssComm;
}

class RdssComm : public QWidget
{
    Q_OBJECT

public:
    explicit RdssComm(QWidget *parent = nullptr);
    ~RdssComm();

private:
    Ui::RdssComm *ui;
};

#endif // RDSSCOMM_H
