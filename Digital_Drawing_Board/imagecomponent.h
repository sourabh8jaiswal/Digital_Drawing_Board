#ifndef IMAGECOMPONENT_H
#define IMAGECOMPONENT_H
#include<DrawableComponent.h>

class ImageComponent:public DrawableComponent
{
private:
    int x;
    int y;
    int width;
    int height;
    QString filename;
    QPixmap *pixmap;
    int holdX;
    int holdY;
    int gapX;
    int gapY;
public:
    ImageComponent();
    ImageComponent(int,int,int,int,QString);
    virtual void draw(QPainter *)override;
    virtual bool isOwnedByYou(int,int)override;
    virtual void Select(QPainter *)override;
    virtual QString toString()override;
    virtual void setPenWidth(int)override;
    virtual void setPenColor(QColor value)override;
    virtual void setHoldPoints(int,int)override;
    virtual void move(int,int)override;
    int getX() const;
    void setX(int value);
    int getY() const;
    void setY(int value);
    int getWidth() const;
    void setWidth(int value);
    int getHeight() const;
    void setHeight(int value);
    QString getFilename() const;
    void setFilename(const QString &value);
    QPixmap *getPixmap() const;
    void setPixmap(QPixmap *value);
    virtual void resize(int, int) override;
};

#endif // IMAGECOMPONENT_H
