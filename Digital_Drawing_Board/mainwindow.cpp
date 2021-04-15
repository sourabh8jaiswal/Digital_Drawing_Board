#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<linecomponent.h>
#include<rectanglecomponent.h>
#include<math.h>
#include<ellipsecomponent.h>
#include<QPixmap>
#include<groupcomponent.h>
#include<QFile>
#include<QFileDialog>
#include<QJsonDocument>
#include<QJsonObject>
#include<QJsonArray>
#include<QMessageBox>
#include<QJsonValue>
#include<QDebug>
#include<imagecomponent.h>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->view=new TMView();
    this->ui->sheetButton->setToolTip(QString("Sheet"));
    this->ui->paperButton->setToolTip(QString("Page"));
    this->ui->pickToolButton->setToolTip(QString("Pick Tool"));
    this->ui->rectangleButton->setToolTip(QString("Rectangle"));
    this->ui->circleButton->setToolTip(QString("Circle"));
    this->ui->lineButton->setToolTip(QString("Line"));
    this->ui->freeHandToolButton->setToolTip(QString("Free Hand Tool"));
    this->ui->clearButton->setToolTip(QString("Clear"));
    this->ui->groupButton->setToolTip(QString("Group"));
    this->ui->unGroupButton->setToolTip(QString("Ungroup"));
    this->ui->saveButton->setToolTip(QString("Save"));
    this->ui->openButton->setToolTip(QString("Open"));
    this->ui->imageButton->setToolTip(QString("Image"));
    this->ui->backButton->setToolTip(QString("Back"));
    QPixmap rectanglePixmap(":/images/rectangle.png");
    QPixmap circlePixmap(":/images/circle.png");
    QPixmap freeHandToolPixmap(":/images/pen.png");
    QPixmap linePixmap(":/images/line.png");
    QPixmap pickToolPixmap(":/images/pickTool.png");
    QPixmap clearSheetPixmap(":/images/clearSheet.png");
    QPixmap groupPixmap(":/images/group.png");
    QPixmap unGroupPixmap(":/images/ungroup.png");
    QPixmap savePixmap(":/images/save.png");
    QPixmap openPixmap(":/images/open.png");
    QPixmap sheetPixmap(":/images/blank_page.png");
    QPixmap pagePixmap(":/images/page.png");
    QPixmap imagePixmap(":/images/camera.png");
    QPixmap backPixmap(":/images/back.png");
    QPixmap toolsPixmap(":/images/tools.png");
    QPixmap resizePixmap(":/images/resize.png");
    QPixmap one(":/images/one.png");
    QPixmap two(":/images/two.png");
    QPixmap three(":/images/three.png");
    QPixmap four(":/images/four.png");
    QPixmap five(":/images/five.png");
    QPixmap six(":/images/six.png");
    QPixmap seven(":/images/seven.png");
    QPixmap eight(":/images/eight.png");
    QPixmap nine(":/images/nine.png");
    QPixmap zero(":/images/zero.png");
    QPixmap plus(":/images/plus.png");
    QPixmap minus(":/images/minus.png");
    QPixmap multiply(":/images/multiply.png");
    QPixmap divide(":/images/divide.png");
    QPixmap equal(":/images/equal.png");
    QPixmap root(":/images/root.png");
    QPixmap decimal(":/images/decimal.png");
    QPixmap sigma(":/images/sigma.png");
    QPixmap lineEquation(":/images/lineEquation.png");
    QPixmap circleEquation(":/images/circleEquation.png");
    QPixmap trigonometryFunction(":/images/trigonometryFunctions.png");
    QPixmap trigonometryFunction2(":/images/trigonometryFunctions2.png");
    QPixmap colon(":/images/colon.png");
    QSize size(35,35);
    QSize size2(200,35);
    this->ui->rectangleButton->setIcon(rectanglePixmap);
    this->ui->rectangleButton->setIconSize(size);
    this->ui->circleButton->setIcon(circlePixmap);
    this->ui->circleButton->setIconSize(size);
    this->ui->freeHandToolButton->setIcon(freeHandToolPixmap);
    this->ui->freeHandToolButton->setIconSize(size);
    this->ui->lineButton->setIcon(linePixmap);
    this->ui->lineButton->setIconSize(size);
    this->ui->pickToolButton->setIcon(pickToolPixmap);
    this->ui->pickToolButton->setIconSize(size);
    this->ui->clearButton->setIcon(clearSheetPixmap);
    this->ui->clearButton->setIconSize(size);
    this->ui->groupButton->setIcon(groupPixmap);
    this->ui->groupButton->setIconSize(size);
    this->ui->unGroupButton->setIcon(unGroupPixmap);
    this->ui->unGroupButton->setIconSize(size);
    this->ui->saveButton->setIcon(savePixmap);
    this->ui->saveButton->setIconSize(size);
    this->ui->openButton->setIcon(openPixmap);
    this->ui->openButton->setIconSize(size);
    this->ui->sheetButton->setIcon(sheetPixmap);
    this->ui->sheetButton->setIconSize(size);
    this->ui->paperButton->setIcon(pagePixmap);
    this->ui->paperButton->setIconSize(size);
    this->ui->imageButton->setIcon(imagePixmap);
    this->ui->imageButton->setIconSize(size);
    this->ui->backButton->setIcon(backPixmap);
    this->ui->backButton->setIconSize(size);
    this->ui->toolsButton->setIcon(toolsPixmap);
    this->ui->toolsButton->setIconSize(size);
    this->ui->resizeButton->setIcon(resizePixmap);
    this->ui->resizeButton->setIconSize(size);
    this->ui->one->setIcon(one);
    this->ui->one->setIconSize(size);
    this->ui->two->setIcon(two);
    this->ui->two->setIconSize(size);
    this->ui->three->setIcon(three);
    this->ui->three->setIconSize(size);
    this->ui->four->setIcon(four);
    this->ui->four->setIconSize(size);
    this->ui->five->setIcon(five);
    this->ui->five->setIconSize(size);
    this->ui->six->setIcon(six);
    this->ui->six->setIconSize(size);
    this->ui->seven->setIcon(seven);
    this->ui->seven->setIconSize(size);
    this->ui->eight->setIcon(eight);
    this->ui->eight->setIconSize(size);
    this->ui->nine->setIcon(nine);
    this->ui->nine->setIconSize(size);
    this->ui->zero->setIcon(zero);
    this->ui->zero->setIconSize(size);
    this->ui->plus->setIcon(plus);
    this->ui->plus->setIconSize(size);
    this->ui->minus->setIcon(minus);
    this->ui->minus->setIconSize(size);
    this->ui->multiply->setIcon(multiply);
    this->ui->multiply->setIconSize(size);
    this->ui->divide->setIcon(divide);
    this->ui->divide->setIconSize(size);
    this->ui->equal->setIcon(equal);
    this->ui->equal->setIconSize(size);
    this->ui->root->setIcon(root);
    this->ui->root->setIconSize(size);
    this->ui->decimal->setIcon(decimal);
    this->ui->decimal->setIconSize(size);
    this->ui->colon->setIcon(colon);
    this->ui->colon->setIconSize(size);
    this->ui->sigma->setIcon(sigma);
    this->ui->sigma->setIconSize(size);
    this->ui->lineEquation->setIcon(lineEquation);
    this->ui->lineEquation->setIconSize(size2);
    this->ui->circleEquation->setIcon(circleEquation);
    this->ui->circleEquation->setIconSize(size2);
    this->ui->trigonometryFunction->setIcon(trigonometryFunction);
    this->ui->trigonometryFunction->setIconSize(size2);
    this->ui->trigonometryFunction2->setIcon(trigonometryFunction2);
    this->ui->trigonometryFunction2->setIconSize(size2);
    this->ui->penWidthSlider->setRange(1,10);
    this->ui->penWidthSlider->setCursor(Qt::DragMoveCursor);
    this->penColor.setRgb(2,2,2);
    this->setCursor(QCursor(freeHandToolPixmap,0,freeHandToolPixmap.height()));
    this->ui->toolsFrame->setCursor(Qt::PointingHandCursor);
    this->ui->frame->setCursor(Qt::PointingHandCursor);
    this->ui->menuFrame->setCursor(Qt::PointingHandCursor);
    this->ui->componentStack->setCursor(Qt::ArrowCursor);
    this->ui->menuFrame->setStyleSheet("border: 1px solid white");
    this->ui->toolsFrame->setStyleSheet("background-color: rgb(255,221,207);border: 1px solid black");


}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::paintEvent(QPaintEvent *ev)
{
   QRect windowRect(0,0,this->width(),this->height());
   QColor color(255,221,207);
   QPainter windowPainter(this);
   windowPainter.setBrush(color);
   windowPainter.drawRect(windowRect);
   QPainter painter(this);
   QPen pen;
   pen.setColor(Qt::black);
   pen.setWidth(10);
   painter.setPen(pen);
   painter.eraseRect(183,32,1268,842);
    painter.drawRect(183,32,1268,842);
    pen.setColor(Qt::white);
    pen.setWidth(3);
    painter.setPen(pen);
     painter.drawRect(182,31,1269,843);

    if(flag!=0)
    {
        painter.fillRect(QRect(185,34,1264,838),Qt::white);
        if(paper)
        {
        QPainter painter0(this);
        painter0.setClipRect(185,34,1264,838);
        QPen pen0;
        pen0.setColor(QColor(160,220,255));
        painter0.setPen(pen0);
        int y=0;
        for(int i=0;i<40;i++)
        {
            y=y+35;
            painter0.drawLine(184,y,1450,y);
        }
        }
        QPainter painter3(this);
        painter3.setClipRect(QRect(185,34,1264,838));
        if(strechedLine!=nullptr) strechedLine->draw(&painter3);
        if(strechedRectangle!=nullptr) strechedRectangle->draw(&painter3);
        if(strechedCircle!=nullptr) strechedCircle->draw(&painter3);
        view->draw(&painter3);
    }
    if(processCallingFlag)
    {
        QPainter painter2(this);
        painter2.setClipRect(QRect(185,34,1264,838));
        view->processClick(oldX,oldY,&painter2);
        for(int i=0;i<list->size();i++)
        {
            list->at(i)->Select(&painter2);
        }
    }
    flag++;
}

