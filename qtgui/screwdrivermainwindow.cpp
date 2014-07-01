#include <QMessageBox>
#include <QDebug>

#include "screwdrivermainwindow.h"
#include "ui_screwdrivermainwindow.h"



ScrewdriverMainWindow::ScrewdriverMainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ScrewdriverMainWindow)
{
    ui->setupUi(this);

    connect(this, SIGNAL(signalmodeswitch(UIMode)), this, SLOT(slotmodeswitch(UIMode)));


    //ui->modeSwitchToolBar->toolButtonStyle();
}

ScrewdriverMainWindow::~ScrewdriverMainWindow()
{
    delete ui;
}



void ScrewdriverMainWindow::on_actionTaskMgrMode_triggered()
{
    emit signalmodeswitch(UIMode::TaskManagerMode);
}

void ScrewdriverMainWindow::on_actionCfgMode_triggered()
{
    emit signalmodeswitch(UIMode::ConfigurationMode);
}

void ScrewdriverMainWindow::on_actionAnalysisMode_triggered()
{
    emit signalmodeswitch(UIMode::AnalysisMode);
}

void ScrewdriverMainWindow::on_actionAcqMode_triggered()
{
    emit signalmodeswitch(UIMode::AcquisiationMode);
}

void ScrewdriverMainWindow::on_actionPlaybackMode_triggered()
{
    emit signalmodeswitch(UIMode::PlaybackMode);
}


void ScrewdriverMainWindow::slotmodeswitch(UIMode mode)
{
    //qDebug()<< "Mode:" <<mode;


    switch (mode)
    {
    case UIMode::TaskManagerMode:
    {
        ui->stackedWidget->setCurrentIndex(0);
        break;
    }

    case UIMode::ConfigurationMode:
    {
        ui->stackedWidget->setCurrentIndex(1);
        break;
    }

    case UIMode::AnalysisMode:
    {
        break;
    }

    case UIMode::AcquisiationMode:
    {
        break;
    }

    case UIMode::PlaybackMode:
    {
        break;
    }
    }//switch

}















void ScrewdriverMainWindow::on_actionAbout_Screwdriver_triggered()
{
    QMessageBox::about(this, tr("About Screwdriver"),
                       tr("<p>This is Screwdriver</p>"
                          "<p>Copyright (C) 2014 Sean Chen</p>"
                          "<p>Screwdriver is a telemetry data decom software.</p>"
                          "<p>Author:  Sean Chen</p>"
                          "<p>Mobile:  13910848917</p>"
                          "<p>Email:   sean.yu@newworldt.com</p>"
                          "<p>Company: New World Telecom </p>"
                          "<p>Website: <a href='http://www.newworldt.com'>www.newworldt.com</a></p>"));
}


