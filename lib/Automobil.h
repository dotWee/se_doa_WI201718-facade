#ifndef SE_FACADE_AUTOMOBIL_H
#define SE_FACADE_AUTOMOBIL_H

#include "Motor.h"
#include "Frontlichter.h"

class Automobil {
private:
    Motor motor;
    Frontlichter frontlichter;
public:
    void starte();
};

#endif //SE_FACADE_AUTOMOBIL_H