void MainWindow::mousePressEvent(QMouseEvent *mp)
{
    oldX=mp->x();
    oldY=mp->y();
    if(pickToolSignal==true)
    {
        processCallingFlag=true;
        if(!shiftKeyPressed) component=view->getComponent(oldX,oldY);
        if(component!=NULL)
        {
        component->setHoldPoints(oldX,oldY);
        }
        QPoint point(oldX,oldY);

        DrawableComponent *dc;
        if(ctrlKeyPressed)
        {
            dc=view->getComponent(point.x(),point.y());
            if(dc!=nullptr)
            {
                list->push_back(dc);
            }

           // pointsList.push_back(point);
            QWidget::update();
        }

    }
    if(lineSignal==true)
    {
        strechedLine=new LineComponent(oldX,oldY,oldX,oldY);
        strechedLine->setPenColor(penColor);
        strechedLine->setPenWidth(penWidth);

    }
    if(rectangleSignal)
    {
        strechedRectangle=new RectangleComponent(oldX,oldY,1,1);
        strechedRectangle->setPenColor(penColor);
        strechedRectangle->setPenWidth(penWidth);
    }
    if(circleSignal)
    {
        strechedCircle=new EllipseComponent(oldX,oldY,1);
        strechedCircle->setPenColor(penColor);
        strechedCircle->setPenWidth(penWidth);
    }

QWidget::mousePressEvent(mp);
}

