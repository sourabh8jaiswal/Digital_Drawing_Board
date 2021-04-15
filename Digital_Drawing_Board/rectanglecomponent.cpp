#include "rectanglecomponent.h"
#include<QDebug>

int RectangleComponent::getX() const
{
    return X;
}

void RectangleComponent::setX(int value)
{
    X = value;
}

int RectangleComponent::getY() const
{
    return Y;
}

void RectangleComponent::setY(int value)
{
    Y = value;
}

int RectangleComponent::getWidth() const
{
    return width;
}

void RectangleComponent::setWidth(int value)
{
    width = value;
}

int RectangleComponent::getHeight() const
{
    return height;
}

void RectangleComponent::setHeight(int value)
{
    height = value;
}


void RectangleComponent::draw(QPainter *painter)
{
    /*
      QPen pen;
    if(penWidth!=0)
    {

        pen.setWidth(penWidth);
        if(this->penColor!="")
        {
            if(this->penColor=="green") pen.setColor(Qt::green);
            if(this->penColor=="red") pen.setColor(Qt::red);
            if(this->penColor=="black") pen.setColor(Qt::black);
            if(this->penColor=="blue") pen.setColor(Qt::blue);
            if(this->penColor=="gray") pen.setColor(Qt::gray);
            if(this->penColor=="yellow") pen.setColor(Qt::yellow);
        }
        painter->setPen(pen);
    }
*/
    QPen pen;
    pen.setWidth(penWidth);
    pen.setColor(penColor);
    painter->setPen(pen);
    painter->drawRect(this->X,this->Y,this->width,this->height);
}

int RectangleComponent::getPenWidth() const
{
    return penWidth;
}

void RectangleComponent::setPenWidth(int value)
{
    penWidth = value;
}

bool RectangleComponent::isOwnedByYou(int a, int b)
{
    if(a>=X && a<=X+width && b>=Y && b<=Y+height) return true;
    return false;
}

void RectangleComponent::Select(QPainter *painter)
{
    QPen pen;

    pen.setColor(Qt::red);
    pen.setWidth(penWidth+6);
    painter->setPen(pen);
    painter->drawPoint(X,Y);
    painter->drawPoint(X+width,Y);
    painter->drawPoint(X,Y+height);
    painter->drawPoint(X+width,Y+height);
    painter->drawPoint(X+(width/2),Y);
    painter->drawPoint(X+(width/2),Y+height);

}

QString RectangleComponent::toString()
{
    return "Rectangle";
}

void RectangleComponent::setPenColor(QColor value)
{
    this->penColor=value;
}

void RectangleComponent::setHoldPoints(int x, int y)
{
    this->holdX=x;
    this->holdY=y;
    gapX=holdX-this->X;
    gapY=holdY-this->Y;

}

void RectangleComponent::move(int a, int b)
{
    this->X=a-gapX;
    this->Y=b-gapY;
}

void RectangleComponent::resize(int x, int y)
{
    int px=this->X-x;
    int py=this->Y-y;
    this->setX(x);
    this->setY(y);
    this->width+=px;
    this->height+=py;
}


RectangleComponent::RectangleComponent()
{
    this->X=0;
    this->Y=0;
    this->width=0;
    this->height=0;
    this->penWidth=0;
    this->penColor="";
}

RectangleComponent::RectangleComponent(int X, int Y, int width, int height)
{
    this->X=X;
    this->Y=Y;
    this->width=width;
    this->height=height;
}
