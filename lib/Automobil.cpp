#include <cstring>
#include <cstdlib>
#include <iostream>

#include "Automobil.h"
#include "Motor.h"
#include "Frontlichter.h"

void Automobil::schlüsseldrehen() {
    // Starte das Auto
    std::cout << "Versuche das Auto mit Motor und Frontlichtern zu starten..." << std::endl;            

    // Zünde den Motor
    std::cout << "Versuche den Motor zu zünden..." << std::endl;        
    motor.zünden();

    // Schalte die Frontlichter ein
    std::cout << "Versuche die Frontlichter einzuschalten..." << std::endl;        
    frontlichter.anschalten();

    std::cout << "Auto wurde gestartet." << std::endl;    
}