void MainWindow::mouseMoveEvent(QMouseEvent *mm)
{
    if(freeHandToolSignal)
    {
        currentX=mm->x();
        currentY=mm->y();
        DrawableComponent *freeHandToolComponent=new LineComponent(oldX,oldY,currentX,currentY);
        freeHandToolComponent->setPenWidth(penWidth);
        freeHandToolComponent->setPenColor(penColor);
        view->add(freeHandToolComponent);
        QWidget::update();
        oldX=currentX;
        oldY=currentY;
    }
    if(pickToolSignal)
    {

        if(component!=nullptr)
        {
            currentX=mm->x();
            currentY=mm->y();
            if(resizeSignal)
            {
            component->resize(currentX,currentY);
            }
            else
            {
            component->move(currentX,currentY);
            }

            QWidget::update();
        }
    }
    if(lineSignal)
    {
        strechedLine->setEndX(mm->x());
        strechedLine->setEndY(mm->y());
        QWidget::update();
    }
    if(rectangleSignal)
    {
        strechedRectangle->setWidth(mm->x()-strechedRectangle->getX());
        strechedRectangle->setHeight(mm->y()-strechedRectangle->getY());
        QWidget::update();
    }
    if(circleSignal)
    {
        int x=strechedCircle->getCenterX();
        int y=strechedCircle->getCenterY();
        int rad=sqrt(pow(mm->x()-x,2)+pow(mm->y()-y,2));
        strechedCircle->setRadius(rad);
        QWidget::update();
    }
QWidget::mouseMoveEvent(mm);
}

