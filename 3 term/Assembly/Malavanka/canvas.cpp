#include "canvas.h"
#include "size.h"

Canvas::Canvas(MainWindow *p) : QWidget() {
    parent = p;

    xMax = 750;
    yMax = 750;
    label = new QLabel(this);
    pixmapList.push_back(new QPixmap(xMax,yMax));
    pixActual = pixmapList.size()-1;
    pixmapList[pixActual]->fill();
    painter = new QPainter(pixmapList[pixActual]);

    label->setPixmap(*pixmapList[pixActual]);
}

void Canvas::paintEvent(QPaintEvent *event) {}

void Canvas::mouseMoveEvent(QMouseEvent *event) {
    if(parent->getDrawEnable()) {
        xMove = event->pos().x();
        yMove = event->pos().y();
        draw();
    }
    if(parent->getRectangleEnable()) {
        xMove = event->pos().x();
        yMove = event->pos().y();
        drawTempRectangle();
    }
    if(parent->getCircleEnable()) {
            xMove = event->pos().x();
            yMove = event->pos().y();
            drawTempCircle();
    }
    if(parent->getLineEnable()) {
            xMove = event->pos().x();
            yMove = event->pos().y();
            drawTempLine();
    }
}

void Canvas::mousePressEvent(QMouseEvent* event) {
    if(parent->getRectangleEnable()||parent->getCircleEnable() || parent->getFillEnable()|| parent->getLineEnable()) {
        xPress = event->pos().x();
        yPress = event->pos().y();
    }
    if(parent->getDrawEnable()) {
        pixmapList.push_back(new QPixmap(xMax,yMax));
        pixActual++;
        pixmapList[pixActual]->operator =(*pixmapList[pixActual-1]);
        painter->end();
        delete painter;
        painter = new QPainter(pixmapList[pixActual]);
    }
    if(parent->getDrawEnable()){
        xPress = event->pos().x();
        yPress = event->pos().y();
        path = new QPainterPath(QPointF(xPress,yPress));
        path->moveTo(xPress,yPress);
   }

}

void Canvas::mouseReleaseEvent(QMouseEvent *event) {
    if(parent->getRectangleEnable()) {
            xRelease = event->pos().x();
            yRelease = event->pos().y();
            drawRectangle();

    }
    if(parent->getCircleEnable()) {
            xRelease = event->pos().x();
            yRelease = event->pos().y();
            drawCircle();

    }
    if(parent->getLineEnable()) {
            xRelease = event->pos().x();
            yRelease = event->pos().y();
            drawLine();

    }
    if(parent->getFillEnable()) {
            xRelease = event->pos().x();
            yRelease = event->pos().y();
            fill();
    }
    if(parent->getDrawEnable()) {
        delete path;
    }
}

void Canvas::draw() {
    QPen pen;

    path->lineTo(xMove,yMove);
    pen.setColor(parent->getColor());
    pen.setWidth(parent->getValueSlider());
    painter->setPen(pen);
    painter->setRenderHint(QPainter::Antialiasing);
    painter->drawPath(*path);

    label->setPixmap(*pixmapList[pixActual]);
}

void Canvas::drawRectangle() {
    QPen pen;
    pen.setColor(parent->getColor());
    pen.setWidth(parent->getValueSlider());

    pixmapList.push_back(new QPixmap(xMax,yMax));
    pixActual++;
    pixmapList[pixActual]->operator =(*pixmapList[pixActual-1]);
    painter->end();
    delete painter;
    painter = new QPainter(pixmapList[pixActual]);

    painter->setPen(pen);
    painter->drawRect(xPress,yPress,xRelease-xPress,yRelease-yPress);

    label->setPixmap(*pixmapList[pixActual]);
}

void Canvas::drawTempRectangle() {
    QPen pen;
    pen.setColor(parent->getColor());
    pen.setWidth(parent->getValueSlider());

    pixmapList.push_back(new QPixmap(xMax,yMax));
    pixActual++;
    pixmapList[pixActual]->operator =(*pixmapList[pixActual-1]);
    painter->end();
    delete painter;
    painter = new QPainter(pixmapList[pixActual]);

    painter->setPen(pen);
    painter->drawRect(xPress,yPress,xMove-xPress,yMove-yPress);
    label->setPixmap(*pixmapList[pixActual]);
    pixmapList.remove(pixActual);
    pixActual = pixmapList.size()-1;
}

void Canvas::drawCircle() {
    QPen pen;
    pen.setColor(parent->getColor());
    pen.setWidth(parent->getValueSlider());

    pixmapList.push_back(new QPixmap(xMax,yMax));
    pixActual++;
    pixmapList[pixActual]->operator =(*pixmapList[pixActual-1]);
    painter->end();
    delete painter;
    painter = new QPainter(pixmapList[pixActual]);

    painter->setPen(pen);
    painter->drawEllipse(xPress,yPress,xRelease-xPress,yRelease-yPress);
    label->setPixmap(*pixmapList[pixActual]);
}

void Canvas::drawTempCircle() {
    QPen pen;
    pen.setColor(parent->getColor());
    pen.setWidth(parent->getValueSlider());

    pixmapList.push_back(new QPixmap(xMax,yMax));
    pixActual++;
    pixmapList[pixActual]->operator =(*pixmapList[pixActual-1]);
    painter->end();
    delete painter;
    painter = new QPainter(pixmapList[pixActual]);

    painter->setPen(pen);
    painter->drawEllipse(xPress,yPress,xMove-xPress,yMove-yPress);
    label->setPixmap(*pixmapList[pixActual]);
    pixmapList.remove(pixActual);
    pixActual = pixmapList.size()-1;
}

