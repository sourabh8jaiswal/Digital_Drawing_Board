#ifndef LINECOMPONENT_H
#define LINECOMPONENT_H
#include<QString>
#include<DrawableComponent.h>
class LineComponent:public DrawableComponent
{
private:
    int startX;
    int startY;
    int endX;
    int endY;
    QColor penColor;
    int penWidth;
    int holdX;
    int holdY;
    int gapX;
    int gapY;
public:
    LineComponent(int startX,int startY,int endX,int endY);
    LineComponent();
    int getStartX() const;
    void setStartX(int value);
    int getStartY() const;
    void setStartY(int value);
    int getEndX() const;
    void setEndX(int value);
    int getEndY() const;
    void setEndY(int value);
    int getPenWidth() const;
    void setPenWidth(int value)override;
    void draw(QPainter *) override;
    virtual bool isOwnedByYou(int,int) override;
    virtual void Select(QPainter *)override;
    virtual QString toString() override;
    virtual void setPenColor(QColor value) override;
    virtual void setHoldPoints(int, int) override;
    virtual void move(int, int) override;
    virtual void resize(int, int) override;
};

#endif // LINECOMPONENT_H