void MainWindow::mouseReleaseEvent(QMouseEvent *mr)
{
    if(lineSignal==true)
    {
    currentX=mr->x();
    currentY=mr->y();
    DrawableComponent *lineComponent=new LineComponent(oldX,oldY,currentX,currentY);
    lineComponent->setPenWidth(penWidth);
    lineComponent->setPenColor(penColor);
    this->ui->componentStack->insertItem(0,lineComponent->toString());
    strechedLine=nullptr;
    view->add(lineComponent);
    }
    if(rectangleSignal==true)
    {
        currentX=mr->x();
        currentY=mr->y();
        int Bx=currentX;
        int By=oldY;
        int width=sqrt(pow((Bx-oldX),2)+pow((By-oldY),2));
        int length=sqrt(pow((currentX-Bx),2)+pow((currentY-By),2));
        DrawableComponent *rectangleComponent=new RectangleComponent(oldX,oldY,width,length);
        rectangleComponent->setPenWidth(penWidth);
        rectangleComponent->setPenColor(penColor);
        this->ui->componentStack->insertItem(0,rectangleComponent->toString());
        strechedRectangle=nullptr;
        view->add(rectangleComponent);
    }
    if(circleSignal==true)
    {
        currentX=mr->x();
        currentY=mr->y();
        int radius=sqrt(pow((currentX-oldX),2)+pow((currentY-oldY),2));
        DrawableComponent *circle=new EllipseComponent(oldX,oldY,radius);
        circle->setPenWidth(penWidth);
        circle->setPenColor(penColor);
        this->ui->componentStack->insertItem(0,circle->toString());
        strechedCircle=nullptr;
        view->add(circle);
    }



    QWidget::update();
    QWidget::mouseReleaseEvent(mr);
}

void MainWindow::keyPressEvent(QKeyEvent *k)
{
    if(k->key()==Qt::Key_Control) ctrlKeyPressed=true;
    if(k->key()==Qt::Key_Shift) shiftKeyPressed=true;
}

void MainWindow::keyReleaseEvent(QKeyEvent *k)
{
    ctrlKeyPressed=false;
    shiftKeyPressed=false;
}

void MainWindow::drawBoardLine(QPainter *p)
{
    int j=0;
 for(int i=0;i<=20;i++)
 {
     j=j+34;
     p->drawLine(130,j,870,j);
 }
}

void MainWindow::on_lineButton_clicked()
{
lineSignal=true;
rectangleSignal=false;
freeHandToolSignal=false;
circleSignal=false;
pickToolSignal=false;
resizeSignal=false;
processCallingFlag=false;

}

void MainWindow::on_rectangleButton_clicked()
{
    lineSignal=false;
    rectangleSignal=true;
    freeHandToolSignal=false;
    circleSignal=false;
    pickToolSignal=false;
    resizeSignal=false;
    processCallingFlag=false;
}

void MainWindow::on_freeHandToolButton_clicked()
{
    lineSignal=false;
    rectangleSignal=false;
    freeHandToolSignal=true;
    circleSignal=false;
    pickToolSignal=false;
    resizeSignal=false;
    processCallingFlag=false;
}

void MainWindow::on_circleButton_clicked()
{
    lineSignal=false;
    rectangleSignal=false;
    freeHandToolSignal=false;
    circleSignal=true;
    pickToolSignal=false;
    resizeSignal=false;
    processCallingFlag=false;
}

void MainWindow::on_pickToolButton_clicked()
{
    lineSignal=false;
    rectangleSignal=false;
    freeHandToolSignal=false;
    circleSignal=false;
    pickToolSignal=true;
    processCallingFlag=false;
    resizeSignal=false;
    list=new QList<DrawableComponent *>();
}

