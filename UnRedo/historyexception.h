#ifndef HISTORYEXCEPTION_H
#define HISTORYEXCEPTION_H

#include "exception.h"
#include <QString>

class HistoryException : public Exception
{
public:
    HistoryException(QString message);
};

#endif // HISTORYEXCEPTION_H
