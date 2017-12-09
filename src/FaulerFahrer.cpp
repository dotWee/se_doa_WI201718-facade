#include <cstring>
#include <cstdlib>
#include <iostream>

#include "FaulerFahrer.h"

using std::cout;
using std::endl;

void FaulerFahrer::starten() {

    // Starte das Auto
    cout << "FaulerFahrer: Versuche das Auto zu starten..." << endl; 

    // Schlüssel drehen
    automobil.schlüsseldrehen();

    // Läuft
    cout << "FaulerFahrer: Motor und Frontscheinwerfer gestartet!" << endl;
}
