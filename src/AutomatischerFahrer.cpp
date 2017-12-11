#include <cstring>
#include <cstdlib>
#include <iostream>

#include "AutomatischerFahrer.h"

using std::cout;
using std::endl;

void AutomatischerFahrer::starten() {
    cout << "AutomatischerFahrer: Beginne das Auto zu starten..." << endl; 

    // Schlüssel drehen
    automobil.schlüsseldrehen();

    // Läuft
    cout << "AutomatischerFahrer: Motor und Frontscheinwerfer gestartet!" << endl;
}
