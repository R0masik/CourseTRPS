#ifndef GLWIDGET_H
#define GLWIDGET_H

#include <QTimer>
#include <QGLWidget>
#include <QPoint>
#include <QDebug>
#include <QMouseEvent>
#include "corpuscle.h"

class GLWidget : public QGLWidget
{
    Q_OBJECT

private:
    QTimer *timer;

    // параметры экрана
    double xmin = 0.0;
    double xmax = 100.0;
    double ymin = 0.0;
    double ymax = 100.0;
    double g = 0.5;
    int n = 5;

    Corpuscle* corp;

public:
    explicit GLWidget(QWidget *parent = 0);
    ~GLWidget();

    void drawCircle(float cx, float cy, float cr);

    void initializeGL();
    void paintGL();
    void resizeGL(int nWidth, int nHeight);

    void timerStart(int t);
    void timerStop();

public slots:
    void draw();
};

#endif // GLWIDGET_H
