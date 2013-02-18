#include <QString>
#include <QtTest>
#include "../UnRedo/command.h"

class TestCommand : public Command
{
private:
    int _doCount;
    int _undoCount;

public:
    TestCommand()
    {
        _doCount = 0;
        _undoCount = 0;
    }

    void Do()
    {
        _doCount++;
    }
    void Undo()
    {
        _undoCount++;
    }
    int GetDoCount()
    {
        return _doCount;
    }
    int GetUndoCount()
    {
        return _undoCount;
    }
};



class UnRedoTest : public QObject
{
    Q_OBJECT
    
public:
    UnRedoTest();
    
private Q_SLOTS:
    void testTestCommand();
    void testTestCommandDo();
    void testTestCommandUndo();
};

UnRedoTest::UnRedoTest()
{
}

void UnRedoTest::testTestCommand()
{
    TestCommand command;

    QVERIFY2(command.GetDoCount() == 0, "Do count should be 0");
    QVERIFY2(command.GetUndoCount() == 0, "Undo count should be 0");
}

void UnRedoTest::testTestCommandDo()
{
    TestCommand command;
    command.Do();

    QVERIFY2(command.GetDoCount() == 1, "Do count should be 1");
    QVERIFY2(command.GetUndoCount() == 0, "Undo count should be 0");
}

void UnRedoTest::testTestCommandUndo()
{
    TestCommand command;
    command.Undo();

    QVERIFY2(command.GetDoCount() == 0, "Do count should be 0");
    QVERIFY2(command.GetUndoCount() == 1, "Undo count should be 1");
}

QTEST_APPLESS_MAIN(UnRedoTest)

#include "tst_unredotest.moc"
