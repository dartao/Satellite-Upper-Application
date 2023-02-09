#ifndef DATASHOW_H
#define DATASHOW_H

#include <QWidget>

namespace Ui {
class DataShow;
}

class DataShow : public QWidget
{
    Q_OBJECT

public:
    explicit DataShow(QWidget *parent = nullptr);
    ~DataShow();

private:
    Ui::DataShow *ui;
};

#endif // DATASHOW_H
