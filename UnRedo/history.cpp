#include "history.h"

History::History()
    : _history()
{
}

void History::execute(Command const * command)
{
    _history.push_back(command);
}

bool History::canUndo()
{

}

bool History::canRedo()
{
}

void History::undo()
{
}

void History::redo()
{
}
