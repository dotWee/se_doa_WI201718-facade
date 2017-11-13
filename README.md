# Beispielcode zum Entwurfsmuster Fassade

Dieses Projekt stellt eine Beispiel-Implementation des Entwurfsmusters **Fassade** aus dem Bereich der Softwareentwicklung dar.

## Ausführung

Ein aktueller C++-Compiler (`g++`) und das GNU Make Tool (`make`) werden vorausgesetzt.

Der Befehl `make` startet die Kompilierung und führt die generierten Binaries im Anschluss aus.

Beispielausführung:

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

## Bestandteile

### [Motor](lib/Motor.h) und [Frontscheinwerfer](lib/Frontscheinwerfer.h)

Die Klassen [Motor](lib/Motor.h) und [Frontscheinwerfer](lib/Frontscheinwerfer.h) sollen Bestandteile eines Autos symbolisieren, welche jeweils durch die Schnittstellen `Motor::zünden()` und `Frontscheinwerfer::einschalten()` angesprochen werden.

### [Automobil](lib/Automobil.h)

Die Klasse _Automobil_ soll ein Modell eines Auto symbolisieren, welches durch einen Aufruf der Funktion `schlüsseldrehen()` gestartet werden sollte. Dieses fiktionale Auto besteht aus mehreren Bestandteilen, unteranderem einem Motor und Frontscheinwerfer. Bim Drehen des Autoschlüssels wird der Motor gezündet und die Frontscheinwerfer beginnen zu leuchten.

Die Implementierung der Klasse _Automobil_ bildet hier eine Art **Fassade**, bei der die Schnittstellen des _Motors_ (`zünden()`) und der _Frontscheinwerfer_ (`einschalten()`) hinter einer einzelnen vereinfachten Schnittstelle (`schlüsseldrehen()`) verborgen wird.

## Referenzen

- [Einsteigerfreundliche Einführung in das Facade Design Pattern](http://www.philipphauer.de/study/se/design-pattern/facade.php)
- [Fassade (Entwurfsmuster)](https://de.wikipedia.org/wiki/Fassade_(Entwurfsmuster))