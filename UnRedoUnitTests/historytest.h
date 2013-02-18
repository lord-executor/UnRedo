#ifndef HISTORYTEST_H
#define HISTORYTEST_H

#include "AutoTest.h"

class HistoryTest : public QObject
{
    Q_OBJECT

public:
    HistoryTest();

private Q_SLOTS:
    void testEmptyHistory();
    void testSingleExecution();
    void testUndo();
    void testRedo();
    void testUndoOnEmpty();
    void testUndoOnBefore();
    void testRedoOnEmpty();
    void testRedoOnLast();
};

DECLARE_TEST(HistoryTest)

#endif // HISTORYTEST_H
