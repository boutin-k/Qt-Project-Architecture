#include <QMutexLocker>
#include <QDebug>
#include <QDir>
#include <QMetaEnum>
#include <QDateTime>

#include "common/logger/defs.h"
#include "logger.h"

#define LOG_DIRECTORY           "logs/"
#define LOG_FILE_MAX_SIZE       (1000 * 1000 * 4) // 4Mo

#define EnumToString(T, V)      QMetaEnum::fromType<T>().valueToKey(V)

#define DATE_TIME_FORMAT        "yyyy-MM-dd | hh:mm:ss.zzz"
#define DATE_TIME_TO_STRING     QDateTime::currentDateTime().toString(DATE_TIME_FORMAT)

using namespace Log;

/**
 * @brief Logger::Instance
 * @return
 */
Logger& Logger::Instance() {
  // Since it's a static variable, if the class has already been created,
  // it won't be created again.
  // And it **is** thread-safe in C++11.
  static Logger lInstance;

  // Return a reference to our instance.
  return lInstance;
}

/**
 * @brief Logger::log
 * @param pFileName
 * @param pLevel
 * @param pMessage
 */
void Logger::log(const QString& pFileName, const Level& pLevel, const QString& pMessage) {
    QMutexLocker locker(&mMutex);

    try {
        // If the file is called for the first time
        if (!mFileList.contains(pFileName)) {
            // Open it and insert its instance in array
            mFileList.insert(pFileName, openFile(pFileName, Extension::LOG));
        }

        // Build the message
        QString lMessageBuilder(QString("[%1](%2)\t%3\n")
                .arg(DATE_TIME_TO_STRING)
                .arg(LevelName[pLevel])
                .arg(pMessage));

        // Copy the message in the file
        QFile* lFile = mFileList.value(pFileName);
        if (nullptr != lFile) {
            lFile->write(lMessageBuilder.toUtf8());
        } else {
            // Pointer is not valid; throw an exception
            throw QString("/!\\ WARNING - Can't write message in %1 stream buffer\n%2")
                    .arg(pFileName)
                    .arg(lMessageBuilder);
        }

        // When the file is bigger than max size
        if (lFile->size() / LOG_FILE_MAX_SIZE) {
            // Copy content in backup file
            backupFile(lFile, pFileName);
        }
    } catch (QString msg) {
        qDebug() << DATE_TIME_TO_STRING << msg;
    }
}

/**
 * @brief Logger::getFilePath
 * @param pFileName
 * @param pExtension
 * @return
 */
QString Logger::getFilePath(const QString& pFileName, Extension pExtension) const {
    // Format the destination log file path
    return QString("%1/" LOG_DIRECTORY "%2.%3")
            .arg(QDir::currentPath())
            .arg(pFileName)
            .arg(EnumToString(Extension, pExtension));
}

/**
 * @brief Logger::openFile
 * @param pFileName
 * @param pExtension
 * @return
 */
QFile* Logger::openFile(const QString& pFileName, Extension pExtension) noexcept(false) {
    QFile* lFile = new QFile(getFilePath(pFileName, pExtension));
    if (!lFile->open(QIODevice::WriteOnly | QIODevice::Append | QIODevice::Text)) {
        throw QString(" /!\\ WARNING - Can't open %1 file").arg(lFile->fileName());
    }
    return lFile;
}

/**
 * @brief Logger::backupFile
 * @param pFile
 * @param pFileName
 */
void Logger::backupFile(QFile* pFile, const QString& pFileName) noexcept(false) {
    // Destroy the previous saved file
    QFile lSavFile(getFilePath(pFileName, Extension::SAV));
    if (lSavFile.exists()) lSavFile.remove();
    lSavFile.close();

    // Rename the current log file
    pFile->rename(getFilePath(pFileName, Extension::SAV));
    pFile->close();

    // Inject a clean file in array
    mFileList.insert(pFileName, openFile(pFileName, Extension::LOG));
}
