#include "irigframegraphicpreview.h"
#include "ui_irigframegraphicpreview.h"

IRIGFrameGraphicPreview::IRIGFrameGraphicPreview(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::IRIGFrameGraphicPreview)
{
    ui->setupUi(this);
}

IRIGFrameGraphicPreview::~IRIGFrameGraphicPreview()
{
    delete ui;
}
