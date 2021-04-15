#include "imagecomponent.h"

int ImageComponent::getX() const
{
    return x;
}

void ImageComponent::setX(int value)
{
    x = value;
}

int ImageComponent::getY() const
{
    return y;
}

void ImageComponent::setY(int value)
{
    y = value;
}

int ImageComponent::getWidth() const
{
    return width;
}

void ImageComponent::setWidth(int value)
{
    width = value;
}

int ImageComponent::getHeight() const
{
    return height;
}

void ImageComponent::setHeight(int value)
{
    height = value;
}

QString ImageComponent::getFilename() const
{
    return filename;
}

void ImageComponent::setFilename(const QString &value)
{
    filename = value;
}

QPixmap *ImageComponent::getPixmap() const
{
    return pixmap;
}

void ImageComponent::setPixmap(QPixmap *value)
{
    pixmap = value;
}

void ImageComponent::resize(int p, int q)
{
    int px=this->x-p;
    int py=this->y-q;
    this->setX(p);
    this->setY(q);
    this->width+=px;
    this->height+=py;
}

ImageComponent::ImageComponent()
{
    this->x=0;
    this->y=0;
    this->width=0;
    this->height=0;
    this->filename="";
    this->pixmap=nullptr;
}

ImageComponent::ImageComponent(int x, int y, int width, int height, QString filename)
{
    this->x=x;
    this->y=y;
    this->width=width;
    this->height=height;
    this->filename=filename;
    this->pixmap=new QPixmap(filename);

}

void ImageComponent::draw(QPainter *painter)
{
    painter->drawPixmap(QRect(x,y,width,height),*pixmap);
}

bool ImageComponent::isOwnedByYou(int a, int b)
{
    if(a>=x && a<=x+width && b>=y && b<=y+height) return true;
    return false;
}

void ImageComponent::Select(QPainter *painter)
{
    QPen pen;

    pen.setColor(Qt::red);
    pen.setWidth(7);
    painter->setPen(pen);
    painter->drawPoint(x,y);
    painter->drawPoint(x+width,y);
    painter->drawPoint(x,y+height);
    painter->drawPoint(x+width,y+height);

}

QString ImageComponent::toString()
{
    return QString("Image");
}

void ImageComponent::setPenWidth(int)
{

}

void ImageComponent::setPenColor(QColor value)
{

}

void ImageComponent::setHoldPoints(int x, int y)
{
    this->holdX=x;
    this->holdY=y;
    gapX=holdX-this->x;
    gapY=holdY-this->y;

}

void ImageComponent::move(int a, int b)
{
    this->x=a-gapX;
    this->y=b-gapY;
}
