#ifndef COMMAND_H
#define COMMAND_H

class Command
{
public:
    virtual ~Command() {}

    virtual void Do() = 0;
    virtual void Undo() = 0;
};

#endif // COMMAND_H
