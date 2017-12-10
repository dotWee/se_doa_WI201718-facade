#include <cstring>
#include <cstdlib>
#include <iostream>

#include "ManuellerFahrer.h"

using std::cout;
using std::endl;

void ManuellerFahrer::starten() {
    cout << "ManuellerFahrer: Beginne das Auto zu starten..." << endl; 

    // Zünde den Motor
    cout << "ManuellerFahrer: Versuche den Motor zu zünden..." << endl;        
    motor.zünden();

    // Schalte die Frontscheinwerfer ein
    cout << "ManuellerFahrer: Versuche die Frontscheinwerfer einzuschalten..." << endl;        
    frontscheinwerfer.einschalten();

    // Läuft
    cout << "ManuellerFahrer: Motor und Frontscheinwerfer gestartet!" << endl;
}
