#include "historytest.h"
#include "../UnRedo/history.h"
#include "testcommand.h"
#include <QDebug>
#include <QSharedPointer>

HistoryTest::HistoryTest()
{
}

void HistoryTest::testConstructor()
{
    History history;

    QVERIFY2(history.canRedo() == false, "Empty history cannot redo");
    QVERIFY2(history.canUndo() == false, "Empty history cannot undo");
}

void HistoryTest::testExecution()
{
    History history;
    TestCommand * command = new TestCommand();

    QSharedPointer<Command> p = QSharedPointer<Command>(command);
    history.execute(p);

    QVERIFY2(history.canUndo() == true, "What has been done can be undone");
    QVERIFY2(history.canRedo() == false, "Still nothing to redo");
    QVERIFY2(command->getDoCount() == 1, "Command has been executed");
    QVERIFY2(command->getUndoCount() == 0, "Command has not been undone");
}

void HistoryTest::testUndo()
{
    History history;
    TestCommand * command = new TestCommand();

    history.execute(QSharedPointer<Command>(command));
    history.undo();

    QVERIFY2(history.canUndo() == false, "Back where we started");
    QVERIFY2(history.canRedo() == true, "Redo possible after undo");
    QVERIFY2(command->getDoCount() == 1, "Command has been executed");
    QVERIFY2(command->getUndoCount() == 1, "Command has been undone");
}

void HistoryTest::testRedo()
{
    History history;
    TestCommand * command = new TestCommand();

    history.execute(QSharedPointer<Command>(command));
    history.undo();
    history.redo();

    QVERIFY2(history.canUndo() == true, "Undo always possible after redo");
    QVERIFY2(history.canRedo() == false, "No redo at end of command sequence");
    QVERIFY2(command->getDoCount() == 2, "Command has been executed twice");
    QVERIFY2(command->getUndoCount() == 1, "Command has been undone");
}
