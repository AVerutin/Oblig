#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    testDb();
}

MainWindow::~MainWindow()
{
}


/// Тестирование API БД
void MainWindow::testDb()
{
    Oblig oblig;
    oblig.setCode("RU000A1008D7");
    oblig.setName("РЖД 1P-14R");
    oblig.setNominal(1000);
    oblig.setRate(8.4);
    oblig.setCash(20.94);
    // oblig.setPeriod(81);
    oblig.setPeriodCount(2);
    oblig.setStartDate(QDate(2020, 10, 13));
    oblig.setFinishDate(QDate(2029, 05, 04));
    oblig.setPrice(120.31);

    int daysRemains = oblig.daysRemains();
    int paymentsRemains = oblig.paymentsRemains();
    double nkd = oblig.nkd();

    // Database *sdb = new Database();
    // sdb->add(oblig);
    // delete sdb;
}

