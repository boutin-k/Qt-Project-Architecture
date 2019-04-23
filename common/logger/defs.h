#ifndef LOG_DEFS_H
#define LOG_DEFS_H

#include <QObject>

namespace Log
{
    enum Level {
        Verbose, Debug, Info, Warning, Error, Assert, MaxLevel
    };
    static const QString LevelName[Level::MaxLevel] = {
        "Verbose", "Debug", "Info", "Warning", "Error", "Assert"
    };
}
Q_DECLARE_METATYPE(Log::Level)

#endif // LOG_DEFS_H

