#ifndef MAPTRAKE_H
#define MAPTRAKE_H

#include <QWidget>

namespace Ui {
class MapTrake;
}

class MapTrake : public QWidget
{
    Q_OBJECT

public:
    explicit MapTrake(QWidget *parent = nullptr);
    ~MapTrake();

private:
    Ui::MapTrake *ui;
};

#endif // MAPTRAKE_H
