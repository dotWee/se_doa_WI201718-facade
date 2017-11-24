# Beispielcode zum Entwurfsmuster Fassade

Dieses Projekt stellt eine Beispiel-Implementierung in C++ des Entwurfsmusters **Fassade** aus dem Bereich der Softwareentwicklung dar.

## Inhaltsverzeichnis

1. [Komponenten](#komponenten)
    - [Motor](#motor)
    - [Frontscheinwerfer](#frontscheinwerfer)
    - [Automobil](#automobil)
2. [Ausführung](#ausführung)
    - [Ablaufdiagramm](#ablaufdiagramm)
    - [Voraussetzungen](#voraussetzungen)
    - [Beispielausführung](#beispielausführung)
3. [Referenzen](#referenzen)

## Komponenten

![Klassendiagramm](uml/Klassendiagramm.jpeg)

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

### Ablaufdiagramm

Ablauf mit Fassade | Ablauf ohne Fassade
--- | ---
![Ablauf mit Fassade](uml/AblaufdiagrammMitFassade.jpeg) | ![Ablauf ohne Fassade](uml/AblaufdiagrammOhneFassade.jpeg)

### Voraussetzungen

Ein aktueller C++-Compiler (`g++`) und das GNU Make Tool (`make`) werden vorausgesetzt.

Zu Beginnt wird mit `$ make automobil` die Kompilierung des Quellcodes gestartet und im Anschluss die generierten Binaries mit den nötigen Rechten für eine Ausführung versehen.

Zuletzt wird mit `$ ./Automobil` die Ausführung gestartet.

### Beispielausführung

```bash
Lukas-MacBook:se_doa_WI201718-facade lukas$ make automobil
g++ -c lib/Automobil.cpp lib/Frontscheinwerfer.cpp lib/Motor.cpp main.cpp
g++ Automobil.o Frontscheinwerfer.o Motor.o main.o -o Automobil
chmod +x Automobil

Lukas-MacBook:se_doa_WI201718-facade lukas$ ./Automobil
Versuche das Auto mit Motor und Frontscheinwerfer zu starten...
Versuche den Motor zu zünden...
Motor wurde gezündet.
Versuche die Frontscheinwerfer einzuschalten...
Frontscheinwerfer wurden eingeschaltet.
Auto wurde gestartet!
```

## Referenzen

- [Einsteigerfreundliche Einführung in das Facade Design Pattern](http://www.philipphauer.de/study/se/design-pattern/facade.php)
- [Fassade (Entwurfsmuster)](https://de.wikipedia.org/wiki/Fassade_(Entwurfsmuster))