#ifndef SIZE_H
#define SIZE_H

#include <QtWidgets>
#include <canvas.h>

class Size : public QWidget {
    Q_OBJECT

public:
    Size(Canvas *canvas);
    static int getLength();
    static int getHeight();

public slots:
    void createClick();
    void getLengthLine(QString lLine);
    void getHeightLine(QString hLine);

private:
    static int length;
    static int height;
    QLineEdit *lengthLine;
    QLineEdit *heightLine;
    QPushButton *create;
};

#endif // SIZE_H
