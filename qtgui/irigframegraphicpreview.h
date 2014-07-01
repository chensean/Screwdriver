#ifndef IRIGFRAMEGRAPHICPREVIEW_H
#define IRIGFRAMEGRAPHICPREVIEW_H

#include <QWidget>

namespace Ui {
class IRIGFrameGraphicPreview;
}

class IRIGFrameGraphicPreview : public QWidget
{
    Q_OBJECT

public:
    explicit IRIGFrameGraphicPreview(QWidget *parent = 0);
    ~IRIGFrameGraphicPreview();

private:
    Ui::IRIGFrameGraphicPreview *ui;
};

#endif // IRIGFRAMEGRAPHICPREVIEW_H
