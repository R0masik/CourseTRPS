#include "corpuscle.h"

Corpuscle::Corpuscle()
{
    randCoord();
}

void Corpuscle::randCoord()
{
    x = qrand() % 901 + 50;
    y = qrand() % 901 + 50;
}
