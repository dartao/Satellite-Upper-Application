#ifndef SATEDIST_H
#define SATEDIST_H

#include <QWidget>

namespace Ui {
class SateDist;
}

class SateDist : public QWidget
{
    Q_OBJECT

public:
    explicit SateDist(QWidget *parent = nullptr);
    ~SateDist();

private:
    Ui::SateDist *ui;
};

#endif // SATEDIST_H
