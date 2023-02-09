#ifndef CHANNELINFO_H
#define CHANNELINFO_H

#include <QWidget>

namespace Ui {
class ChannelInfo;
}

class ChannelInfo : public QWidget
{
    Q_OBJECT

public:
    explicit ChannelInfo(QWidget *parent = nullptr);
    ~ChannelInfo();

private:
    Ui::ChannelInfo *ui;
};

#endif // CHANNELINFO_H
