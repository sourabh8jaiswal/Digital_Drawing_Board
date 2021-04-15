#include "ellipsecomponent.h"
#include<math.h>
int EllipseComponent::getCenterX() const
{
    return centerX;
}

void EllipseComponent::setCenterX(int value)
{
    centerX = value;
}

int EllipseComponent::getCenterY() const
{
    return centerY;
}

void EllipseComponent::setCenterY(int value)
{
    centerY = value;
}

int EllipseComponent::getRadius() const
{
    return radius;
}

void EllipseComponent::setRadius(int value)
{
    radius = value;
}

void EllipseComponent::draw(QPainter *painter)
{
    QPen pen;
    pen.setWidth(penWidth);
    pen.setColor(penColor);
    painter->setPen(pen);
    painter->drawEllipse(QPoint(centerX,centerY),radius,radius);
}

bool EllipseComponent::isOwnedByYou(int a, int b)
{
    int radsq=radius*radius;
    if((pow((centerX-a),2)+pow((centerY-b),2))<=radsq) return true;
    return false;
}

void EllipseComponent::Select(QPainter *painter)
{
    QPen pen;
    pen.setWidth(penWidth+6);
    pen.setColor(Qt::blue);
    painter->setPen(pen);
    painter->drawPoint(centerX+radius,centerY);
    painter->drawPoint(centerX-radius,centerY);
    painter->drawPoint(centerX,centerY+radius);
    painter->drawPoint(centerX,centerY-radius);
}

QString EllipseComponent::toString()
{
return "Circle";
}


int EllipseComponent::getPenWidth() const
{
    return penWidth;
}

void EllipseComponent::setPenWidth(int value)
{
    penWidth = value;
}

void EllipseComponent::setPenColor(QColor value)
{
    this->penColor=value;
}

void EllipseComponent::setHoldPoints(int x, int y)
{
    this->holdX=x;
    this->holdY=y;
    gapX=holdX-centerX;
    gapY=holdY-centerY;

}

void EllipseComponent::move(int x, int y)
{
    this->centerX=x-gapX;
    this->centerY=y-gapY;

}

void EllipseComponent::resize(int p, int q)
{
    int rad=sqrt(pow(p-centerX,2)+pow(q-centerY,2));
    this->radius=rad;
}


EllipseComponent::EllipseComponent()
{
    this->centerX=0;
    this->centerY=0;
    this->radius=0;
    
}

EllipseComponent::EllipseComponent(int centerX, int centerY, int radius)
{
    this->centerX=centerX;
    this->centerY=centerY;
    this->radius=radius;
}
