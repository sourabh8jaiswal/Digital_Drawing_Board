#include "groupcomponent.h"


int GroupComponent::getPenWidth() const
{
    return penWidth;
}

void GroupComponent::setPenWidth(int value)
{
    penWidth = value;
}

void GroupComponent::setPenColor(QColor value)
{
    this->penColor=value;
}

void GroupComponent::setHoldPoints(int x, int y)
{
    DrawableComponent *d;
    for(int i=0;i<list->size();i++)
    {
    d=list->at(i);
    d->setHoldPoints(x,y);
    }
}

void GroupComponent::move(int x, int y)
{
    DrawableComponent *d;
    for(int i=0;i<list->size();i++)
    {
        d=list->at(i);
        d->move(x,y);
    }
}

void GroupComponent::resize(int, int)
{
    //some code
}


GroupComponent::GroupComponent(QList<DrawableComponent *> *list)
{
    this->list=list;
}

QList<DrawableComponent *> * GroupComponent::getList()
{
    return this->list;
}

int GroupComponent::getSize()
{
    return this->list->size();
}

void GroupComponent::draw(QPainter *painter)
{
    for(int i=0;i<list->size();i++)
    {
        list->at(i)->draw(painter);
    }
}

bool GroupComponent::isOwnedByYou(int a, int b)
{
    bool found=false;
for(int i=0;i<list->size();i++)
{
    found=list->at(i)->isOwnedByYou(a,b);
    if(found) break;
}
return found;
}

void GroupComponent::Select(QPainter *painter)
{
for(int i=0;i<list->size();i++)
{
    list->at(i)->Select(painter);
}
}

QString GroupComponent::toString()
{
return "Group";
}