void MainWindow::on_componentStack_clicked(const QModelIndex &index)
{
    qDebug()<<QString::number(index.row());
}

void MainWindow::on_clearButton_clicked()
{
view->clearList();
this->ui->componentStack->clear();
QWidget::update();
}

void MainWindow::on_groupButton_clicked()
{
    GroupComponent *groupComponent=new GroupComponent(list);
    view->add(groupComponent);
    for(int i=0;i<list->size();i++)
    {
        view->remove(list->at(i));
    }
    pickToolSignal=false;
QWidget::update();
}

void MainWindow::on_unGroupButton_clicked()
{
    QString name=component->toString();
    if(name=="Group")
    {
       GroupComponent *group=(GroupComponent *) component;
       QList<DrawableComponent *> *list=group->getList();
       for(int i=0;i<list->size();i++)
       {
           view->add(list->at(i));
       }
       view->remove(group);
       pickToolSignal=true;
       QWidget::update();
    }

}

void MainWindow::on_saveButton_clicked()
{
    QString jsonFilter="JSON(*.json)";
    QString fileName=QFileDialog::getSaveFileName(this,"Open the file","/","JSON(*.json)",&jsonFilter,QFileDialog::DontUseNativeDialog);
    QFile output(fileName);
    if(output.open(QIODevice::WriteOnly|QIODevice::Text))
    {
     QJsonDocument document;
     QList<DrawableComponent *> *list;
     DrawableComponent *d;
     QByteArray data_json;
     QJsonArray listArray;
     list=view->getList();
     for(int i=0;i<list->size();i++)
     {
         d=list->at(i);
         QJsonObject obj;
         if(d->toString()=="Rectangle")
         {
             RectangleComponent *c=(RectangleComponent *)d;
             obj.insert("Name",QJsonValue::fromVariant(c->toString()));
             obj.insert("x",QJsonValue::fromVariant(c->getX()));
             obj.insert("y",QJsonValue::fromVariant(c->getY()));
             obj.insert("width",QJsonValue::fromVariant(c->getWidth()));
             obj.insert("height",QJsonValue::fromVariant(c->getHeight()));
             listArray.push_back(obj);
         }
         if(d->toString()=="Circle")
         {
             EllipseComponent *c=(EllipseComponent *)d;
             obj.insert("Name",QJsonValue::fromVariant(c->toString()));
             obj.insert("centerX",QJsonValue::fromVariant(c->getCenterX()));
             obj.insert("centerY",QJsonValue::fromVariant(c->getCenterY()));
             obj.insert("radius",QJsonValue::fromVariant(c->getRadius()));

             listArray.push_back(obj);
         }
         if(d->toString()=="Line")
         {
             LineComponent *c=(LineComponent *)d;
             obj.insert("Name",QJsonValue::fromVariant(c->toString()));
             obj.insert("startX",QJsonValue::fromVariant(c->getStartX()));
             obj.insert("startY",QJsonValue::fromVariant(c->getStartY()));
             obj.insert("endX",QJsonValue::fromVariant(c->getEndX()));
             obj.insert("endY",QJsonValue::fromVariant(c->getEndY()));
             listArray.push_back(obj);
         }
         if(d->toString()=="Group")
         {
             GroupComponent *c=(GroupComponent *)d;
             DrawableComponent *dc;
             QList<DrawableComponent *> *groupList=c->getList();
             for(int i=0;i<groupList->size();i++)
             {
                 dc=groupList->at(i);
                 if(d->toString()=="Rectangle")
                 {
                     RectangleComponent *c=(RectangleComponent *)dc;
                     obj.insert("Name",QJsonValue::fromVariant(c->toString()));
                     obj.insert("x",QJsonValue::fromVariant(c->getX()));
                     obj.insert("y",QJsonValue::fromVariant(c->getY()));
                     obj.insert("width",QJsonValue::fromVariant(c->getWidth()));
                     obj.insert("height",QJsonValue::fromVariant(c->getHeight()));
                     listArray.push_back(obj);
                 }
                 if(d->toString()=="Circle")
                 {
                     EllipseComponent *c=(EllipseComponent *)dc;
                     obj.insert("Name",QJsonValue::fromVariant(c->toString()));
                     obj.insert("centerX",QJsonValue::fromVariant(c->getCenterX()));
                     obj.insert("centerY",QJsonValue::fromVariant(c->getCenterY()));
                     obj.insert("radius",QJsonValue::fromVariant(c->getRadius()));

                     listArray.push_back(obj);
                 }
                 if(d->toString()=="Line")
                 {
                     LineComponent *c=(LineComponent *)dc;
                     obj.insert("Name",QJsonValue::fromVariant(c->toString()));
                     obj.insert("startX",QJsonValue::fromVariant(c->getStartX()));
                     obj.insert("startY",QJsonValue::fromVariant(c->getStartY()));
                     obj.insert("endX",QJsonValue::fromVariant(c->getEndX()));
                     obj.insert("endY",QJsonValue::fromVariant(c->getEndY()));
                     listArray.push_back(obj);
                 }
             }
         }

     }
     document.setArray(listArray);
     data_json=document.toJson();
     output.write(data_json);
     output.close();
    }else
    {
        QMessageBox::critical(this,tr("Error"),output.errorString());
    }
}

