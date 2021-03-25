#include "oblig.h"


/// Конструктор по-умолчанию
Oblig::Oblig()
{
    this->_code = "";
    this->_name = "";
    this->_nominal = 1000;
    this->_rate = 0;
    this->_cash = 0;
    this->_period = 0;
    this->_start.setDate(1970, 1, 1);
    this->_finish.setDate(1970, 1, 1);
    this->_price = 0;
}


/// Установить код ISIN
void Oblig::setCode(const QString &code)
{
    if (code.length() >0)
        this->_code = code;
}


/// Получить код ISIN
QString Oblig::code() const
{
    return this->_code;
}


/// Установить наименование бумаги
void Oblig::setName(const QString &name)
{
    if (name.length() >0)
        this->_name = name;
}


/// Получить наименование бумаги
QString Oblig::name() const
{
    return this->_name;
}


/// Установить номинальную стоимость бумаги
void Oblig::setNominal(int nom)
{
    if (nom >0 )
        this->_nominal = nom;
}


/// Получить номинальную стоимость бумаги
int Oblig::nominal() const
{
    return this->_nominal;
}


/// Установить процентную ставку бумаги
void Oblig::setRate(double rate)
{
    if (rate >0)
        this->_rate = rate;
}


/// Получить процентную ставку бумаги
double Oblig::rate() const
{
    return this->_rate;
}


/// Установить сумму купона
void Oblig::setCash(double cash)
{
    if (cash >0)
        this->_cash = cash;
}


/// Получить сумму купона
double Oblig::cash() const
{
    return this->_cash;
}


/// Установить период выплат купонов в днях
void Oblig::setPeriod(int period)
{
    if (period >0)
        this->_period = period;
}


/// Установить количество выплат купонов в год
void Oblig::setPeriodCount(int count)
{
    this->_period = qFloor(365/count);
}


/// Получить период выплат купонов в днях
int Oblig::period() const
{
    return this->_period;
}


/// Установить дату эмиссии
void Oblig::setStartDate(const QDate &start)
{
    if (start.isValid())
        this->_start = start;
}


/// Получить дату эмиссии
QDate Oblig::startDate() const
{
    return this->_start;
}


/// Установить дату погашения
void Oblig::setFinishDate(const QDate &finish)
{
    if (finish.isValid())
        this->_finish = finish;
}


/// Получить дату погашения
QDate Oblig::finishDate() const
{
    return this->_finish;
}


/// Установить цену покупки
void Oblig::setPrice(double price)
{
    if (price >0)
        this->_price = price;
}


/// Получить цену покупки
double Oblig::price() const
{
    return this->_price;
}



/// Получить количество дней до погашения бумаги
int Oblig::daysRemains() const
{
    int result = QDate::currentDate().daysTo(this->finishDate());
    return result;
}


/// Получить количество оставшихся выплат купонов
int Oblig::paymentsRemains() const
{
    int result = qFloor(daysRemains()/period());

    return result;
}


/// Расчет накопленного купонного дохода
double Oblig::nkd()
{
    // Найти сколько дней осталось до следующей выплаты купона
    QDate nextDate = this->_start;
    QDate prevDate;
    QDate today = QDate::currentDate();

    do
    {
        prevDate = nextDate;
        nextDate = nextDate.addDays(this->_period);
    } while (nextDate < today);

    int days = this->_period - today.daysTo(nextDate);

    // умножить на размер купона за 1 день
    double dayCost = this->_cash / this->_period;
    double result = dayCost * days;

    return result;
}


