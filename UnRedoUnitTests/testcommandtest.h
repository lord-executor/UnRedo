#ifndef TESTCOMMANDTEST_H
#define TESTCOMMANDTEST_H

#include "AutoTest.h"

class TestCommandTest : public QObject
{
    Q_OBJECT

public:
    TestCommandTest();

private Q_SLOTS:
    void testTestCommand();
    void testTestCommandDo();
    void testTestCommandUndo();
};

DECLARE_TEST(TestCommandTest)

#endif // TESTCOMMANDTEST_H