void MainWindow::on_openButton_clicked()
{
    QString jsonFilter="JSON(*.json)";
    QString filename=QFileDialog::getOpenFileName(this,"Open the File","/",tr("All files (*);;%1").arg(jsonFilter),&jsonFilter,QFileDialog::DontUseNativeDialog);
    QFile input(filename);
    if(input.open(QIODevice::ReadOnly|QIODevice::Text))
    {
       QByteArray data_json=input.readAll();
       input.close();
       QJsonDocument document=document.fromJson(data_json);
       QJsonArray jsonArray=document.array();
       for(QJsonValue value:jsonArray)
       {
           QJsonObject obj(value.toObject());
           if(obj.value(QString("Name")).toString()=="Rectangle")
           {
             RectangleComponent *c=new RectangleComponent;
             c->setX(obj["x"].toInt());
             c->setY(obj["y"].toInt());
             c->setWidth(obj["width"].toInt());
             c->setHeight(obj["height"].toInt());
             view->add(c);
           }
           if(obj.value(QString("Name")).toString()=="Circle")
           {
             EllipseComponent *c=new EllipseComponent;
             c->setCenterX(obj["centerX"].toInt());
             c->setCenterY(obj["centerY"].toInt());
             c->setRadius(obj["radius"].toInt());
             view->add(c);
           }
           if(obj.value(QString("Name")).toString()=="Line")
           {
             LineComponent *c=new LineComponent;
             c->setStartX(obj["startX"].toInt());
             c->setStartY(obj["startY"].toInt());
             c->setEndX(obj["endX"].toInt());
             c->setEndY(obj["endY"].toInt());
             view->add(c);
           }
       }
       QWidget::update();

    }else
    {
        QMessageBox::critical(this,tr("Error"),input.errorString());
    }

}

void MainWindow::on_penWidthSlider_valueChanged(int value)
{
    this->penWidth=value;
    this->ui->penWidthLabel->setText(QString::number(penWidth));
}

void MainWindow::on_red_clicked()
{
    this->penColor.setRgb(255,0,0);
    this->ui->choosenColor->setStyleSheet("background-color:red;");
}

void MainWindow::on_green_clicked()
{
    this->penColor.setRgb(0,255,0);
        this->ui->choosenColor->setStyleSheet("background-color:green;");
}

void MainWindow::on_blue_clicked()
{
    this->penColor.setRgb(0,0,255);
        this->ui->choosenColor->setStyleSheet("background-color:blue;");
}

void MainWindow::on_yellow_clicked()
{
    this->penColor.setRgb(255,255,0);
        this->ui->choosenColor->setStyleSheet("background-color:yellow;");
}

void MainWindow::on_orange_clicked()
{
    this->penColor.setRgb(255,85,0);
        this->ui->choosenColor->setStyleSheet("background-color:orange;");
}

void MainWindow::on_pink_clicked()
{
    this->penColor.setRgb(255,0,255);
        this->ui->choosenColor->setStyleSheet("background-color:pink;");
}

void MainWindow::on_white_clicked()
{
    this->penColor.setRgb(255,255,255);
        this->ui->choosenColor->setStyleSheet("background-color:white;");
}

