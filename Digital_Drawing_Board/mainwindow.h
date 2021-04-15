#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include<QPainter>
#include<tmview.h>
#include<QPaintEvent>
#include<QMouseEvent>
#include<DrawableComponent.h>
#include<QKeyEvent>
#include<linecomponent.h>
#include<rectanglecomponent.h>
#include<ellipsecomponent.h>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    void paintEvent(QPaintEvent *);
    void mouseMoveEvent(QMouseEvent *mm);
    void mousePressEvent(QMouseEvent *mp);
    void mouseReleaseEvent(QMouseEvent *mr);
    void keyPressEvent(QKeyEvent *k);
    void keyReleaseEvent(QKeyEvent *k);
    void drawBoardLine(QPainter *p);
    ~MainWindow();

private slots:
    void on_lineButton_clicked();

    void on_rectangleButton_clicked();

    void on_freeHandToolButton_clicked();

    void on_circleButton_clicked();

    void on_pickToolButton_clicked();

    void on_componentStack_clicked(const QModelIndex &index);

    void on_clearButton_clicked();

    void on_groupButton_clicked();

    void on_unGroupButton_clicked();

    void on_saveButton_clicked();

    void on_openButton_clicked();

    void on_penWidthSlider_valueChanged(int value);

    void on_red_clicked();

    void on_green_clicked();

    void on_blue_clicked();

    void on_yellow_clicked();

    void on_orange_clicked();

    void on_pink_clicked();

    void on_white_clicked();

    void on_black_clicked();

    void on_skyblue_clicked();

    void on_sheetButton_clicked();

    void on_paperButton_clicked();

    void on_imageButton_clicked();

    void on_backButton_clicked();

    void on_toolsButton_clicked();

    void on_pushButton_clicked();

    void on_toolsFrameCancelButton_clicked();

    void on_resizeButton_clicked();

    void on_three_clicked();

    void on_one_clicked();

    void on_two_clicked();

    void on_four_clicked();

    void on_five_clicked();

    void on_six_clicked();

    void on_seven_clicked();

    void on_eight_clicked();

    void on_nine_clicked();

    void on_zero_clicked();

    void on_decimal_clicked();

    void on_colon_clicked();

    void on_plus_clicked();

    void on_minus_clicked();

    void on_multiply_clicked();

    void on_divide_clicked();

    void on_equal_clicked();

    void on_root_clicked();

    void on_sigma_clicked();

    void on_lineEquation_clicked();

    void on_circleEquation_clicked();

    void on_trigonometryFunction_clicked();

    void on_trigonometryFunction2_clicked();

private:
    Ui::MainWindow *ui;
    TMView *view;
    int flag=0;
    int oldX=-1;
    int oldY=-1;
    int currentX=-1;
    int currentY=-1;
    bool lineSignal=false;
    bool rectangleSignal=false;
    bool freeHandToolSignal=false;
    bool circleSignal=false;
    bool pickToolSignal=false;
    bool processCallingFlag=false;
    bool ctrlKeyPressed=false;
    bool shiftKeyPressed=false;
    bool resizeSignal=false;
    QList<DrawableComponent *> *list;
    QPainter *n;
    DrawableComponent *component;
    int gapX=0;
    int gapY=0;
    int penWidth=1;
    QColor penColor;
    bool sheet=true;
    bool paper=false;
    LineComponent *strechedLine=nullptr;
    RectangleComponent *strechedRectangle=nullptr;
    EllipseComponent *strechedCircle=nullptr;



};
#endif // MAINWINDOW_H
