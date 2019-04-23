#ifndef LOGGER_H
#define LOGGER_H

#include <QObject>
#include <QMutex>
#include <QFile>
#include <QMap>

#include "common/logger/defs.h"

namespace Log
{
    class Logger: public QObject
    {
        Q_OBJECT

    public:
        enum Extension { LOG, SAV };
        Q_ENUM(Extension)

        static Logger& Instance();

        void log(const QString& fileName, const Log::Level& pLevel, const QString& pMessage);

    private:
        explicit Logger(void): QObject(nullptr) {}
        ~Logger(void) {}

    private:
        QString getFilePath(const QString& pFileName, Extension pExtension) const;
        QFile* openFile(const QString& pFileName, Extension pExtension) noexcept(false);
        void backupFile(QFile* pFile, const QString& pFileName) noexcept(false);

    private:
        QMap<QString, QFile*>   mFileList;
        mutable QMutex          mMutex;
    };
}

#endif // LOGGER_H
