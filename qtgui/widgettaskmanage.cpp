#include "widgettaskmanage.h"
#include "ui_widgettaskmanage.h"



WidgetTaskManage::WidgetTaskManage(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::WidgetTaskManage)
{
    ui->setupUi(this);





}

WidgetTaskManage::~WidgetTaskManage()
{
    delete ui;
}















