#include "history.h"

History::History()
    : _history()
{
    _current = 0;
}

void History::execute(Command * const command)
{
    if (_current < _history.size())
        _history.at(_current) = command;
    else
        _history.push_back(command);

    command->doCommand();
    _current++;
}

bool History::canUndo()
{
    if (_history.empty())
        return false;

    return _current > 0;
}

bool History::canRedo()
{
    if (_history.empty())
        return false;

    return _current < (int)(_history.size());
}

void History::undo()
{
    if (!canUndo())
        throw "impossible undo";

    _history.at(--_current)->undoCommand();
}

void History::redo()
{
}
