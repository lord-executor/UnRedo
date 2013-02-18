#include "exception.h"

Exception::Exception(QString exceptionMessage)
{
    _message = exceptionMessage;
}

QString Exception::toString()
{
    return _message;
}
