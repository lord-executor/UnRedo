#ifndef TESTCOMMAND_H
#define TESTCOMMAND_H

#include "../UnRedo/command.h"

class TestCommand : public Command
{
private:
    int _doCount;
    int _undoCount;

public:
    TestCommand();
    void doCommand();
    void undoCommand();
    int getDoCount();
    int getUndoCount();
};

#endif // TESTCOMMAND_H
