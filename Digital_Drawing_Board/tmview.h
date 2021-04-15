#ifndef TMVIEW_H
#define TMVIEW_H
#include<QList>
#include<DrawableComponent.h>

class TMView
{
private:
    QList<DrawableComponent *> *list;
public:
    TMView();
    void add(DrawableComponent *);
    void processClick(int x,int y,QPainter *);
    void draw(QPainter *);
    void clearList();
    void remove(DrawableComponent *);
    void remove();
    QList<DrawableComponent *> * getList();
    DrawableComponent * getComponent(int x,int y);
};

#endif // TMVIEW_H
