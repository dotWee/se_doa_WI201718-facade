#ifndef SE_FACADE_FAULERFAHRER_H
#define SE_FACADE_FAULERFAHRER_H

#include "Fahrer.h"
#include "Automobil.h"

class FaulerFahrer : public Fahrer {
private:
    Automobil automobil;
public:
    void starten();
};

#endif //SE_FACADE_FAULERFAHRER_H