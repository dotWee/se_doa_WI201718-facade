#include <cstring>
#include <cstdlib>
#include <iostream>

#include "ManuellerFahrer.h"
#include "AutomatischerFahrer.h"

using namespace std;

int main(int argc, char *argv[]) {

    cout << "-------------------------------------" << endl;
    ManuellerFahrer manuellerFahrer;
    manuellerFahrer.starten();

    cout << "-------------------------------------" << endl;    
    AutomatischerFahrer automatischerFahrer;
    automatischerFahrer.starten();

    cout << "-------------------------------------" << endl;    
    return 0;
}
