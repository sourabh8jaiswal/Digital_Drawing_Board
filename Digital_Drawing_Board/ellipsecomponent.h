#ifndef ELLIPSECOMPONENT_H
#define ELLIPSECOMPONENT_H
#include<DrawableComponent.h>

class EllipseComponent:public DrawableComponent
{
private:
    int centerX;
    int centerY;
    int radius;
    QColor penColor;
    int penWidth;
    int holdX;
    int holdY;
    int gapX;
    int gapY;
public:
    EllipseComponent();
    EllipseComponent(int centerX,int centerY,int radius);
    int getCenterX() const;
    void setCenterX(int value);
    int getCenterY() const;
    void setCenterY(int value);
    int getRadius() const;
    void setRadius(int value);
    void draw(QPainter *) override;
    virtual bool isOwnedByYou(int,int) override;
    virtual void Select(QPainter *) override;
    virtual QString toString() override;
    int getPenWidth() const;
    void setPenWidth(int value)override;
    virtual void setPenColor(QColor value) override;
    virtual void setHoldPoints(int x,int y) override;
    virtual void move(int x, int y) override;
    virtual void resize(int, int) override;
};

#endif // ELLIPSECOMPONENT_H
