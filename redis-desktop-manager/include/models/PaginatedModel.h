#pragma once

#include <QStringList>
#include "KeyModel.h"

class PaginatedModel : public KeyModel
{
    Q_OBJECT

public:
    PaginatedModel(ConnectionBridge * db, const QString &keyName, int dbIndex);

    virtual ~PaginatedModel();

    virtual int getCurrentPage();

    virtual void setCurrentPage(int) = 0;

    virtual int itemsCount();

    virtual int getPagesCount();
    static void delayedDeallocator(QObject *);
protected:
    int currentPage;
    QVector<QString> * rawData;

    static const int itemsOnPageLimit = 500;

    void initModel(const QVariant &);    
};

