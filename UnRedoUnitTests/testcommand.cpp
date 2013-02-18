#include "testcommand.h"

TestCommand::TestCommand()
{
    _doCount = 0;
    _undoCount = 0;
}
TestCommand::~TestCommand()
{
}

void TestCommand::doCommand()
{
    _doCount++;
}
void TestCommand::undoCommand()
{
    _undoCount++;
}
int TestCommand::getDoCount()
{
    return _doCount;
}
int TestCommand::getUndoCount()
{
    return _undoCount;
}
