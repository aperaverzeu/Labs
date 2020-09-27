#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->lineEditSearchValue->setReadOnly(true);
        QPixmap bkgnd("/Users/Alex/Desktop/luke-chesser-B_oL3jEt5L4-unsplash.jpg");
        bkgnd = bkgnd.scaled(this->size(), Qt::IgnoreAspectRatio);
        QPalette palette;
        palette.setBrush(QPalette::Background, bkgnd);
        this->setPalette(palette);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::printTable()
{
    ui->textEdit->setText(HT->printTable());
}

void MainWindow::on_btnAdd_clicked()
{
    int key = ui->lineEditInsertKey->text().toInt();
    QString value = ui->lineEditInsertValue->text();
    if (key == 0 || value == "") {
        QMessageBox::information(this, "", "Error!\nPlease type something…");
        return;
    }
    HT->insertItem(key, value);
    printTable();
}

void MainWindow::on_btnSearch_clicked()
{
    int key = ui->lineEditSearchKey->text().toInt();
    if (key == 0) {
        QMessageBox::information(this, "", "Error!\nPlease type something…");
        return;
    }

    QString value = HT->searchItem(key);
    if (value == "[WARNING] Key not found") {
        QMessageBox::information(this, "", "Error!\nSorry, this element doensn't exist…");
        return;
    }
    ui->lineEditSearchValue->setText(value);
    printTable();
}

void MainWindow::on_bntDelete_clicked()
{
    int key = ui->lineEditDeleteKey->text().toInt();
    if (key == 0) {
        QMessageBox::information(this, "", "Error!\nPlease type something…");
        return;
    }
    HT->removeItem(key);
    printTable();
}

void MainWindow::on_btnPlus_clicked()
{
    ui->tableWidget->setRowCount(ui->tableWidget->rowCount() + 1);
    ui->tableWidget->setItem(ui->tableWidget->rowCount() - 1, 0, new QTableWidgetItem());
    ui->tableWidget->setItem(ui->tableWidget->rowCount() - 1, 1, new QTableWidgetItem());
}

void MainWindow::on_btnMinus_clicked()
{
    ui->tableWidget->setRowCount(ui->tableWidget->rowCount() - 1);
}

void MainWindow::on_bntAddInfo_clicked()
{
    HT->clear();
        for (int i = 0; i < ui->tableWidget->rowCount(); i++) {
            int key = ui->tableWidget->item(i,0)->text().toInt();
            QString value = ui->tableWidget->item(i,1)->text();
            HT->insertItem(key, value);
        }
        printTable();
}

void MainWindow::on_BtnDeleteInfo_clicked()
{
    HT->clear();
    printTable();
}

void MainWindow::on_btnClear_clicked()
{
    ui->textEdit->clear();
}

void MainWindow::on_btnShow_clicked()
{
    printTable();
}

void MainWindow::on_bntTask_clicked()
{
    int amount = ui->lineEditCreateHashTableAmount->text().toInt();
    if (amount == 0) {
        QMessageBox::information(this, "", "Error!\nType something…");
        return;
    } else if (amount <= 0) {
        QMessageBox::information(this, "", "Error!\nOnly Positive values…");
        return;
    }
    ui->lineEditTask->setText(QString::number(HT->findBigger(amount)));
}

void MainWindow::on_bntCreateHashTable_clicked()
{
    int amount, from, to;
    amount = ui->lineEditCreateHashTableAmount->text().toInt();
    from = ui->lineEditCreateHashTableFrom->text().toInt();
    to = ui->lineEditCreateHashTableTo->text().toInt();
    if (amount == 0 || from == 0 || to == 0) {
        QMessageBox::information(this, "", "Error!\nType something…");
        return;
    }
    if (amount <= 0 || from <= 0 || to <= 0) {
        QMessageBox::information(this, "", "Error!\nOnly Positive values…");
        return;
    }
    HT = new HashTable();
    for (int i = 0; i < amount; i++) {
        int key = rand() % (to - from + 1) + from;
        QString value;
        value += (char)('a' + i % 26);
        value += (char)('a' + i % 26);
        value += (char)('a' + i % 26);
        value += (char)('a' + i % 26);
        HT->insertItem(key, value);
    }
    printTable();
}
