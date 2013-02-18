#ifndef TEXTWIDGET_H
#define TEXTWIDGET_H

#include <QPlainTextEdit>
#include "history.h"

namespace Ui {
class TextWidget;
}

class TextWidget : public QPlainTextEdit
{
    Q_OBJECT
    
public:
    explicit TextWidget(QWidget *parent = 0);
    ~TextWidget();

protected:
    void keyPressEvent(QKeyEvent *e);
    
private:
    Ui::TextWidget *ui;
    History _history;
};

#endif // TEXTWIDGET_H
