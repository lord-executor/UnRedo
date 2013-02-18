#ifndef EXCEPTION_H
#define EXCEPTION_H

#include <QString>

class Exception
{
public:
    Exception(QString exceptionMessage);

    virtual QString toString();

private:
    QString _message;
};

#endif // EXCEPTION_H
