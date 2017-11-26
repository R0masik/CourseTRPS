#ifndef CORPUSCLE_H
#define CORPUSCLE_H
#include <time.h>
#include <QTime>

class Corpuscle
{
private:
    double x = 50.0;
    double y = 50.0;
    double r = 1.0;
    double vx = 0.0;
    double vy = 0.0;

    void randCoord();

public:
    Corpuscle();
    ~Corpuscle() {}

    void setX(double fx) { x = fx; }
    void setY(double fy) { y = fy; }
    double getX() { return x; }
    double getY() { return y; }

    void setR(double fr) { r = fr; }
    double getR() { return r; }

    void setVX(double fvx) { vx = fvx; }
    void setVY(double fvy) { vy = fvy; }
    double getVX() { return vx; }
    double getVY() { return vy; }
};

#endif // CORPUSCLE_H
