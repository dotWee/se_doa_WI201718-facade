#ifndef SE_FACADE_MANUELLERFAHRER_H
#define SE_FACADE_MANUELLERFAHRER_H

#include "Fahrer.h"
#include "Motor.h"
#include "Frontscheinwerfer.h"

class ManuellerFahrer : public Fahrer {
private:
    Motor motor;
    Frontscheinwerfer frontscheinwerfer;
public:
    void starten();
};

#endif //SE_FACADE_MANUELLERFAHRER_H