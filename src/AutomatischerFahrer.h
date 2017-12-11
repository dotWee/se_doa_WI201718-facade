#ifndef SE_FACADE_AUTOMATISCHERERFAHRER_H
#define SE_FACADE_AUTOMATISCHERERFAHRER_H

#include "Fahrer.h"
#include "Automobil.h"

class AutomatischerFahrer : public Fahrer {
private:
    Automobil automobil;
public:
    void starten();
};

#endif //SE_FACADE_AUTOMATISCHERERFAHRER_H