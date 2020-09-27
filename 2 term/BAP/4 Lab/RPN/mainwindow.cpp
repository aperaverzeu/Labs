#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QPixmap bkgnd("/Users/Alex/Documents/Education/Labs/2 term/BAP/fourth/RPN/background/art gray and black artwork.jpg");
    bkgnd = bkgnd.scaled(this->size(), Qt::IgnoreAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Background, bkgnd);
    this->setPalette(palette);
}

MainWindow::~MainWindow()
{
    delete ui;
}


int MainWindow::precedence(QChar x)
{
    if (x == ')') return 1;
    if (x == '+'||x == '-') return 2;
    if (x == '*'||x == '/') return 3;
    if (x == '(') return 4;
    return 0;
}

bool MainWindow::isOperator(const QString& input)
{
    QString ops[] = {"-", "+", "*", "/", "(", ")"};
    for (int i = 0; i < 6; i++) {
        if  (input == ops[i]) return true;
    }
    return false;
}

QString MainWindow::infToPsf(QString infix)
{
    std::stack<QChar> s;
    QString postfix;
    for (auto c : infix) {
        if (!isOperator(c)) {
            postfix += c;
        }
        else if (isOperator(c)) {
            while (!s.empty() && precedence(s.top()) >= precedence(c) && s.top() != '(' && s.top() != ')') {
                postfix += s.top();
                s.pop();
            }
            s.push(c);
            if (!s.empty() && s.top() == ')') {
                s.pop();
                if (s.empty() || s.top() != '(') return "Error!";
                s.pop();
            }
        }
        else {
            return "Error!";
        }
    }
    while (!s.empty()){
        if (s.top() == '(' || s.top() == ')') return "Error!";
        postfix += s.top();
        s.pop();
    }
    return postfix;
}

double MainWindow::solvePostfix(QString s, double a, double b, double c, double d, double e)
{
    std::stack<double> num;
    for (QChar ch: s){
        if (ch >= 'a' && ch <= 'e'){
            if (ch == 'a') num.push(a);
            else if (ch == 'b') num.push(b);
            else if (ch == 'c') num.push(c);
            else if (ch == 'd') num.push(d);
            else num.push(e);
        }
        else {
            double x, y;
            y = num.top(); num.pop();
            x = num.top(); num.pop();
            if (ch == '+') num.push(x + y);
            else if (ch == '-') num.push(x - y);
            else if (ch == '*') num.push(x * y);
            else num.push(x / y);
        }
    }
    return num.top();
}


void MainWindow::on_pushButton_clicked()
{
    QString s = infToPsf(ui->lineEditInf->text());
    if (ui->lineEditInf->text() == "") {
        QMessageBox::information(this, "", "Error!\nType someething!");
        return;
    }
    ui->lineEditPsf->setText(s);
    if (s == "Error!") ui->lineEditResult->setText("Error!");
    else ui->lineEditResult->setText(QString::number(solvePostfix(s,
                                                        ui->lineEditA->text().toDouble(),
                                                        ui->lineEditB->text().toDouble(),
                                                        ui->lineEditC->text().toDouble(),
                                                        ui->lineEditD->text().toDouble(),
                                                        ui->lineEditE->text().toDouble())));
}
