#include "widgettaskcfg.h"
#include "ui_widgettaskcfg.h"

#include <QDebug>

WidgetTaskCfg::WidgetTaskCfg(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::WidgetTaskCfg)
{
    ui->setupUi(this);

    ui->taskconfigurationtree->expandAll();

    connect(ui->taskconfigurationtree,SIGNAL(itemClicked(QTreeWidgetItem*,int)),this,SLOT(cfgnodeswitch(QTreeWidgetItem*,int)));


}

WidgetTaskCfg::~WidgetTaskCfg()
{
    delete ui;
}

/*!
    // Configuration Content Switch
*/
void WidgetTaskCfg::cfgnodeswitch(QTreeWidgetItem *item, int column)
{
    QString nodetext = item->text(column);

    if(nodetext == "Cortex RTR")
    {
        ui->cfgstackedWidget->setCurrentIndex(0);
    }
    else if (nodetext == "IRIG Frames Structure")
    {
        ui->cfgstackedWidget->setCurrentIndex(1);
    }
    else if (nodetext =="Channels")
    {
        ui->cfgstackedWidget->setCurrentIndex(2);
    }
    else if (nodetext == "Graphic Preview")
    {
        ui->cfgstackedWidget->setCurrentIndex(3);
    }

}
