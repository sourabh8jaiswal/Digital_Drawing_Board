#include "tmview.h"

TMView::TMView()
{
    this->list=new QList<DrawableComponent *>();
}

void TMView::add(DrawableComponent *dc)
{
    this->list->push_back(dc);
}

void TMView::processClick(int x, int y, QPainter *painter)
{
    DrawableComponent *dr;
    for(int i=0;i<list->size();i++)
    {
      dr=list->at(i);
      if(dr->isOwnedByYou(x,y)) dr->Select(painter);
    }
}

void TMView::draw(QPainter *painter)
{
    int i=0;
    while (i<list->size()) {
        DrawableComponent *drawableComponent=NULL;
        drawableComponent=list->at(i);
        if(drawableComponent!=NULL)
        {
        drawableComponent->draw(painter);
        }
        i++;
    }
}

void TMView::clearList()
{
    DrawableComponent *drawableComponent;
    for(int i=0;i<list->size();i++)
    {
        drawableComponent=list->at(i);
        free(drawableComponent);
    }
    list->clear();
}

void TMView::remove(DrawableComponent *dc)
{
    this->list->removeOne(dc);
}

void TMView::remove()
{
    this->list->removeAt(list->size()-1);
}

QList<DrawableComponent *> *TMView::getList()
{
    return this->list;
}

DrawableComponent *TMView::getComponent(int x, int y)
{
    DrawableComponent *dr;
    for(int i=0;i<list->size();i++)
    {
      dr=list->at(i);
      if(dr->isOwnedByYou(x,y)) return dr;
    }
    return nullptr;
}
