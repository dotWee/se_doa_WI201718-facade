# Beispielcode zum Entwurfsmuster Fassade

Dieses Projekt stellt eine Beispiel-Implementierung in C++ des Entwurfsmusters **Fassade** aus dem Bereich der Softwareentwicklung dar.

## Inhaltsverzeichnis

1. [Komponenten](#komponenten)
    - [Motor](#motor)
    - [Frontscheinwerfer](#frontscheinwerfer)
    - [Automobil](#automobil)
2. [Ausführung](#ausführung)
    - [Voraussetzungen](#voraussetzungen)
    - [Beispielausführung](#beispielausführung)
3. [Referenzen](#referenzen)

## Komponenten

### [Motor](lib/Motor.h)

Die Klasse [Motor](lib/Motor.h) soll einen mechanischen Motor symbolisieren, welcher durch einen Aufruf der Funktion `Motor::zünden()` zum Starten gebracht werden.

### [Frontscheinwerfer](lib/Frontscheinwerfer.h)

Die Klasse [Frontscheinwerfer](lib/Frontscheinwerfer.h) ist eine fiktive Komponente, welche durch die Schnittstelle `Frontscheinwerfer::einschalten()` angesprochen werden kann.

### [Automobil](lib/Automobil.h)

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

## Ausführung

### Voraussetzungen

Ein aktueller C++-Compiler (`g++`) und das GNU Make Tool (`make`) werden vorausgesetzt.

Der Befehl `make` startet die Kompilierung und führt die generierten Binaries im Anschluss aus.

### Beispielausführung

```sh
Lukas-MacBook:Beispielcode lukas$ make
g++ -c lib/Automobil.cpp lib/Frontscheinwerfer.cpp lib/Motor.cpp main.cpp
g++ Automobil.o Frontscheinwerfer.o Motor.o main.o -o Automobil
chmod +x Automobil
./Automobil

Versuche das Auto mit Motor und Frontscheinwerfer zu starten...
Versuche den Motor zu zünden...
Motor wurde gezündet.
Versuche die Frontscheinwerfer einzuschalten...
Frontscheinwerfer wurden eingeschaltet.
Auto wurde gestartet!

rm -f *.o
rm -f *.out
rm -f Automobil
```

## Referenzen

- [Einsteigerfreundliche Einführung in das Facade Design Pattern](http://www.philipphauer.de/study/se/design-pattern/facade.php)
- [Fassade (Entwurfsmuster)](https://de.wikipedia.org/wiki/Fassade_(Entwurfsmuster))