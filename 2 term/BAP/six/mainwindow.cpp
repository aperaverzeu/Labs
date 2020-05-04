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

void MainWindow::output()
{
    b.output(ui->treeWidget);
}


void MainWindow::on_btnAdd_clicked()
{
    QString key = ui->lineEditInsertKey->text();
    QString value = ui->lineEditInsertValue->text();
    if (key == "" || value == "") {
        QMessageBox::information(this, "", "Error!\nPlease type something…");
        return;
    }
    b.insert(key, value);
    output();
}

void MainWindow::on_btnSearch_clicked()
{
    QString key = ui->lineEditSearchKey->text();
    if (key == "") {
        QMessageBox::information(this, "", "Error!\nPlease type something…");
        return;
    }
    data_s *p = b.get(b.search(key));
    if (p == NULL) {
        QMessageBox::information(this, "", "Error!\nSorry, this element doensn't exist…");
        return;
    }
    ui->lineEditSearchValue->setText(p->value);
    output();
}

void MainWindow::on_bntDelete_clicked()
{
    QString key = ui->lineEditDeleteKey->text();
    if (key == "") {
        QMessageBox::information(this, "", "Error!\nPlease type something…");
        return;
    }
    try {
        b.erase(key);
    } catch (...) {
        QMessageBox::information(this, "", "Error!");
    }

    output();
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
    b.clearD();
        for (int i = 0; i < ui->tableWidget->rowCount(); i++) {
            QString key = ui->tableWidget->item(i,0)->text();
            QString value = ui->tableWidget->item(i,1)->text();
            b.insert(key,value);
        }
        output();
}

void MainWindow::on_BtnDeleteInfo_clicked()
{
    b.clearD();
    output();
}

void MainWindow::on_btnClear_clicked()
{
    ui->treeWidget->clear();
}

void MainWindow::on_btnShow_clicked()
{
    output();
}

void MainWindow::on_btnDeleteMaxBranch_clicked()
{
    b.removeMaxBranch();
//    ui->lineEditSearchValue->setText(b.findMax(b.tree->root));
}
