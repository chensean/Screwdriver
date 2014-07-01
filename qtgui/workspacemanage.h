#ifndef WORKSPACEMANAGE_H
#define WORKSPACETREE_H

#include <QFrame>
#include <QTreeWidget>
#include <QFileSystemModel>



class WorkspaceFileModel : public QFileSystemModel
{
public:
    explicit WorkspaceFileModel(QObject * parent = 0);
    ~WorkspaceFileModel();

    int columnCount(const QModelIndex & parent = QModelIndex()) const;
    QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const;
};




namespace Ui {
class WorkspaceManage;
}


class WorkspaceManage : public QFrame
{
    Q_OBJECT

public:
    explicit WorkspaceManage(QWidget *parent = 0);
    ~WorkspaceManage();

private Q_SLOTS:

    void showtaskmodifymenu(QModelIndex index);

    void activeSelectedTask(QModelIndex index);
    void createNewTask(const QString &name);
    void deleteSelectedTask(QModelIndex index);


    void on_actionTaskSetActive_triggered();

    void on_actionTaskDelete_triggered();

    void on_actionTaskNew_triggered();

    void on_actionTaskRename_triggered();

    void on_searchEdit_selectionChanged();

private:
    Ui::WorkspaceManage *ui;

    WorkspaceFileModel *model;
};

#endif // WORKSPACEMANAGE_H
