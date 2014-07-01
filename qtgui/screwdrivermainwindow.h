#ifndef SCREWDRIVERMAINWINDOW_H
#define SCREWDRIVERMAINWINDOW_H

#include <QMainWindow>

#include "widgettaskcfg.h"
#include "widgettaskmanage.h"



namespace Ui {
class ScrewdriverMainWindow;
}

typedef enum
{
    TaskManagerMode   = 0,
    ConfigurationMode = 1,
    AnalysisMode      = 2,
    AcquisiationMode  = 3,
    PlaybackMode      = 4
} UIMode;


class ScrewdriverMainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit ScrewdriverMainWindow(QWidget *parent = 0);
    ~ScrewdriverMainWindow();

private:
    Ui::ScrewdriverMainWindow *ui;

    WidgetTaskCfg    *uiWidgetTaskCfg;
    WidgetTaskManage *uiWidgetTaskManage;

Q_SIGNALS:

    void signalmodeswitch(UIMode mode);



private slots:
    void on_actionAbout_Screwdriver_triggered();

    void slotmodeswitch(UIMode mode);

    void on_actionTaskMgrMode_triggered();
    void on_actionAcqMode_triggered();
    void on_actionCfgMode_triggered();
    void on_actionAnalysisMode_triggered();
    void on_actionPlaybackMode_triggered();
};

#endif // SCREWDRIVERMAINWINDOW_H
