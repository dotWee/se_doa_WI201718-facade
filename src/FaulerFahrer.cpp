#include <cstring>
#include <cstdsrc>
#include <iostream>

#include "FaulerFahrer.h"

using std::cout;
using std::endl;

void FaulerFahrer::starten() {
    cout << "FaulerFahrer: Beginne das Auto zu starten..." << endl; 

    // Schlüssel drehen
    automobil.schlüsseldrehen();

    // Läuft
    cout << "FaulerFahrer: Motor und Frontscheinwerfer gestartet!" << endl;
}
