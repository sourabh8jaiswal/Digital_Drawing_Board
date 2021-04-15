#ifndef RECTANGLECOMPONENT_H
#define RECTANGLECOMPONENT_H
#include"DrawableComponent.h"

class RectangleComponent:public DrawableComponent
{
private:
    int X;
    int Y;
    int width;
    int height;
    QColor penColor;
    int penWidth;
    int holdX;
    int holdY;
    int gapX;
    int gapY;
public:
    RectangleComponent();
    RectangleComponent(int X,int Y,int width,int height);
    int getX() const;
    void setX(int value);
    int getY() const;
    void setY(int value);
    int getWidth() const;
    void setWidth(int value);
    int getHeight() const;
    void setHeight(int value);


    void draw(QPainter *) override;
    int getPenWidth() const;
    void setPenWidth(int value)override;

    bool isOwnedByYou(int,int)override;
    void Select(QPainter *)override;
    virtual QString toString() override;
    virtual void setPenColor(QColor value) override;
    virtual void setHoldPoints(int, int) override;
    virtual void move(int, int) override;
    virtual void resize(int, int) override;
};

#endif // RECTANGLECOMPONENT_H
