#ifndef HISTORY_H
#define HISTORY_H

#include<list>
#include "command.h"

using namespace std;

class History
{
private:
    list<Command const *> _history;

public:
    History();
    void execute(Command const * command);
    bool canUndo();
    bool canRedo();
    void undo();
    void redo();
};

#endif // HISTORY_H
