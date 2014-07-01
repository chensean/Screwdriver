#include "workspacemanage.h"
#include "ui_workspacemanage.h"

#include <QMenu>
#include <QMessageBox>
#include <QFile>

#include <QLineEdit>
#include <QStyledItemDelegate>


#include <QDebug>
#include <QDir>


#include "newtaskdialog.h"



WorkspaceFileModel::WorkspaceFileModel(QObject *parent) : QFileSystemModel(parent)
{}

WorkspaceFileModel::~WorkspaceFileModel()
{}

int WorkspaceFileModel::columnCount(const QModelIndex &parent) const
{
    return 1;
}

QVariant WorkspaceFileModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    if (orientation == Qt::Horizontal && role == Qt::DisplayRole)
        return QString("Workspace");

    return QVariant();
}




/*

class NameEidtDelegate : public QStyledItemDelegate
{
    Q_OBJECT

public:

};

*/







WorkspaceManage::WorkspaceManage(QWidget *parent) :
    QFrame(parent),
    ui(new Ui::WorkspaceManage)
{
    ui->setupUi(this);

    //QFileSystemModel *model = new QFileSystemModel(parent);
    model = new WorkspaceFileModel();


    model->setRootPath("D:/Sean_Chen/DEV/Workspace");

    model->setFilter(QDir::Dirs | QDir::NoDotAndDotDot |QDir::NoSymLinks);



    ui->workspace->setModel(model);

    ui->workspace->setRootIndex(model->index("D:/Sean_Chen/DEV/Workspace"));


    connect(ui->workspace,SIGNAL(pressed(QModelIndex)),this,SLOT(showtaskmodifymenu(QModelIndex)));
    connect(ui->workspace,SIGNAL(doubleClicked(QModelIndex)),this,SLOT(activeSelectedTask(QModelIndex)));

    connect(ui->actionTaskSetActive,SIGNAL(triggered()),this,SLOT(on_actionTaskSetActive_triggered()));


}

WorkspaceManage::~WorkspaceManage()
{
    model->deleteLater();
    delete ui;
}




void WorkspaceManage::showtaskmodifymenu(QModelIndex index)
{
    if (qApp->mouseButtons() == Qt::RightButton)
    {
        QPoint pos;
        QMenu menu(ui->workspace);
        menu.addAction(ui->actionTaskSetActive);
        menu.addAction(ui->actionTaskNew);
        menu.addAction(ui->actionTaskDelete);
        menu.addAction(ui->actionTaskRename);
        menu.exec(QCursor::pos());
    }
}

void WorkspaceManage::on_actionTaskSetActive_triggered()
{
    activeSelectedTask(ui->workspace->currentIndex());
}

// Delete selected task
void WorkspaceManage::on_actionTaskDelete_triggered()
{
    QModelIndex deleteindex = ui->workspace->currentIndex();;
    // Confirm whether delete the task
    QMessageBox::StandardButton rb = QMessageBox::question(this,
                                                           tr(""),
                                                           tr("<p>Are you sure you wish delete this task?</p>"
                                                              "<p>This operation is irreversible!</p>"),
                                                           QMessageBox::Yes | QMessageBox::Cancel);
    if(rb == QMessageBox::Yes)
    {
        activeSelectedTask(deleteindex);
    }
}

// Create new task
void WorkspaceManage::on_actionTaskNew_triggered()
{
    NewTaskDialog dialog(this);
    if(dialog.exec() == QDialog::Accepted)
    {
        QString name = dialog.name();//get task name

        if(model->index(model->rootPath()+"/"+name).isValid())//check whether this name already exist.
        {
            QMessageBox::warning(this,
                                 tr("Warning"),
                                 tr("<p>This project already exist!</p>"
                                    "<p>Please using other name</p>"),
                                 QMessageBox::Ok);
            return;
        }

        // if new name, create new task.
        createNewTask(name);
    }
}

// Task rename
void WorkspaceManage::on_actionTaskRename_triggered()
{
    QModelIndex renameindex = ui->workspace->currentIndex();

    QString rootpath = model->rootPath();
/*
    QFile file(rootpath+"/"+model->fileName(renameindex));
    file.rename(rootpath+"/"+"chand");
    //model->setData(renameindex, "changed", Qt::EditRole);
*/
}




void WorkspaceManage::activeSelectedTask(QModelIndex index)
{

//    QFont fontb;
  //  fontb.setBold(true);
    //fontb.setWeight(75);
    //ui->workspace->setFont(fontb);

    qDebug()<< index.data(Qt::DisplayRole);

    //index.model()->setData(index,"changed",Qt::EditRole);

    //qDebug()<< "path:" <<model->filePath(index);

    //qDebug()<< model->rmdir(index);
    //qDebug()<< model->remove(index);
    //qDebug()<<ui->workspace->rootIndex();
    //model->mkdir(ui->workspace->rootIndex(),"new folder");

    qDebug()<<"check"<< model->index("D:/Sean_Chen/DEV/Workspace/New folder").isValid();
    qDebug()<<model->rootPath();

}



void WorkspaceManage::createNewTask(const QString &name)
{
    model->mkdir(ui->workspace->rootIndex(),name);
}


void WorkspaceManage::deleteSelectedTask(QModelIndex index)
{
    model->remove(index);
}









void WorkspaceManage::on_searchEdit_selectionChanged()
{
    qDebug()<<"select editline";
}
