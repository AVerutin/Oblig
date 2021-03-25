#include "database.h"

Database::Database()
{
    logger = new Logger;
    unitName = typeid(this).name();
    dbInit();
}

Database::~Database()
{
    dbClose();
}


/// Сохранить облигацию в базу данных
int Database::add(const Oblig &oblig)
{
    QString queryStr = "INSERT INTO 'oblig' ('code', 'name', 'nominal', 'rate', 'cash', 'period', 'start', 'finish') "
        "VALUES ('%1', '%2', %3, %4, %5, %6, '%7', '%8');";
    queryStr = queryStr.arg(oblig.code(), oblig.name(), QString::number(oblig.nominal()));
    queryStr = queryStr.arg(QString::number(oblig.rate()), QString::number(oblig.cash()), QString::number(oblig.period()));
    queryStr = queryStr.arg(oblig.startDate().toString(Qt::ISODate), oblig.finishDate().toString(Qt::ISODate));

    bool res = query->exec(queryStr);
    if (!res)
    {
        QString msg = "Не удалось добавить облигацию [%1] %2";
        msg = msg.arg(oblig.code(), oblig.name());
        logger->error(msg, unitName);
    }

    int result = query->lastInsertId().toInt();
    return result;
}


/// Получить список всех облигаций
const QList<Oblig> Database::getAll()
{

}


/// Получить облигацию по коду
const Oblig Database::getByCode(const QString &)
{

}


/// Получить облигацию по наименованию
const Oblig Database::getByName(const QString &)
{

}


void Database::dbInit()
{
    sdb = QSqlDatabase::addDatabase("QSQLITE");
    QString dbPath = QCoreApplication::applicationDirPath() + "/data.db";
    sdb.setDatabaseName(dbPath);
    query = new QSqlQuery(sdb);

    // Подключение к базе данных
    if (!sdb.open())
    {
          logger->error(sdb.lastError().text(), unitName);
    }
    else
    {
        /////////// DDL query ///////////
        QString str = "CREATE TABLE IF NOT EXISTS `oblig` ("
            "`id` INTEGER NOT NULL, "
            "`code` TEXT NOT NULL, "
            "`name` TEXT NOT NULL, "
            "`nominal` INTEGER NOT NULL, "
            "`rate` REAL NOT NULL, "
            "`cash` REAL NOT NULL, "
            "`period` INTEGER NOT NULL, "
            "`start` TEXT NOT NULL, "
            "`finish` TEXT NOT NULL, "
            "PRIMARY KEY(`id` AUTOINCREMENT)"
        ");";

        bool b = query->exec(str);
        if (!b)
        {
            logger->error(query->lastError().text(), unitName);
        }
    }
}


void Database::dbClose()
{
    sdb.close();
}

