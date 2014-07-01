#ifndef WIDGETIRIGFRAMECFG_H
#define WIDGETIRIGFRAMECFG_H

#include <QWidget>

namespace Ui {
class WidgetIRIGFrameCfg;
}

class WidgetIRIGFrameCfg : public QWidget
{
    Q_OBJECT

public:
    explicit WidgetIRIGFrameCfg(QWidget *parent = 0);
    ~WidgetIRIGFrameCfg();

private:
    Ui::WidgetIRIGFrameCfg *ui;
};

#endif // WIDGETIRIGFRAMECFG_H
