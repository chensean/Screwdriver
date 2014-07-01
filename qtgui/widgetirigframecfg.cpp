#include "widgetirigframecfg.h"
#include "ui_widgetirigframecfg.h"

#include "qtpropertybroswer/qtpropertymanager.h"
#include "qtpropertybroswer/qteditorfactory.h"
#include "qtpropertybroswer/qttreepropertybrowser.h"

WidgetIRIGFrameCfg::WidgetIRIGFrameCfg(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::WidgetIRIGFrameCfg)
{
    ui->setupUi(this);


    QtBoolPropertyManager *boolManager = new QtBoolPropertyManager(this);
    QtIntPropertyManager *intManager = new QtIntPropertyManager(this);
    QtStringPropertyManager *stringManager = new QtStringPropertyManager(this);
    QtEnumPropertyManager *enumManager = new QtEnumPropertyManager(this);
    QtGroupPropertyManager *groupManager = new QtGroupPropertyManager(this);


    QtProperty *gernalItem = groupManager->addProperty("Gernal");

    QtProperty *nameItem = stringManager->addProperty("Name");
    stringManager->setValue(nameItem, "PCM");
    gernalItem->addSubProperty(nameItem);

    QtProperty *bitrateItem = intManager->addProperty("Bit rate(bps)");
    intManager->setValue(bitrateItem, 1024000);
    gernalItem->addSubProperty(bitrateItem);


    QtProperty *frameSetItem = groupManager->addProperty("Frame Setting");

    QtProperty *wordlenItem = intManager->addProperty("PCM Word Lenght(bits)");
    intManager->setValue(wordlenItem, 16);
    frameSetItem->addSubProperty(wordlenItem);

    QtProperty *subframelenItem = intManager->addProperty("Words/Minor Frame");
    intManager->setValue(subframelenItem, 128);
    frameSetItem->addSubProperty(subframelenItem);

    QtProperty *majframelenItem = intManager->addProperty("Minor Frames/Major Frame");
    intManager->setValue(majframelenItem, 16);
    frameSetItem->addSubProperty(majframelenItem);

    QtProperty *fillerpatItem = stringManager->addProperty("Fillter Pattern");
    stringManager->setValue(fillerpatItem, "0xAAAA");
    frameSetItem->addSubProperty(fillerpatItem);

    QtProperty *parityItem = enumManager->addProperty("Parity");
    QStringList parityNames;
    parityNames<< "None" << "Changing";
    enumManager->setEnumNames(parityItem, parityNames);
    frameSetItem->addSubProperty(parityItem);


    QtProperty *framesyncItem = groupManager->addProperty("Frame Sync.");

    QtProperty *syncpatItem = stringManager->addProperty("Sync. Pattern");
    stringManager->setValue(syncpatItem,"0xEB90");
    framesyncItem->addSubProperty(syncpatItem);

    QtProperty *syncpatlenItem = intManager->addProperty("Sync. Pattern Length(bits)");
    intManager->setValue(syncpatlenItem, 16);
    framesyncItem->addSubProperty(syncpatlenItem);


    QtProperty *sfidItem = groupManager->addProperty("SFID");

    QtProperty *directionItem = enumManager->addProperty("Direction");
    QStringList directionname;
    directionname << "Increasing" << "Decreasing";
    enumManager->setEnumNames(directionItem, directionname);
    sfidItem->addSubProperty(directionItem);

    QtProperty *wordposItem = intManager->addProperty("Word Position");
    intManager->setValue(wordposItem, 1);
    sfidItem->addSubProperty(wordposItem);

    QtProperty *lsbbitItem = intManager->addProperty("LSB Bit");
    sfidItem->addSubProperty(lsbbitItem);

    QtProperty *firstvalueItem = intManager->addProperty("First SFID value");
    sfidItem->addSubProperty(firstvalueItem);

    QtProperty *lastvalueItem = intManager->addProperty("Last SFID value");
    intManager->setValue(lastvalueItem, 15);
    sfidItem->addSubProperty(lastvalueItem);




    QtCheckBoxFactory *checkBoxFactory = new QtCheckBoxFactory(this);
    QtSpinBoxFactory *spinBoxFactory = new QtSpinBoxFactory(this);
    QtLineEditFactory *lineEditFactory = new QtLineEditFactory(this);
    QtEnumEditorFactory *comboBoxFactory = new QtEnumEditorFactory(this);

    QtTreePropertyBrowser *irigfrmeditor = new QtTreePropertyBrowser();
    irigfrmeditor->setFactoryForManager(boolManager, checkBoxFactory);
    irigfrmeditor->setFactoryForManager(intManager, spinBoxFactory);
    irigfrmeditor->setFactoryForManager(stringManager, lineEditFactory);
    irigfrmeditor->setFactoryForManager(enumManager, comboBoxFactory);

    irigfrmeditor->addProperty(gernalItem);
    irigfrmeditor->addProperty(frameSetItem);
    irigfrmeditor->addProperty(framesyncItem);
    irigfrmeditor->addProperty(sfidItem);


    irigfrmeditor->setIndentation(10);
    irigfrmeditor->setPropertiesWithoutValueMarked(true);


    ui->propertytreeLayout->addWidget(irigfrmeditor);

}

WidgetIRIGFrameCfg::~WidgetIRIGFrameCfg()
{
    delete ui;
}
