#ifndef MULTICOMTEST_H
#define MULTICOMTEST_H

#include <QWidget>

namespace Ui {
class multicomtest;
}

class multicomtest : public QWidget
{
    Q_OBJECT

public:
    explicit multicomtest(QWidget *parent = nullptr);
    ~multicomtest();

private:
    Ui::multicomtest *ui;
};

#endif // MULTICOMTEST_H
