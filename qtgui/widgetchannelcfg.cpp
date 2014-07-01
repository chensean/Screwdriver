#include "widgetchannelcfg.h"
#include "ui_widgetchannelcfg.h"

#include "qtpropertybroswer/qtpropertymanager.h"
#include "qtpropertybroswer/qteditorfactory.h"
#include "qtpropertybroswer/qttreepropertybrowser.h"


WidgetChannelCfg::WidgetChannelCfg(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::WidgetChannelCfg)
{
    ui->setupUi(this);


    paramPropertyTreeSetup();
}

WidgetChannelCfg::~WidgetChannelCfg()
{
    delete ui;
}




void WidgetChannelCfg::paramPropertyTreeSetup()
{

    QtBoolPropertyManager *boolManager = new QtBoolPropertyManager(this);
    QtIntPropertyManager *intManager = new QtIntPropertyManager(this);
    QtStringPropertyManager *stringManager = new QtStringPropertyManager(this);
    QtEnumPropertyManager *enumManager = new QtEnumPropertyManager(this);
    QtGroupPropertyManager *groupManager = new QtGroupPropertyManager(this);


    QtProperty *gernalItem = groupManager->addProperty("Name");

    QtProperty *nameItem = stringManager->addProperty("Name");
    stringManager->setValue(nameItem, "Param1");
    gernalItem->addSubProperty(nameItem);


    QtProperty *extractItem = groupManager->addProperty("Extraction");


    QtProperty *conversionItem = groupManager->addProperty("Conversion");




    QtCheckBoxFactory *checkBoxFactory = new QtCheckBoxFactory(this);
    QtSpinBoxFactory *spinBoxFactory = new QtSpinBoxFactory(this);
    QtLineEditFactory *lineEditFactory = new QtLineEditFactory(this);
    QtEnumEditorFactory *comboBoxFactory = new QtEnumEditorFactory(this);

    QtTreePropertyBrowser *paraeditor = new QtTreePropertyBrowser();

    paraeditor->setFactoryForManager(boolManager, checkBoxFactory);
    paraeditor->setFactoryForManager(intManager, spinBoxFactory);
    paraeditor->setFactoryForManager(stringManager, lineEditFactory);
    paraeditor->setFactoryForManager(enumManager, comboBoxFactory);

    paraeditor->addProperty(gernalItem);
    paraeditor->addProperty(extractItem);
    paraeditor->addProperty(conversionItem);

    paraeditor->setIndentation(10);
    paraeditor->setPropertiesWithoutValueMarked(true);

    ui->propertytreeLayout->addWidget(paraeditor);


}
