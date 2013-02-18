#ifndef KEYCOMMAND_H
#define KEYCOMMAND_H

#include "textwidget.h"

class KeyCommand : public Command
{
public:
    KeyCommand(TextWidget * widget, char character);
    void doCommand();
    void undoCommand();

private:
    TextWidget * _widget;
    char _character;
    int _cursorPos;
};

#endif // KEYCOMMAND_H
