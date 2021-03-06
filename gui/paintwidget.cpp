#include "paintwidget.h"

#include <QPainter>
#include <iostream>

PaintWidget::PaintWidget(QWidget *parent) :
	QWidget(parent),image(300,300,QImage::Format_RGB32),color(Qt::black),penWidth(1)
{
    fillImage(Qt::white);
}

void PaintWidget::setImage(const QImage &img){
    image=img.copy();
    update();
}

QImage PaintWidget::getImage(){
    return image;
}

void PaintWidget::fillImage(QColor color){
#if QT_VERSION < 0x040800
    image.fill(color.rgba());
#else
    image.fill(color);
#endif
    update();
}

void PaintWidget::mouseMoveEvent(QMouseEvent *event)
{
    QPainter p(&image);
    p.setPen(color);
    p.setBrush(color);
    if(penWidth==1){
        p.drawPoint(event->pos());
    }else{
        p.drawEllipse(event->pos(),penWidth/2,penWidth/2);
    }
    // trigger repaint of widget
    update();
}

void PaintWidget::mouseReleaseEvent(QMouseEvent *event){
    std::cout<<"PaintWidgte::mouseReleseEvent()"<<std::endl;
    emit haveUpdate();
}

void PaintWidget::paintEvent(QPaintEvent *event)
{
    QPainter p(this);
    p.drawImage(0,0,image);
}
