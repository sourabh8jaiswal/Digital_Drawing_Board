#include "linecomponent.h"
#include<math.h>
#include<QPen>
int LineComponent::getStartX() const
{
    return startX;
}

void LineComponent::setStartX(int value)
{
    startX = value;
}

int LineComponent::getStartY() const
{
    return startY;
}

void LineComponent::setStartY(int value)
{
    startY = value;
}

int LineComponent::getEndX() const
{
    return endX;
}

void LineComponent::setEndX(int value)
{
    endX = value;
}

int LineComponent::getEndY() const
{
    return endY;
}

void LineComponent::setEndY(int value)
{
    endY = value;
}

int LineComponent::getPenWidth() const
{
    return penWidth;
}

void LineComponent::setPenWidth(int value)
{
    penWidth = value;
}

void LineComponent::draw(QPainter *painter)
{
/*
    if(penWidth!=0)
    {
        QPen pen;
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
    painter->drawLine(this->startX,this->startY,this->endX,this->endY);

}

bool LineComponent::isOwnedByYou(int p, int q)
{
    int dist1=sqrt(pow(p-startX,2)+pow(q-startY,2));
    int dist2=sqrt(pow(endX-p,2)+pow(endY-q,2));
    int dist=dist1+dist2;
    int actual_dist=sqrt(pow(endX-startX,2)+pow(endY-startY,2));
    if(dist==actual_dist) return true;

    return false;
}

void LineComponent::Select(QPainter *painter)
{
    QPen pen;
    pen.setWidth(penWidth+6);
    pen.setColor(Qt::red);
    painter->setPen(pen);
    painter->drawPoint(startX,startY);
    painter->drawPoint(endX,endY);
}

QString LineComponent::toString()
{
    return "Line";
}

void LineComponent::setPenColor(QColor value)
{
    this->penColor=value;
}

void LineComponent::setHoldPoints(int x, int y)
{
    this->holdX=x;
    this->holdY=y;
    gapX=holdX-startX;
    gapY=holdY-startY;

}

void LineComponent::move(int x, int y)
{
    /*
    int xx=lc->getEndX()-lc->getStartX();
    int yy=lc->getEndY()-lc->getStartY();
    lc->setStartX(currentX-gapX);
    lc->setStartY(currentY-gapY);
    lc->setEndX(currentX-gapX+x);
    lc->setEndY(currentY-gapY+y);
    */
    int xx=endX-startX;
    int yy=endY-startY;
    startX=x-gapX;
    startY=y-gapY;
    endX=x-gapX+xx;
    endY=y-gapY+yy;

}

void LineComponent::resize(int p, int q)
{
    this->startX=p;
    this->startY=q;

}

LineComponent::LineComponent(int startX, int startY, int endX, int endY)
{
    this->startX=startX;
    this->startY=startY;
    this->endX=endX;
    this->endY=endY;
}

LineComponent::LineComponent()
{
    this->startX=0;
    this->startY=0;
    this->endX=0;
    this->endY=0;
    this->penWidth=0;
    this->penColor="";
}
