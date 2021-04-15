#ifndef DRAWABLECOMPONENT_H
#define DRAWABLECOMPONENT_H
#include<QPainter>
class DrawableComponent
{
public:
    virtual void draw(QPainter *)=0;
    virtual bool isOwnedByYou(int,int)=0;
    virtual void Select(QPainter *)=0;
    virtual QString toString()=0;
    virtual void setPenWidth(int)=0;
    virtual void setPenColor(QColor value)=0;
    virtual void setHoldPoints(int,int)=0;
    virtual void move(int,int)=0;
    virtual void resize(int,int)=0;
};

#endif // DRAWABLECOMPONENT_H