void Canvas::drawLine() {
    QPen pen;
    pen.setColor(parent->getColor());
    pen.setWidth(parent->getValueSlider());

    pixmapList.push_back(new QPixmap(xMax,yMax));
    pixActual++;
    pixmapList[pixActual]->operator =(*pixmapList[pixActual-1]);
    painter->end();
    delete painter;
    painter = new QPainter(pixmapList[pixActual]);

    painter->setPen(pen);
    painter->drawLine(xPress,yPress,xRelease,yRelease);
    label->setPixmap(*pixmapList[pixActual]);
}

void Canvas::drawTempLine() {
    QPen pen;
    pen.setColor(parent->getColor());
    pen.setWidth(parent->getValueSlider());

    pixmapList.push_back(new QPixmap(xMax,yMax));
    pixActual++;
    pixmapList[pixActual]->operator =(*pixmapList[pixActual-1]);
    painter->end();
    delete painter;
    painter = new QPainter(pixmapList[pixActual]);

    painter->setPen(pen);
    painter->drawLine(xPress,yPress,xMove,yMove);
    label->setPixmap(*pixmapList[pixActual]);
    pixmapList.remove(pixActual);
    pixActual = pixmapList.size()-1;
}

void Canvas::fill() {
    painter->end();
    delete painter;
    QRgb colTarget,colRep;

    pixmapList.push_back(new QPixmap(xMax,yMax));
    pixActual++;
    pixmapList[pixActual]->operator =(*pixmapList[pixActual-1]);

    image = new QImage(xMax,yMax,QImage::Format_RGB32);
    *image = pixmapList[pixActual]->toImage();
    colTarget = image->pixel(xPress,yPress);
    colRep = parent->getColor().rgb();
    filling4(xPress,yPress,colTarget,colRep);

    pixmapList[pixActual]->convertFromImage(*image);
    painter = new QPainter(pixmapList[pixActual]);

    delete image;

    label->setPixmap(*pixmapList[pixActual]);
}

int Canvas::filling4(int x, int y,QRgb coltarget, QRgb colrep) {
    int a,b,i;
    int lastPosition;
    QVector<Pile *> listPosition;

    if (image->pixel(x,y) != coltarget) {
            return 1;
    }
    if (x < 0 || y < 0 || x > (xMax-1) || y > (yMax-1) || coltarget == colrep) {
            return 0;
    }

    listPosition.push_back(new Pile(x,y));

    while (listPosition.empty()==0) {
        a = listPosition[listPosition.size()-1]->getX();
        b = listPosition[listPosition.size()-1]->getY();

        if (a == 1 || b == 1 || a == (xMax-1) || b == (yMax-1)) {
            for (i = 0 ;i < xMax; i++) {
                image->setPixel(i, 0, colrep);
                image->setPixel(i, yMax-1, colrep);
            }
            for (i = 0;i < yMax; i++) {
                image->setPixel(0, i, colrep);
                image->setPixel(xMax-1, i, colrep);
            }
        }
        lastPosition = listPosition.size()-1;
        listPosition.remove(lastPosition);

        image->setPixel(a, b, colrep);

        if (image->pixel(a, b-1) == coltarget) {
            listPosition.push_back(new Pile(a, b-1));
        }
        if (image->pixel(a, b+1) == coltarget) {
            listPosition.push_back(new Pile(a, b+1));
        }
        if (image->pixel(a+1, b) == coltarget) {
            listPosition.push_back(new Pile(a+1, b));
        }
        if (image->pixel(a-1, b) == coltarget) {
            listPosition.push_back(new Pile(a-1, b));
        }
    }
    return 1;
}

void Canvas::saveCanvas() {
    QString fichier = QFileDialog::getSaveFileName(0, "Save image", QString(), "Images (*.png *.gif *.jpg *.jpeg)");
    pixmapList[pixActual]->save(fichier);
}

void Canvas::openCanvas() {
    QString fichier = QFileDialog::getOpenFileName(0,"Open image",QString(),"Images (*.png *.gif *.jpg *.jpeg)");
    painter->end();
    delete painter;
    pixmapList.remove(pixActual);
    pixmapList.push_back(new QPixmap(fichier));
    painter = new QPainter(pixmapList[pixActual]);
    label->setPixmap(*pixmapList[pixActual]);
}

void Canvas::newCanvas() {
    painter->end();
    delete painter;
    pixmapList.erase(pixmapList.begin(), pixmapList.end());
    delete label;
    xMax = Size::getLength();
    yMax = Size::getHeight();

    pixmapList.push_back(new QPixmap(xMax,yMax));
    pixActual = pixmapList.size()-1;
    pixmapList[pixActual]->fill();

    label = new QLabel(this);
    label->setPixmap(*pixmapList[pixActual]);
    label->show();
    painter = new QPainter(pixmapList[pixActual]);
}

void Canvas::returnCanvas() {
    if(pixActual == 0) return;
    pixmapList.remove(pixActual);
    pixActual = pixmapList.size()-1;
    painter->end();
    delete painter;
    painter = new QPainter(pixmapList[pixActual]);
    label->setPixmap(*pixmapList[pixActual]);
}
