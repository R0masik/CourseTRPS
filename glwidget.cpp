#include "glwidget.h"

GLWidget::GLWidget(QWidget *parent) : QGLWidget(parent)
{
    alg = new Algorithm();
    timer = new QTimer();

    // расчет движени€ частиц происходит по срабатыванию “аймера
    connect(timer, SIGNAL(timeout()), SLOT(calculate()));
}

GLWidget::~GLWidget()
{
    delete alg;
    delete timer;
}

void GLWidget::drawCorp(double cx, double cy, double cr)
{
    glColor3f(0.3f,0.3f,0.8f);
    glBegin( GL_TRIANGLE_FAN );
        glVertex2f(cx, cy);
        for(int i = 0; i <= 50; i++ ) {
            double ang = (double)i / 50.0f * 3.1415f * 2.0f;
            glVertex2f(cx + cos(ang) * cr, cy + sin(ang) * cr);
        }
    glEnd();
}

void GLWidget::initializeGL()
{
    // цвет фона
    glClearColor(1.0, 0.9, 0.9, 1.0);

    glEnable(GL_DEPTH_TEST);
    glShadeModel(GL_FLAT);
    glEnable(GL_CULL_FACE);
}

void GLWidget::paintGL()
{
    // очистка экрана
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    int n = getFieldN();

    // отрисовка частиц
    for (int i = 0; i < n; i++) {
        double corpX = getCorpX(i);
        double corpY = getCorpY(i);
        double corpR = getCorpR(i);

        drawCorp(corpX, corpY, corpR);
    }
}

void GLWidget::resizeGL(int nWidth, int nHeight)
{
    glMatrixMode(GL_PROJECTION);

    glLoadIdentity();

    double xmin = getFieldXmin();
    double xmax = getFieldXmax();
    double ymin = getFieldYmin();
    double ymax = getFieldYmax();

    glOrtho(xmin, xmax, ymin, ymax, -1.0, 1.0);

    glViewport(0, 0, (GLint)nWidth, (GLint)nHeight);
}

void GLWidget::calculate()
{
    // итераци€ моделировани€
    alg->modeling();

    // отрисовка изображени€ выполн€етс€ за kn шагов дискретизации
    ki++;
    if (ki == kn) {
        updateGL();
        ki = 0;
    }
}
