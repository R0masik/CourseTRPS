#include "corpuscle.h"

Corpuscle::Corpuscle()
{
    randCoord();
}

void Corpuscle::randCoord()
{
    x = qrand() % 70 + 15;
    y = qrand() % 70 + 20;
    vx = qrand() % 5 - 2;
}
