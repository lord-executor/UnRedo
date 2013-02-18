#include "keycommand.h"

KeyCommand::KeyCommand(TextWidget * widget, char character)
{
    _widget = widget;
    _character = character;

    _cursorPos = _widget->textCursor().position();
}

void KeyCommand::doCommand()
{
    _widget->textCursor().movePosition(QTextCursor::Start);
    _widget->textCursor().movePosition(QTextCursor::NextCharacter, QTextCursor::MoveAnchor, _cursorPos);

    _widget->insertPlainText(QString(_character));
}

void KeyCommand::undoCommand()
{

}
