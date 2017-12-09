#include <cstring>
#include <cstdlib>
#include <iostream>

#include "Automobil.h"
#include "Motor.h"
#include "Frontscheinwerfer.h"

using std::cout;
using std::endl;

void Automobil::schlüsseldrehen() {
    // Starte das Auto
    cout << "Automobil: Versuche das Auto mit Motor und Frontscheinwerfer zu starten..." << endl;            

    // Zünde den Motor
    cout << "Automobil: Versuche den Motor zu zünden..." << endl;        
    motor.zünden();

    // Schalte die Frontscheinwerfer ein
    cout << "Automobil: Versuche die Frontscheinwerfer einzuschalten..." << endl;        
    frontscheinwerfer.einschalten();

    cout << "Automobil: Auto wurde gestartet!" << endl;    
}