void MainWindow::on_black_clicked()
{
    this->penColor.setRgb(2,2,2);
        this->ui->choosenColor->setStyleSheet("background-color:black;");
}

void MainWindow::on_skyblue_clicked()
{
    this->penColor.setRgb(115,255,251);
        this->ui->choosenColor->setStyleSheet("background-color:skyblue;");
}

void MainWindow::on_sheetButton_clicked()
{
    sheet=true;
    paper=false;
    QWidget::update();

}

void MainWindow::on_paperButton_clicked()
{
    paper=true;
    sheet=false;
    QWidget::update();
}

void MainWindow::on_imageButton_clicked()
{
    QString imageFilter="PNG(*.png)";
    QString filename=QFileDialog::getOpenFileName(this,"Open file","/",tr("All files (*);;%1").arg(imageFilter),&imageFilter,QFileDialog::DontUseNativeDialog);
    DrawableComponent *imageComponent=new ImageComponent((this->width()/2)-(130/2),(this->height()/2)-(130/2),130,130,filename);
    view->add(imageComponent);
    this->ui->componentStack->insertItem(0,imageComponent->toString());
    QWidget::update();
    qDebug()<<filename;
}

void MainWindow::on_backButton_clicked()
{
    view->remove();
    this->ui->componentStack->takeItem(0);
    QWidget::update();
}

void MainWindow::on_toolsButton_clicked()
{
this->ui->toolsFrame->setGeometry(165,500,350,185);
}

void MainWindow::on_toolsFrameCancelButton_clicked()
{
    this->ui->toolsFrame->setGeometry(2000,440,281,141);
}

void MainWindow::on_resizeButton_clicked()
{
    resizeSignal=true;
    lineSignal=false;
    rectangleSignal=false;
    freeHandToolSignal=false;
    circleSignal=false;
    pickToolSignal=true;
    processCallingFlag=false;
}

void MainWindow::on_three_clicked()
{

    DrawableComponent *i=new ImageComponent((this->width()/2)-(130/2),(this->height()/2)-(130/2),130,130,"C:/QT_eg/DrawingExample4/three.png");
    view->add(i);
    QWidget::update();
}

void MainWindow::on_one_clicked()
{
    DrawableComponent *i=new ImageComponent((this->width()/2)-(130/2),(this->height()/2)-(130/2),130,130,"C:/QT_eg/DrawingExample4/one.png");
    view->add(i);
    QWidget::update();
}

void MainWindow::on_two_clicked()
{
    DrawableComponent *i=new ImageComponent((this->width()/2)-(130/2),(this->height()/2)-(130/2),130,130,"C:/QT_eg/DrawingExample4/two.png");
    view->add(i);
    QWidget::update();
}

void MainWindow::on_four_clicked()
{
    DrawableComponent *i=new ImageComponent((this->width()/2)-(130/2),(this->height()/2)-(130/2),130,130,"C:/QT_eg/DrawingExample4/four.png");
    view->add(i);
    QWidget::update();
}

void MainWindow::on_five_clicked()
{
    DrawableComponent *i=new ImageComponent((this->width()/2)-(130/2),(this->height()/2)-(130/2),130,130,"C:/QT_eg/DrawingExample4/five.png");
    view->add(i);
    QWidget::update();
}

void MainWindow::on_six_clicked()
{
    DrawableComponent *i=new ImageComponent((this->width()/2)-(130/2),(this->height()/2)-(130/2),130,130,"C:/QT_eg/DrawingExample4/six.png");
    view->add(i);
    QWidget::update();
}

void MainWindow::on_seven_clicked()
{
    DrawableComponent *i=new ImageComponent((this->width()/2)-(130/2),(this->height()/2)-(130/2),130,130,"C:/QT_eg/DrawingExample4/seven.png");
    view->add(i);
    QWidget::update();
}

void MainWindow::on_eight_clicked()
{
    DrawableComponent *i=new ImageComponent((this->width()/2)-(130/2),(this->height()/2)-(130/2),130,130,"C:/QT_eg/DrawingExample4/eight.png");
    view->add(i);
    QWidget::update();

}

