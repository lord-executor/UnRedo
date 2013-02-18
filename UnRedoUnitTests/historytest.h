#ifndef HISTORYTEST_H
#define HISTORYTEST_H

#include "AutoTest.h"

class HistoryTest : public QObject
{
    Q_OBJECT

public:
    HistoryTest();

private Q_SLOTS:
    void testConstructor();
    void testExecution();
    void testUndo();
    void testRedo();
};

DECLARE_TEST(HistoryTest)

#endif // HISTORYTEST_H
