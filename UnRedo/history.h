#ifndef HISTORY_H
#define HISTORY_H

#include<vector>
#include "command.h"

using namespace std;

class History
{
private:
    vector<Command *> _history;
    unsigned int _current;

public:
    History();
    void execute(Command * const command);
    bool canUndo();
    bool canRedo();
    void undo();
    void redo();
};

#endif // HISTORY_H
