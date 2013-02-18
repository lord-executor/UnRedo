#include "historytest.h"
#include "../UnRedo/history.h"
#include "../UnRedo/historyexception.h"
#include "testcommand.h"
#include <QDebug>
#include <QSharedPointer>
#include <typeinfo>


HistoryTest::HistoryTest()
{
}

void HistoryTest::testEmptyHistory()
{
    History history;

    QVERIFY2(history.canRedo() == false, "Empty history cannot redo");
    QVERIFY2(history.canUndo() == false, "Empty history cannot undo");
}

void HistoryTest::testSingleExecution()
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

void HistoryTest::testUndoOnEmpty()
{
    History history;
    bool exception = false;

    try
    {
        QVERIFY2(!history.canUndo(), "Cannot undo now");
        history.undo();
    }
    catch (HistoryException&)
    {
        exception = true;
    }

    QVERIFY2(exception, "should have been a HistoryException");
}

void HistoryTest::testRedoOnEmpty()
{
    History history;
    bool exception = false;

    try
    {
        QVERIFY2(!history.canRedo(), "Cannot redo now");
        history.redo();
    }
    catch (HistoryException&)
    {
        exception = true;
    }

    QVERIFY2(exception, "should have been a HistoryException");
}

void HistoryTest::testUndoOnBefore()
{
    History history;
    QSharedPointer<Command> command = QSharedPointer<Command>(new TestCommand());
    bool exception = false;

    history.execute(command);
    history.undo();

    try
    {
        QVERIFY2(!history.canUndo(), "Cannot undo now");
        history.undo();
    }
    catch (HistoryException&)
    {
        exception = true;
    }

    QVERIFY2(exception, "should have been a HistoryException");
}

void HistoryTest::testRedoOnLast()
{
    History history;
    QSharedPointer<Command> command = QSharedPointer<Command>(new TestCommand());
    bool exception = false;

    history.execute(command);

    try
    {
        QVERIFY2(!history.canRedo(), "Cannot redo now");
        history.redo();
    }
    catch (HistoryException&)
    {
        exception = true;
    }

    QVERIFY2(exception, "should have been a HistoryException");
}

void HistoryTest::testMultiCommandUndoRedo()
{
    History history;
    QSharedPointer<TestCommand> c1 = QSharedPointer<TestCommand>(new TestCommand());
    QSharedPointer<TestCommand> c2 = QSharedPointer<TestCommand>(new TestCommand());
    QSharedPointer<TestCommand> c3 = QSharedPointer<TestCommand>(new TestCommand());

    history.execute(c1);
    history.execute(c2);
    history.execute(c3);
    history.undo();
    history.undo();
    history.redo();
    history.redo();
    history.undo();
    history.redo();

    QVERIFY2(c1->getDoCount() == 1, "First executed once");
    QVERIFY2(c1->getUndoCount() == 0, "First never undone");
    QVERIFY2(c2->getDoCount() == 2, "Second executed once");
    QVERIFY2(c2->getUndoCount() == 1, "Second never undone");
    QVERIFY2(c3->getDoCount() == 3, "Third executed once");
    QVERIFY2(c3->getUndoCount() == 2, "Third never undone");
}

void HistoryTest::testHistoryWipeAfterExecute()
{
    History history;
    QSharedPointer<TestCommand> c1 = QSharedPointer<TestCommand>(new TestCommand());
    QSharedPointer<TestCommand> c2 = QSharedPointer<TestCommand>(new TestCommand());
    QSharedPointer<TestCommand> c3 = QSharedPointer<TestCommand>(new TestCommand());
    QSharedPointer<TestCommand> c4 = QSharedPointer<TestCommand>(new TestCommand());

    history.execute(c1);
    history.execute(c2);
    history.execute(c3);
    history.undo();
    history.undo();
    history.execute(c4);

    QVERIFY2(!history.canRedo(), "Execute wipes the (forward) history");

    QVERIFY2(c1->getDoCount() == 1, "First executed once");
    QVERIFY2(c1->getUndoCount() == 0, "First never undone");
    QVERIFY2(c2->getDoCount() == 1, "Second executed once");
    QVERIFY2(c2->getUndoCount() == 1, "Second never undone");
    QVERIFY2(c3->getDoCount() == 1, "Third executed once");
    QVERIFY2(c3->getUndoCount() == 1, "Third never undone");
    QVERIFY2(c4->getDoCount() == 1, "Fourth executed once");
    QVERIFY2(c4->getUndoCount() == 0, "Fourth never undone");
}
