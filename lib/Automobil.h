#ifndef SE_FACADE_AUTOMOBIL_H
#define SE_FACADE_AUTOMOBIL_H

#include "Motor.h"
#include "Frontscheinwerfer.h"

class Automobil {
private:
    Motor motor;
    Frontscheinwerfer frontscheinwerfer;
public:
    void starten();
};

#endif //SE_FACADE_AUTOMOBIL_H