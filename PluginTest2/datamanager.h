#ifndef DATAMANAGER_H
#define DATAMANAGER_H

#include <QObject>
#include <QMutexLocker>

#define THREAD_SAFE_DECL(V, T, D)               \
    public:                                     \
        inline void set_##V(T P) {              \
            QMutexLocker locker(&mutex_##V);    \
            this->V = P;                        \
        }                                       \
        inline T get_##V() const {              \
            QMutexLocker locker(&mutex_##V);    \
            return V;                           \
        }                                       \
    private:                                    \
        T V = D;                                \
        mutable QMutex mutex_##V


class DataManager : public QObject
{
    Q_OBJECT
public:
    explicit DataManager(QObject *parent = nullptr);

private:
    THREAD_SAFE_DECL(value, int, 0);
    THREAD_SAFE_DECL(name, QString, "");
};

#endif // DATAMANAGER_H
