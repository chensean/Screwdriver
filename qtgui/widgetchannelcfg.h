#ifndef WIDGETCHANNELCFG_H
#define WIDGETCHANNELCFG_H

#include <QWidget>

namespace Ui {
class WidgetChannelCfg;
}

class WidgetChannelCfg : public QWidget
{
    Q_OBJECT

public:
    explicit WidgetChannelCfg(QWidget *parent = 0);
    ~WidgetChannelCfg();


private:
    Ui::WidgetChannelCfg *ui;

    void paramPropertyTreeSetup();
};

#endif // WIDGETCHANNELCFG_H
