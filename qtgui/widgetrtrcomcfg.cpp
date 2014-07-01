#include "widgetrtrcomcfg.h"
#include "ui_widgetrtrcomcfg.h"

#include "qtpropertybroswer/qtpropertymanager.h"
#include "qtpropertybroswer/qteditorfactory.h"
#include "qtpropertybroswer/qttreepropertybrowser.h"

WidgetRTRComCfg::WidgetRTRComCfg(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::WidgetRTRComCfg)
{
    ui->setupUi(this);


    QtGroupPropertyManager *groupManager = new QtGroupPropertyManager(this);
    QtEnumPropertyManager *enumManager = new QtEnumPropertyManager(this);
    QtBoolPropertyManager *boolManager = new QtBoolPropertyManager(this);
    QtIntPropertyManager *intManager = new QtIntPropertyManager(this);
    QtStringPropertyManager *stringManager = new QtStringPropertyManager(this);



    QtProperty *rtrnetworkItem = groupManager->addProperty("RTR Nerwork");

    QtProperty *ipconnectionItem = enumManager->addProperty("IP connection type");
    QStringList iptypelist;
    iptypelist << "TCP";
    enumManager->setEnumNames(ipconnectionItem, iptypelist);
    rtrnetworkItem->addSubProperty(ipconnectionItem);

    QtProperty *rtripaddrItem = stringManager->addProperty("RTR IP address");
    stringManager->setValue(rtripaddrItem, "192.168.1.1");
    rtrnetworkItem->addSubProperty(rtripaddrItem);

    QtProperty *rtripportItem = intManager->addProperty("Port");
    intManager->setValue(rtripportItem, 3070);
    rtrnetworkItem->addSubProperty(rtripportItem);


    QtProperty *rtrtelestmItem = groupManager->addProperty("RTR Telemetry Stream");

    QtProperty *datasourceItem = enumManager->addProperty("Data Source");
    QStringList datashourcelist;
    datashourcelist << "RTR Network" << "RTR Simulator";
    enumManager->setEnumNames(datasourceItem, datashourcelist);
    rtrtelestmItem->addSubProperty(datasourceItem);

    QtProperty *telechannelItem = enumManager->addProperty("Telemetry Channel");
    QStringList rtrchannellist;
    rtrchannellist << "1" << "2" << "3";
    enumManager->setEnumNames(telechannelItem, rtrchannellist);
    rtrtelestmItem->addSubProperty(telechannelItem);

    QtProperty *bitrateItem = intManager->addProperty("Bit rate(bps)");
    intManager->setValue(bitrateItem, 1024000);
    rtrtelestmItem->addSubProperty(bitrateItem);


    QtProperty *rtrfrmsyncItem = groupManager->addProperty("Frame Synchro");

    QtProperty *softfrmsyncItem = enumManager->addProperty("Software frame sync");
    QStringList softsynclist;
    softsynclist << "Yes" << "No";
    enumManager->setEnumNames(softfrmsyncItem, softsynclist);
    rtrfrmsyncItem->addSubProperty(softfrmsyncItem);

    QtCheckBoxFactory *checkBoxFactory = new QtCheckBoxFactory(this);
    QtSpinBoxFactory *spinBoxFactory = new QtSpinBoxFactory(this);
    QtLineEditFactory *lineEditFactory = new QtLineEditFactory(this);
    QtEnumEditorFactory *comboBoxFactory = new QtEnumEditorFactory(this);

    QtTreePropertyBrowser *rtreditor = new QtTreePropertyBrowser();
    rtreditor->setFactoryForManager(boolManager, checkBoxFactory);
    rtreditor->setFactoryForManager(intManager, spinBoxFactory);
    rtreditor->setFactoryForManager(stringManager, lineEditFactory);
    rtreditor->setFactoryForManager(enumManager, comboBoxFactory);

    rtreditor->addProperty(rtrnetworkItem);
    rtreditor->addProperty(rtrtelestmItem);
    rtreditor->addProperty(rtrfrmsyncItem);

    rtreditor->setIndentation(10);
    rtreditor->setPropertiesWithoutValueMarked(true);

    ui->propertytreeLayout->addWidget(rtreditor);


}

WidgetRTRComCfg::~WidgetRTRComCfg()
{
    delete ui;
}
