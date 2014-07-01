#ifndef WIDGETTASKMANAGE_H
#define WIDGETTASKMANAGE_H

#include <QWidget>


namespace Ui {
class WidgetTaskManage;
}

class WidgetTaskManage : public QWidget
{
    Q_OBJECT

public:
    explicit WidgetTaskManage(QWidget *parent = 0);
    ~WidgetTaskManage();


private:
    Ui::WidgetTaskManage *ui;




};

#endif // WIDGETTASKMANAGE_H
