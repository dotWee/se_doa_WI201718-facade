# Beispielcode zum Entwurfsmuster Fassade

Dieses Projekt stellt eine Beispiel-Implementierung in C++ des Entwurfsmusters **Fassade** aus dem Bereich der Softwareentwicklung dar.

## Inhaltsverzeichnis

1. [Komponenten](#komponenten)
    - [Motor](#motor)
    - [Frontscheinwerfer](#frontscheinwerfer)
    - [Automobil](#automobil)
    - [Fahrer](#fahrer)
2. [Ausführung](#ausführung)
    - [Ablaufdiagramm](#ablaufdiagramm)
    - [Voraussetzungen](#voraussetzungen)
    - [Beispielausführung](#beispielausführung)
3. [Referenzen](#referenzen)

## Komponenten

![Klassendiagramm](uml/Klassendiagramm.png)
![Typenhierarchie](uml/Typenhierarchie.png)

### [Motor](src/Motor.h)

Die Klasse [Motor](src/Motor.h) soll einen mechanischen Motor symbolisieren, welcher durch einen Aufruf der Funktion `Motor::zünden()` zum Starten gebracht werden.

### [Frontscheinwerfer](src/Frontscheinwerfer.h)

Die Klasse [Frontscheinwerfer](src/Frontscheinwerfer.h) ist eine fiktive Komponente, welche durch die Schnittstelle `Frontscheinwerfer::einschalten()` angesprochen werden kann.

### [Automobil](src/Automobil.h)

Die Klasse _Automobil_ soll ein Modell eines Auto symbolisieren, welches durch einen Aufruf der Funktion `Automobil::schlüsseldrehen()` gestartet werden kann. Dieses fiktionale Auto besteht aus mehreren Bestandteilen, unteranderem einem [Motor](#motor) und [Frontscheinwerfer](#frontscheinwerfer). Bim Drehen des Autoschlüssels wird der Motor gezündet und die Frontscheinwerfer werden eingeschaltet.

Die Datenstruktur der Klasse _Automobil_ bildet hier eine Art **Fassade**, bei der die Schnittstellen des _Motors_ (`Motor::zünden()`) und der _Frontscheinwerfer_ (`Frontscheinwerfer::einschalten()`) hinter einer einzelnen Schnittstelle (`Automobil::schlüsseldrehen()`) verborgen wird:

```cpp
#include "Automobil.h"
#include "Motor.h"

void Automobil::schlüsseldrehen() {
    // Zünde den Motor
    motor.zünden();

    // Schalte die Frontscheinwerfer ein
    frontscheinwerfer.einschalten();

    [...]
    // Auto wurde gestartet!
}
```

### [Fahrer](src/Fahrer.h)

Das Fahrer-Modell soll abstrakte Clients simulieren, welche auf verschiedene Zugriffsarten die Komponenten [Motor](#motor) und [Frontscheinwerfer](#frontscheinwerfer) anprechen sowie aktivieren.

#### 1. [Der "manuelle" Fahrer](src/ManuelleFahrer.h)

Der "manuelle" Fahrer spricht die Komponenten [Motor](#motor) und [Frontscheinwerfer](#frontscheinwerfer) direkt an, überprüft deren Status selbst und hat volle Kontrolle über deren Schnittstellen.

```cpp
#include "Fahrer.h"
#include "Motor.h"
#include "Frontscheinwerfer.h"

class ManuellerFahrer : public Fahrer {
private:
    Motor motor;
    Frontscheinwerfer frontscheinwerfer;
public:
    void starten() {
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
};
```

#### 2. [Der "automatische" Fahrer](src/AutomatischeFahrer.h)

Der "automatische" Fahrer spricht über die **Fassadenklasse** [Automobil](src/Automobil.h) die Komponenten [Motor](#motor) und [Frontscheinwerfer](#frontscheinwerfer) an, es findet keine direkte Kommunikation zwischen den Schnittstellen statt.

```cpp
#include "Fahrer.h"
#include "Automobil.h"

class AutomatischerFahrer : public Fahrer {
private:
    Automobil automobil;
public:
    void starten() {
        cout << "AutomatischerFahrer: Beginne das Auto zu starten..." << endl;

        // Schlüssel drehen
        automobil.schlüsseldrehen();

        // Läuft
        cout << "AutomatischerFahrer: Motor und Frontscheinwerfer gestartet!" << endl;
    }
};
```

## Ausführung

### Ablaufdiagramm

Ablauf "automatischer" Fahrer | Ablauf "manueller" Fahrer
--- | ---
![AblaufdiagrammAutomatisch](uml/AblaufdiagrammAutomatisch.png) | ![AblaufdiagrammManuell](uml/AblaufdiagrammManuell.png)

### Voraussetzungen

Ein aktueller C++-Compiler (`g++`) und das GNU Make Tool (`make`) werden vorausgesetzt.

Zu Beginnt wird mit `$ make executable` die Kompilierung des Quellcodes gestartet und im Anschluss die generierten Binaries mit den nötigen Rechten für eine Ausführung versehen.

Zuletzt wird mit `$ make run` die Ausführung gestartet.

### Beispielausführung

```bash
Lukas-MacBook:se_doa_WI201718-facade lukas$ make
g++ -Wall -I./src src/main.cpp src/ManuellerFahrer.cpp src/AutomatischerFahrer.cpp src/Automobil.cpp src/Frontscheinwerfer.cpp src/Motor.cpp -o Automobil
chmod +x Automobil
./Automobil
-------------------------------------
ManuellerFahrer: Beginne das Auto zu starten...
ManuellerFahrer: Versuche den Motor zu zünden...
Motor: Motor wurde gezündet.ManuellerFahrer: Versuche die Frontscheinwerfer einzuschalten...
Frontscheinwerfer: Frontscheinwerfer wurden eingeschaltet.
ManuellerFahrer: Motor und Frontscheinwerfer gestartet!
-------------------------------------
AutomatischerFahrer: Beginne das Auto zu starten...
Automobil: Versuche das Auto mit Motor und Frontscheinwerfer zu starten...
Automobil: Versuche den Motor zu zünden...
Motor: Motor wurde gezündet.
Automobil: Versuche die Frontscheinwerfer einzuschalten...
Frontscheinwerfer: Frontscheinwerfer wurden eingeschaltet.
Automobil: Auto wurde gestartet!
AutomatischerFahrer: Motor und Frontscheinwerfer gestartet!
-------------------------------------
rm -f Automobil
```

## Referenzen

- [Einsteigerfreundliche Einführung in das Facade Design Pattern](http://www.philipphauer.de/study/se/design-pattern/facade.php)
- [Fassade (Entwurfsmuster)](https://de.wikipedia.org/wiki/Fassade_(Entwurfsmuster))