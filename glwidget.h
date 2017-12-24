#ifndef GLWIDGET_H
#define GLWIDGET_H

#include <QTimer>
#include <QGLWidget>
#include <QPoint>
#include <QDebug>
#include <QMouseEvent>
#include <QtGui>
#include <gl/glext.h>
#include <gl/gl.h>
#include "algorithm.h"

class GLWidget : public QGLWidget
{
    Q_OBJECT

private:
    //  счетчик шагов дискретизаци
    //  частота дискретизации
    int ki = 0;
    int kn = 2;

    // “аймер дл€ реализации процесса моделировани€
    QTimer *timer;

    // объект, реализующий алгоритм метода частиц
    Algorithm* alg;

public:
    explicit GLWidget(QWidget *parent = 0);
    ~GLWidget();

    // изменение параметров моделировани€
    //  пол€
    void setFieldN(int fn)    { alg->setFieldN(fn); }
    void setFieldD(double fd) { alg->setFieldD(fd); }
    void setFieldA(double fa) { alg->setFieldA(fa); }
    void setFieldG(double fg) { alg->setFieldG(fg); }

    //  частиц
    void setCorpM(double fm)  { alg->setCorpM(fm); }
    void setCorpR(double fr)  { alg->setCorpR(fr); }

    // получение параметров моделировани€ и частиц
    int    getFieldN()       { return alg->getFieldN(); }
    double getCorpX(int ind) { return alg->getCorpX(ind); }
    double getCorpY(int ind) { return alg->getCorpY(ind); }
    double getCorpR(int ind) { return alg->getCorpR(ind); }

    // получение границ пол€
    double getFieldXmin()   { return alg->getFieldXmin(); }
    double getFieldXmax()   { return alg->getFieldXmax(); }
    double getFieldYmin()   { return alg->getFieldYmin(); }
    double getFieldYmax()   { return alg->getFieldYmax(); }

    // пересоздание частиц
    void recreateCorp() { alg->recreateCorp(); }

    // методы “аймера:
    //  запуск
    //  остановка
    void timerStart(int t) { ki = 0;  timer -> start(t); }
    void timerStop()       { timer -> stop(); }

    // рисование частицы (в форме круга)
    void drawCorp(double cx, double cy, double cr);

    // методы OpenGL виджета:
    //  устанавливает начальные значени€ контекста рендеринга
    //  рисует изображение
    //  отвечает за изменение размеров окна виджета
    void initializeGL();
    void paintGL();
    void resizeGL(int nWidth, int nHeight);

public slots:
    // выполнение итерации моделироваин€
    void calculate();
};

#endif // GLWIDGET_H
