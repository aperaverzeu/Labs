#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

int MainWindow::checkNum(QString str)
{
    if (str == "") return 0;
    for (int i = 0; i < str.length(); i++) {
        if (str[i] < '0' || str[i] > '9') {
            return -1;
        }
    }
    int num = str.toInt();
    if (num <= 0) return -1;
    return num;
}


void MainWindow::on_btnPlus_clicked()
{
    ui->tableWidget->setRowCount(ui->tableWidget->rowCount() + 1);
    ui->tableWidget->setItem(ui->tableWidget->rowCount() - 1, 0, new QTableWidgetItem());
    ui->tableWidget->setItem(ui->tableWidget->rowCount() - 1, 1, new QTableWidgetItem());
    ui->tableWidget->setItem(ui->tableWidget->rowCount() - 1, 2, new QTableWidgetItem());
    ui->tableWidget->setItem(ui->tableWidget->rowCount() - 1, 3, new QTableWidgetItem());
    ui->tableWidget->setItem(ui->tableWidget->rowCount() - 1, 4, new QTableWidgetItem());
    ui->tableWidget->setItem(ui->tableWidget->rowCount() - 1, 5, new QTableWidgetItem());
    ui->tableWidget->setItem(ui->tableWidget->rowCount() - 1, 6, new QTableWidgetItem());
}

void MainWindow::on_btnMinus_clicked()
{
    ui->tableWidget->setRowCount(ui->tableWidget->rowCount() - 1);
}

void MainWindow::on_btnInitialize_clicked()
{
    try {
    for (int i = 0; i < ui->tableWidget->rowCount(); i++) {
        QString name, surname;
        QString city, street, house;
        int markMath, markPhys, markLang;
        double averageMark;
        name = ui->tableWidget->item(i,0)->text();
        surname = ui->tableWidget->item(i,1)->text();
        city = ui->tableWidget->item(i,2)->text();
        street = ui->tableWidget->item(i,3)->text();
        house = ui->tableWidget->item(i,4)->text();
        markMath = ui->tableWidget->item(i,5)->text().toInt();
        markPhys = ui->tableWidget->item(i,6)->text().toInt();
        markLang = ui->tableWidget->item(i,7)->text().toInt();
        averageMark = (markMath+markPhys+markLang)/3.0;
        list.add(new Info(name, surname, city, street, house, markMath, markPhys, markLang, averageMark));
    }
    ui->textEdit->setText(list.output());
    } catch (...) {
        QMessageBox::information(this, "", "Error!\nUnexpected mistake!\n");
    }
}

void MainWindow::on_btnShow_clicked()
{
    ui->textEdit->setText(list.output());
}

void MainWindow::on_btnClear_clicked()
{
    ui->textEdit->clear();
}

void MainWindow::on_btnAdd_clicked()
{
    QString name, surname;
    QString city, street, house;
    int markMath, markPhys, markLang;
    double averageMark;
    surname = ui->lineEditSurname->text();
    if  (surname == "")  {
        QMessageBox::information(this, "","Error!\nType something");
        return;
    }
    name = ui->lineEditName->text();
    if  (name == "")  {
        QMessageBox::information(this, "","Error!\nType something");
        return;
    }
    city = ui->lineEditCity->text();
    if  (city == "") {
        QMessageBox::information(this, "","Error!\nType something");
        return;
    }
    street = ui->lineEditStreet->text();
    if  (street == "")  {
        QMessageBox::information(this, "","Error!\nType something");
        return;
    }
    house = ui->lineEditHouse->text();
    if  (house == "")  {
        QMessageBox::information(this, "","Error!\nType something");
        return;
    }
    markMath = checkNum(ui->lineEditMarkMath->text());
    if (markMath == -1) {
        QMessageBox::information(this, "","Error!\nMarks can be only positive");
        return;
    }
    markPhys = checkNum(ui->lineEditMarkPhys->text());
    if (markPhys == -1) {
        QMessageBox::information(this, "","Error!\nMarks can be only positive");
        return;
    }
    markLang = checkNum(ui->lineEditMarkLang->text());
    if (markLang == -1) {
        QMessageBox::information(this, "","Error!\nMarks can be only positive");
        return;
    }
    averageMark = (double)(markMath+markPhys+markLang)/3.0;
    list.add(new Info(name, surname, city, street, house, markMath, markPhys, markLang, averageMark));
    ui->textEdit->setText(list.output());
}

void MainWindow::on_btnSearch_clicked()
{
    QString name, surname;
    QString city, street, house;
    int markMath, markPhys, markLang;
    double averageMark;
    surname = ui->lineEditSurname->text();
    name = ui->lineEditName->text();
    city = ui->lineEditCity->text();
    street = ui->lineEditStreet->text();
    house = ui->lineEditHouse->text();
    markMath = checkNum(ui->lineEditMarkMath->text());
    markPhys = checkNum(ui->lineEditMarkPhys->text());
    markLang = checkNum(ui->lineEditMarkLang->text());
    averageMark = checkNum(ui->lineEditAMark->text());
    if (surname == "" && name == "" && city == "" && street == "" && house == "" && markMath == 0 && markPhys == 0 && markLang == 0 && averageMark == 0 ) {
        QMessageBox::information(this, "","Error!\nType something");
        return;
    }
    if (surname != "") {
        ui->textEdit->setText("Surname:\t" + surname + "\n" + list.find(Info(name, surname, city, street, house, markMath, markPhys, markLang, averageMark)));
        return;
    }
    ui->textEdit->setText(list.find(Info(name, surname, city, street, house, markMath, markPhys, markLang, averageMark)));
}

void MainWindow::on_btnDelete_clicked()
{
    QString name, surname;
    QString city, street, house;
    int markMath, markPhys, markLang;
    double averageMark;
    surname = ui->lineEditSurname->text();
    if  (surname == "")  {
        QMessageBox::information(this, "","Error!\nType something");
        return;
    }
    name = ui->lineEditName->text();
    if  (name == "")  {
        QMessageBox::information(this, "","Error!\nType something");
        return;
    }
    city = ui->lineEditCity->text();
    if  (city == "") {
        QMessageBox::information(this, "","Error!\nType something");
        return;
    }
    street = ui->lineEditStreet->text();
    if  (street == "")  {
        QMessageBox::information(this, "","Error!\nType something");
        return;
    }
    house = ui->lineEditHouse->text();
    if  (house == "")  {
        QMessageBox::information(this, "","Error!\nType something");
        return;
    }
    markMath = checkNum(ui->lineEditMarkMath->text());
    if (markMath == -1) {
        QMessageBox::information(this, "","Error!\nMarks can be only positive");
        return;
    }
    markPhys = checkNum(ui->lineEditMarkPhys->text());
    if (markPhys == -1) {
        QMessageBox::information(this, "","Error!\nMarks can be only positive");
        return;
    }
    markLang = checkNum(ui->lineEditMarkLang->text());
    if (markLang == -1) {
        QMessageBox::information(this, "","Error!\nMarks can be only positive");
        return;
    }
    averageMark = ui->lineEditAMark->text().toDouble();
    list.remove(Info(name, surname, city, street, house, markMath, markPhys, markLang, averageMark));
    ui->textEdit->setText(list.output());
}
