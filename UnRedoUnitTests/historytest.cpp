#include "historytest.h"
#include "../UnRedo/history.h"

HistoryTest::HistoryTest()
{
}

void HistoryTest::testConstructor()
{
    History history;

    QVERIFY2(history.canRedo() == false, "Empty history cannot redo");
    QVERIFY2(history.canUndo() == false, "Empty history cannot undo");
}
