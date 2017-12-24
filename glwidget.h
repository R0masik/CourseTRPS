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
    //  ������� ����� ������������
    //  ������� �������������
    int ki = 0;
    int kn = 2;

    // ������ ��� ���������� �������� �������������
    QTimer *timer;

    // ������, ����������� �������� ������ ������
    Algorithm* alg;

public:
    explicit GLWidget(QWidget *parent = 0);
    ~GLWidget();

    // ��������� ���������� �������������
    //  ����
    void setFieldN(int fn)    { alg->setFieldN(fn); }
    void setFieldD(double fd) { alg->setFieldD(fd); }
    void setFieldA(double fa) { alg->setFieldA(fa); }
    void setFieldG(double fg) { alg->setFieldG(fg); }

    //  ������
    void setCorpM(double fm)  { alg->setCorpM(fm); }
    void setCorpR(double fr)  { alg->setCorpR(fr); }

    // ��������� ���������� ������������� � ������
    int    getFieldN()       { return alg->getFieldN(); }
    double getCorpX(int ind) { return alg->getCorpX(ind); }
    double getCorpY(int ind) { return alg->getCorpY(ind); }
    double getCorpR(int ind) { return alg->getCorpR(ind); }

    // ��������� ������ ����
    double getFieldXmin()   { return alg->getFieldXmin(); }
    double getFieldXmax()   { return alg->getFieldXmax(); }
    double getFieldYmin()   { return alg->getFieldYmin(); }
    double getFieldYmax()   { return alg->getFieldYmax(); }

    // ������������ ������
    void recreateCorp() { alg->recreateCorp(); }

    // ������ �������:
    //  ������
    //  ���������
    void timerStart(int t) { ki = 0;  timer -> start(t); }
    void timerStop()       { timer -> stop(); }

    // ��������� ������� (� ����� �����)
    void drawCorp(double cx, double cy, double cr);

    // ������ OpenGL �������:
    //  ������������� ��������� �������� ��������� ����������
    //  ������ �����������
    //  �������� �� ��������� �������� ���� �������
    void initializeGL();
    void paintGL();
    void resizeGL(int nWidth, int nHeight);

public slots:
    // ���������� �������� �������������
    void calculate();
};

#endif // GLWIDGET_H
