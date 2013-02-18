#include "history.h"
#include "historyexception.h"

History::History()
    : _history()
{
    _current = 0;
}
History::~History()
{
}

void History::execute(QSharedPointer<Command> command)
{
    if (_current < _history.size())
    {
        // wipe history from current to end so we can
        // rewrite said history
        _history.resize(_current);
    }

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

    return _current < _history.size();
}

void History::undo()
{
    if (!canUndo())
        throw HistoryException("impossible undo");

    _history.at(--_current)->undoCommand();
}

void History::redo()
{
    if (!canRedo())
        throw HistoryException("impossible redo");

    _history.at(_current++)->doCommand();
}
