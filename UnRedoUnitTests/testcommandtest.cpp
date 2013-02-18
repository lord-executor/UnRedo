#include "testcommandtest.h"
#include "testcommand.h"

TestCommandTest::TestCommandTest()
{
}

void TestCommandTest::testTestCommand()
{
    TestCommand command;

    QVERIFY2(command.getDoCount() == 0, "Do count should be 0");
    QVERIFY2(command.getUndoCount() == 0, "Undo count should be 0");
}

void TestCommandTest::testTestCommandDo()
{
    TestCommand command;
    command.doCommand();

    QVERIFY2(command.getDoCount() == 1, "Do count should be 1");
    QVERIFY2(command.getUndoCount() == 0, "Undo count should be 0");
}

void TestCommandTest::testTestCommandUndo()
{
    TestCommand command;
    command.undoCommand();

    QVERIFY2(command.getDoCount() == 0, "Do count should be 0");
    QVERIFY2(command.getUndoCount() == 1, "Undo count should be 1");
}

