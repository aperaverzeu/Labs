#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->textEdit->setReadOnly(true);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::write(Auto* *a, int size)
{
    ui->textEdit->clear();
    for (int i = 0; i < size; i++) {
        Auto *msch = a[i];
        ui->textEdit->append(QString::number(i + 1) + ". " +
                                                msch->country + "\n     " +
                                                msch->mark + "\n     " +
                                                msch->motorType + "\n     " +
                                                QString::number(msch->price) + " $\n     " +
                                                QString::number(msch->eating) + "  per litre\n     " +
                                                QString::number(msch->durability) + "  years\n     " +
                                                QString::number(msch->convenience) + " point\n     ");
        }
}

void MainWindow::on_comboBoxCountry_currentTextChanged(const QString &arg1)
{
    if (arg1 == "Belarus") {
        ui->comboBoxMark->clear();
        ui->comboBoxMark->addItem("MAZ");
    }
    else if (arg1 == "Germany") {
        ui->comboBoxMark->clear();
        ui->comboBoxMark->addItem("MAN");
        ui->comboBoxMark->addItem("Boar");
    }
    else if (arg1 == "USA") {
        ui->comboBoxMark->clear();
        ui->comboBoxMark->addItem("Cat");
    }
}


void MainWindow::on_btnOpen_clicked()
{
    file_name = QFileDialog::getOpenFileName(this, "",
                                                         "/Users/Alex/Documents/Education/Labs/2 term/BAP/second/DiskShop/DiskShop/database/",
                                                         "Text file (*.txt)");

    QFile file(file_name);
    file.open(QFile::ReadOnly);

    QTextStream in(&file);
    int n = in.readLine().toInt();
    size = n;
    for (int i = 0; i < n; i++)  {
        in.readLine();
        QString country = in.readLine();
        QString mark = in.readLine();
        QString motorType = in.readLine();
        int price = in.readLine().toInt();
        int eating = in.readLine().toInt();
        int durability = in.readLine().toInt();
        int convenience = in.readLine().toInt();

        Auto *msch = new Auto(country, mark, motorType, price, eating, durability, convenience);
        a[i] = msch;
        }

        file.close();
        write(a, size);
}

void MainWindow::on_btnSave_clicked()
{
    QFile file(file_name);
    file.open(QFile::WriteOnly);
    QTextStream out(&file);
    out << size << '\n';
    for (int i = 0; i < size; i++) {
        Auto *msch = a[i];
        out << '\n';
        out << msch->country << '\n';
        out << msch->mark << '\n';
        out << msch->motorType << '\n';
        out << msch->price << '\n';
        out << msch->eating << '\n';
        out << msch->durability << '\n';
        out << msch->convenience << '\n';
        }
        file.close();
}

void MainWindow::on_btnAdd_clicked()
{
    QString country = ui->comboBoxCountry->currentText();
    if (country == "") return;
    QString mark = ui->comboBoxMark->currentText();
    if (mark == "") return;
    QString motorType = ui->comboBoxMotorType->currentText();
    if (motorType == "") return;
    int price = ui->comboBoxPrice->currentText().toInt();
    if (price == 0) return;
    int eating = ui->lineEditEat->text().toInt();
    if (eating == 0) return;
    int durability = ui->lineEditDur->text().toInt();
    if (durability == 0) return;
    int convenience = ui->lineEditCon->text().toInt();
    if (convenience == 0) return;

    Auto *msch = new Auto(country, mark, motorType, price, eating, durability, convenience);
    a[size] = msch;
    size++;
    write(a, size);
}

void MainWindow::on_btnShow_clicked()
{
    write(a, size);
}

void MainWindow::on_btnSearch_clicked()
{
    int tsize = 0;
    Auto* *ta= new Auto*[10000];

    QString country = ui->comboBoxCountry->currentText();
    on_comboBoxCountry_currentTextChanged(country);
    QString mark = ui->comboBoxMark->currentText();
    QString motorType = ui->comboBoxMotorType->currentText();
    int price = ui->comboBoxPrice->currentText().toInt();
    int eating = ui->lineEditEat->text().toInt();
    int durability = ui->lineEditDur->text().toInt();
    int convenience = ui->lineEditCon->text().toInt();


    for (int i = 0; i < size; i++) {
        Auto *msch = a[i];
        if ((country == "" || country == msch->country) &&
                (mark == "" || mark == msch->mark) &&
                (motorType == "" || motorType == msch->motorType) &&
                (price == 0 || price >= msch->price) &&
                (eating == 0 || eating == msch->eating) &&
                (durability == 0 || durability == msch->durability) &&
                (convenience == 0 || convenience == msch->convenience) ) {
                    ta[tsize] = a[i];
                    tsize++;
        }
    }
    write(ta, tsize);
}

void MainWindow::on_btnSort_clicked()
{
    std::sort(a, a + size, [](Auto* a, Auto* b) {
        if (a->country == b->country) return a->mark < b->mark;
        return a->country < b->country;
        }
    );
    write(a, size);
}

void MainWindow::on_btnDelete_clicked()
{
    int tsize = 0;
    Auto* *ta= new Auto*[10000];

    QString country = ui->comboBoxCountry->currentText();
    QString mark = ui->comboBoxMark->currentText();
    QString motorType = ui->comboBoxMotorType->currentText();
    int price = ui->comboBoxPrice->currentText().toInt();
    int eating = ui->lineEditEat->text().toInt();
    int durability = ui->lineEditDur->text().toInt();
    int convenience = ui->lineEditCon->text().toInt();

    for (int i = 0; i < size; i++) {
        Auto *msch = a[i];
        if (!((country == "" || country == msch->country) &&
                (mark == "" || mark == msch->mark) &&
                (motorType == "" || motorType == msch->motorType) &&
                (price == 0 || price == msch->price) &&
                (eating == 0 || eating == msch->eating) &&
                (durability == 0 || durability == msch->durability) &&
                (convenience == 0 || convenience == msch->convenience))) {
                    ta[tsize] = a[i];
                    tsize++;
        }
    }
    delete[] ta;
    a = ta;
    size = tsize;
    write(a, size);
}
