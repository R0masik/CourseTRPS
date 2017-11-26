#include "glwidget.h"
#include <QtGui>
#include <math.h>
#include <gl/glext.h>
#include <gl/gl.h>

GLWidget::GLWidget(QWidget *parent) : QGLWidget(parent)
{
    QTime midnight(0,0,0);
    qsrand(midnight.secsTo(QTime::currentTime()));

    corp = new Corpuscle[n];

    timer = new QTimer();
    connect(timer, SIGNAL(timeout()), SLOT(draw()));
}

GLWidget::~GLWidget()
{
    delete[] corp;
    delete timer;
}

void GLWidget::drawCircle(float cx, float cy, float cr)
{
    glColor3f(0.3f,0.3f,0.8f);
    glBegin( GL_TRIANGLE_FAN );
        glVertex2f(cx, cy); // вершина в центре круга
        for(int i = 0; i <= 50; i++ ) {
            float ang = (float)i / 50.0f * 3.1415f * 2.0f;
            glVertex2f(cx + cos(ang) * cr, cy + sin(ang) * cr);
        }
    glEnd();
}

void GLWidget::draw()
{
    for (int i = 0; i < n; i++) {
        double px = corp[i].getX();
        double py = corp[i].getY();
        double r = corp[i].getR();
        double vx = corp[i].getVX();
        double vy = corp[i].getVY();

        if (px >= xmax - r || px <= xmin + r)
            vx -= 2 * vx;

        if (py <= ymin + r)
            vy -= 2 * vy;
        else
            vy -= g;

        px += vx;
        py += vy;

        corp[i].setX(px);
        corp[i].setY(py);
        corp[i].setVX(vx);
        corp[i].setVY(vy);
    }
    updateGL();
}

void GLWidget::initializeGL()
{
    glClearColor(1.0, 0.8, 0.8, 1.0);

    glEnable(GL_DEPTH_TEST);
    glShadeModel(GL_FLAT);
    glEnable(GL_CULL_FACE);

    glEnableClientState(GL_VERTEX_ARRAY);
    glEnableClientState(GL_COLOR_ARRAY);
}

void GLWidget::paintGL()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    for (int i = 0; i < n; i++)
        drawCircle(corp[i].getX(), corp[i].getY(), corp[i].getR());
}

void GLWidget::resizeGL(int nWidth, int nHeight)
{
    glMatrixMode(GL_PROJECTION);

    glLoadIdentity();

    glOrtho(xmin, xmax, ymin, ymax, -1.0, 1.0);

    glViewport(0, 0, (GLint)nWidth, (GLint)nHeight);
}

void GLWidget::timerStart(int t)
{
    timer -> start(t);
}

void GLWidget::timerStop()
{
    timer -> stop();
}
