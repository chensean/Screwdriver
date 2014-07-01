#ifndef WIDGETTASKCFG_H
#define WIDGETTASKCFG_H

#include <QWidget>
#include <QTreeWidget>

namespace Ui {
class WidgetTaskCfg;
}

class WidgetTaskCfg : public QWidget
{
    Q_OBJECT

public:
    explicit WidgetTaskCfg(QWidget *parent = 0);
    ~WidgetTaskCfg();

public Q_SLOTS:

    void cfgnodeswitch(QTreeWidgetItem *item, int column);

private:
    Ui::WidgetTaskCfg *ui;
};

#endif // WIDGETTASKCFG_H
