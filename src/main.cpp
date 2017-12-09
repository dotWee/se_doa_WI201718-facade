#include <cstring>
#include <cstdlib>
#include <iostream>

#include "ManuellerFahrer.h"
#include "FaulerFahrer.h"

using namespace std;

int main(int argc, char *argv[]) {

    cout << "-------------------------------------" << endl;
    ManuellerFahrer manuellerFahrer;
    manuellerFahrer.starten();

    cout << "-------------------------------------" << endl;    
    FaulerFahrer faulerFahrer;
    faulerFahrer.starten();

    cout << "-------------------------------------" << endl;    
    return 0;
}
