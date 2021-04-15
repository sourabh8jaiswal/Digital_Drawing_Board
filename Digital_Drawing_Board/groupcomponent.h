#ifndef GROUPCOMPONENT_H
#define GROUPCOMPONENT_H

#include<DrawableComponent.h>

class GroupComponent:public DrawableComponent
{
private:
    QList<DrawableComponent *> *list;
    QColor penColor;
    int penWidth;
    int holdX;
    int holdY;
public:
    GroupComponent(QList<DrawableComponent *> *list);
    QList<DrawableComponent *> * getList();
    int getSize();
    virtual void draw(QPainter *)override;
    virtual bool isOwnedByYou(int,int)override;
    virtual void Select(QPainter *)override;
    virtual QString toString()override;
    int getPenWidth() const;
    void setPenWidth(int value)override;
    virtual void setPenColor(QColor value) override;
    virtual void setHoldPoints(int, int) override;
    virtual void move(int, int) override;
    virtual void resize(int, int) override;
};

#endif // GROUPCOMPONENT_H
