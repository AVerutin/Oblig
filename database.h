#ifndef DATABASE_H
#define DATABASE_H

#include <QtSql>
#include <QList>
#include <QString>
#include "logger.h"
#include "oblig.h"

class Database
{
public:
    Database();
    ~Database();
    int add(const Oblig&);
    const QList<Oblig> getAll();
    const Oblig getByCode(const QString&);
    const Oblig getByName(const QString&);

private:
    QSqlDatabase sdb;
    QSqlQuery *query;
    QString unitName;
    Logger *logger;

    void dbInit();
    void dbClose();
};

#endif // DATABASE_H
