#ifndef CORPUSCLE_H
#define CORPUSCLE_H

#include <QTime>
#include <time.h>

// класс Частица
class Corpuscle
{
private:
    // параметры частиц:
    //  координата X
    //  координата Y
    //  масса
    //  радиус
    //  проекция вектора скорости на ось X
    //  проекция вектора скорости на ось Y
    double x = 50.0;
    double y = 50.0;
    double m = 1e3;
    double r = 10.0;
    double vx = 0.0;
    double vy = 0.0;

    // метод, задающий частице случайные координаты
    void randCoord();

public:
    Corpuscle();
    ~Corpuscle() {}

    // запись и получение параметров:
    //  координаты
    void setX(double fx) { x = fx; }
    void setY(double fy) { y = fy; }
    double getX() { return x; }
    double getY() { return y; }

    //  масса
    void setM(double fm) { m = fm; }
    double getM() { return m; }

    //  радиус
    void setR(double fr) { r = fr; }
    double getR() { return r; }

    //  проекции вектора скорости
    void setVX(double fvx) { vx = fvx; }
    void setVY(double fvy) { vy = fvy; }
    double getVX() { return vx; }
    double getVY() { return vy; }
};

#endif // CORPUSCLE_H