void MainWindow::on_nine_clicked()
{
    DrawableComponent *i=new ImageComponent((this->width()/2)-(130/2),(this->height()/2)-(130/2),130,130,"C:/QT_eg/DrawingExample4/nine.png");
    view->add(i);
    QWidget::update();
}

void MainWindow::on_zero_clicked()
{
    DrawableComponent *i=new ImageComponent((this->width()/2)-(130/2),(this->height()/2)-(130/2),130,130,"C:/QT_eg/DrawingExample4/zero.png");
    view->add(i);
}

void MainWindow::on_decimal_clicked()
{
    DrawableComponent *i=new ImageComponent((this->width()/2)-(130/2),(this->height()/2)-(130/2),130,130,"C:/QT_eg/DrawingExample4/decimal.png");
    view->add(i);
    QWidget::update();
}

void MainWindow::on_colon_clicked()
{
    DrawableComponent *i=new ImageComponent((this->width()/2)-(130/2),(this->height()/2)-(130/2),130,130,"C:/QT_eg/DrawingExample4/colon.png");
    view->add(i);
    QWidget::update();
}

void MainWindow::on_plus_clicked()
{
    DrawableComponent *i=new ImageComponent((this->width()/2)-(130/2),(this->height()/2)-(130/2),130,130,"C:/QT_eg/DrawingExample4/plus.png");
    view->add(i);
    QWidget::update();
}

void MainWindow::on_minus_clicked()
{
    DrawableComponent *i=new ImageComponent((this->width()/2)-(130/2),(this->height()/2)-(130/2),130,130,"C:/QT_eg/DrawingExample4/minus.png");
    view->add(i);
    QWidget::update();
}

void MainWindow::on_multiply_clicked()
{
    DrawableComponent *i=new ImageComponent((this->width()/2)-(130/2),(this->height()/2)-(130/2),130,130,"C:/QT_eg/DrawingExample4/multiply.png");
    view->add(i);
    QWidget::update();
}

void MainWindow::on_divide_clicked()
{
    DrawableComponent *i=new ImageComponent((this->width()/2)-(130/2),(this->height()/2)-(130/2),130,130,"C:/QT_eg/DrawingExample4/divide.png");
    view->add(i);
    QWidget::update();
}

void MainWindow::on_equal_clicked()
{
    DrawableComponent *i=new ImageComponent((this->width()/2)-(130/2),(this->height()/2)-(130/2),130,130,"C:/QT_eg/DrawingExample4/equal.png");
    view->add(i);
    QWidget::update();
}

void MainWindow::on_root_clicked()
{
    DrawableComponent *i=new ImageComponent((this->width()/2)-(130/2),(this->height()/2)-(130/2),130,130,"C:/QT_eg/DrawingExample4/root.png");
    view->add(i);
    QWidget::update();
}

void MainWindow::on_sigma_clicked()
{
    DrawableComponent *i=new ImageComponent((this->width()/2)-(130/2),(this->height()/2)-(130/2),130,130,"C:/QT_eg/DrawingExample4/sigma.png");
    view->add(i);
    QWidget::update();
}

void MainWindow::on_lineEquation_clicked()
{
    DrawableComponent *i=new ImageComponent((this->width()/2)-(130/2),(this->height()/2)-(130/2),130,130,"C:/QT_eg/DrawingExample4/lineEquation.png");
    view->add(i);
    QWidget::update();
}

void MainWindow::on_circleEquation_clicked()
{
    DrawableComponent *i=new ImageComponent((this->width()/2)-(130/2),(this->height()/2)-(130/2),130,130,"C:/QT_eg/DrawingExample4/circleEquation.png");
    view->add(i);
    QWidget::update();
}

void MainWindow::on_trigonometryFunction_clicked()
{
    DrawableComponent *i=new ImageComponent((this->width()/2)-(130/2),(this->height()/2)-(130/2),130,130,"C:/QT_eg/DrawingExample4/trigonometryFunctions.png");
    view->add(i);
    QWidget::update();
}

void MainWindow::on_trigonometryFunction2_clicked()
{
    DrawableComponent *i=new ImageComponent((this->width()/2)-(130/2),(this->height()/2)-(130/2),130,130,"C:/QT_eg/DrawingExample4/trigonometryFunctions2.png");
    view->add(i);
    QWidget::update();
}
