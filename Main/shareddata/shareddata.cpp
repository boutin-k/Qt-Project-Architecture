#include <QMutexLocker>
#include "shareddata.h"

SharedData& SharedData::Instance() {
  // Since it's a static variable, if the class has already been created,
  // it won't be created again.
  // And it **is** thread-safe in C++11.
  static SharedData lInstance;

  // Return a reference to our instance.
  return lInstance;
}

void SharedData::getSharedData(quint32 pId, QVariant& pOutValue) const {
    QMutexLocker locker(&mMutex);
    if (mSharedData.contains(pId)) {
        pOutValue = mSharedData.value(pId, pOutValue);
    }
}

void SharedData::setSharedData(quint32 pId, QVariant pValue) {
    QMutexLocker locker(&mMutex);
    mSharedData.insert(pId, pValue);
}
