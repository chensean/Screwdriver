#ifndef WIDGETRTRCOMCFG_H
#define WIDGETRTRCOMCFG_H

#include <QWidget>

namespace Ui {
class WidgetRTRComCfg;
}

class WidgetRTRComCfg : public QWidget
{
    Q_OBJECT

public:
    explicit WidgetRTRComCfg(QWidget *parent = 0);
    ~WidgetRTRComCfg();

private:
    Ui::WidgetRTRComCfg *ui;
};

#endif // WIDGETRTRCOMCFG_H
