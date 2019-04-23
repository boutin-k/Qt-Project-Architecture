#ifndef SHAREDDATA_H
#define SHAREDDATA_H

#include <QObject>
#include <QVariant>
#include <QMutex>
#include <QMap>

class SharedData
{
public:
    static SharedData& Instance();

    void getSharedData(quint32 pKey, QVariant& pOutValue) const;
    void setSharedData(quint32 pKey, QVariant pValue);

private:
    explicit SharedData(void) {}
    ~SharedData(void) {}

private:
    QMap<quint32, QVariant> mSharedData;
    mutable QMutex          mMutex;
};

#endif // SHAREDDATA_H
