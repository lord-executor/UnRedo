#include "textwidget.h"
#include "ui_textwidget.h"
#include "keycommand.h"
#include <QSharedPointer>

TextWidget::TextWidget(QWidget *parent) :
    QPlainTextEdit(parent),
    ui(new Ui::TextWidget)
{
    ui->setupUi(this);
}

TextWidget::~TextWidget()
{
    delete ui;
}

void TextWidget::keyPressEvent(QKeyEvent *k)
{
    KeyCommand * command = new KeyCommand(this, (char)(k->key()));
    _history.execute(QSharedPointer<Command>(command));
/*switch ( tolower(k->ascii()) ) {
case 'r': // reload
pict->load( name );
update();
break;
case 'q': // quit
QApplication::exit();
break;
}*/
}
