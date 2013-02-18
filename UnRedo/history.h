#ifndef HISTORY_H
#define HISTORY_H

#include<vector>
#include<QSharedPointer>
#include "command.h"

using namespace std;

class History
{
private:
    vector< QSharedPointer<Command> > _history;
    unsigned int _current;

public:
    History();
    ~History();
    void execute(QSharedPointer<Command> command);
    bool canUndo();
    bool canRedo();
    void undo();
    void redo();
};

#endif // HISTORY_H
