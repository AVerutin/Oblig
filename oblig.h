#ifndef OBLIG_H
#define OBLIG_H

#include <QDate>
#include <QString>
#include <QtMath>

class Oblig
{
public:
    Oblig();
    void setCode(const QString&);
    QString code() const;
    void setName(const QString&);
    QString name() const;
    void setNominal(int);
    int nominal() const;
    void setRate(double);
    double rate() const;
    void setCash(double);
    double cash() const;
    void setPeriod(int);
    void setPeriodCount(int);
    int period() const;
    void setStartDate(const QDate&);
    QDate startDate() const;
    void setFinishDate(const QDate&);
    QDate finishDate() const;
    void setPrice(double);
    double price() const;

    int daysRemains() const;
    int paymentsRemains() const;
    double nkd();

private:
    QString _code;
    QString _name;
    int _nominal;
    double _rate;
    double _cash;
    int _period;
    QDate _start;
    QDate _finish;
    double _price;
};

#endif // OBLIG_H
