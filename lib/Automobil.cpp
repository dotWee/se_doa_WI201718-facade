#include <cstring>
#include <cstdlib>
#include <iostream>

#include "Automobil.h"
#include "Motor.h"

void Automobil::starten() {
    // Starte das Auto
    std::cout << "Versuche das Auto mit Motor und Frontscheinwerfer zu starten..." << std::endl;            

    // Zünde den Motor
    std::cout << "Versuche den Motor zu zünden..." << std::endl;        
    motor.zünden();

    // Schalte die Frontscheinwerfer ein
    std::cout << "Versuche die Frontscheinwerfer einzuschalten..." << std::endl;        
    frontscheinwerfer.einschalten();

    std::cout << "Auto wurde gestartet!" << std::endl;    
}
