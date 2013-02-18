#include "textwidget.h"
#include "ui_textwidget.h"

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

    this->setPlainText(this->toPlainText() + (char)(k->key()));
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
