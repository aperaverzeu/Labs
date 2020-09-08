#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setFixedSize(1280, 720);
    QPixmap bkgnd("/Users/Alex/Documents/Личное/Мои Данные/Обои/books spine.jpg");
    bkgnd = bkgnd.scaled(this->size(), Qt::IgnoreAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Background, bkgnd);
    this->setPalette(palette);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_btnEditUserInfo_clicked()
{
    QVector<QString> user;
    user.clear();
    QString surname, name;
    QString city, streetHouse, phone;
    QString workplace;
    QDate birthday;

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
    if  (city == "")  {
        QMessageBox::information(this, "","Error!\nType something");
        return;
    }
    streetHouse = ui->lineEditStreet->text();
    if  (streetHouse== "")  {
        QMessageBox::information(this, "","Error!\nType something");
        return;
    }
    phone = ui->lineEditPhone->text();
    if  (phone == "")  {
        QMessageBox::information(this, "","Error!\nType something");
        return;
    }
    workplace = ui->lineEditWorkplace->text();
    if  (workplace == "")  {
        QMessageBox::information(this, "","Error!\nType something");
        return;
    }
    birthday = ui->dateEditBirthday->date();
    if (QDate::isValid(birthday.toString("dd").toInt(), birthday.toString("MM").toInt(), birthday.toString("yyyy").toInt())) {
        QMessageBox::information(this, "","Error!\nWrong date!");
        return;
    }
    user.push_back(surname);
    user.push_back(name);
    user.push_back(city);
    user.push_back(streetHouse);
    user.push_back(phone);
    user.push_back(workplace);
    user.push_back(birthday.toString());
    users.push_back(user);
}

void MainWindow::on_btnShowUserInfo_clicked()
{
    ui->textEditMain->clear();
    QString res;
    for (auto user : users) {
        QString s = "Surname:\t\t" + user[0] +
                                "\nName:\t\t" + user[1] +
                                "\nCity:\t\t" + user[2] +
                                "\nStreet,house:\t" + user[3] +
                                "\nPnone:\t\t" + user[4] +
                                "\nWorkplace:\t\t" + user[5] +
                                "\nBirthday:\t\t" + user[6] +
                                "\n================================\n";
        res += s;
    }
    ui->textEditMain->setText(res);
}

void MainWindow::on_btnAddTask_clicked()
{
    QVector<QString> task;
    QString title, place, comment;
    QTime timeEvent;
    QDate dateEvent;
    title = ui->lineEditTitle->text();
    if  (title == "")  {
        QMessageBox::information(this, "","Error!\nType something");
        return;
    }
    timeEvent = ui->timeEditTask->time();
    dateEvent = ui->dateEditTask->date();
    if (QDate::isValid(dateEvent.toString("dd").toInt(), dateEvent.toString("MM").toInt(), dateEvent.toString("yyyy").toInt())) {
        QMessageBox::information(this, "","Error!\nWrong date!");
        return;
    }
    place = ui->comboBoxTask->currentText();
    comment = ui->textEditTask->toPlainText();
    task.push_back(title);
    task.push_back(timeEvent.toString());
    task.push_back(dateEvent.toString());
    task.push_back(place);
    task.push_back(comment);
    tasks.push_back(task);
}

void MainWindow::on_btnShowAddTask_clicked()
{
    ui->textEditMain->clear();
    QString res, s;
    for (auto task : tasks) {
        s = "Title:\t" + task[0] +
                  "\nTime:\t" + task[1] +
                  "\nDate:\t" + task[2] +
                  "\nPlace:\t" + task[3] +
                  "\nComment:\t" + task[4] +
                  "\n================================\n";
        res += s;
    }
    ui->textEditMain->setText(res);
}

// find and show task by day
void MainWindow::on_bntShowTask_clicked()
{
    QDate findEvent = ui->dateShowTaskByDate->date();
    for (auto task : tasks) {
        if (findEvent.toString() == task[2]) {
            ui->textEditMain->setText("Title:\t" + task[0] +
                                                           "\nTime:\t" + task[1] +
                                                           "\nDate:\t" + task[2] +
                                                           "\nPlace:\t" + task[3] +
                                                           "\nComment:\t" + task[4]);
        }
        else {
            ui->textEditMain->setText("There are no tasks at this date…");
        }
    }
}

// find and show birthday
void MainWindow::on_btnShowBirthday_clicked()
{
    QDate findBirthday = ui->dateShowTaskBirthday->date();
    for (auto user : users) {
        if (findBirthday.day() == QDate::fromString(user[6]).day() && findBirthday.month() == QDate::fromString(user[6]).month()) {
            ui->textEditMain->setText("This day " + QString::number(findBirthday.day()) + "." + QString::number(findBirthday.month()) + " is birthday for " + user[0] + "  " + user[1]);
        } else {
            ui->textEditMain->setText("There are no birthdays at this day");
        }
    }

}
