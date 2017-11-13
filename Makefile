all: automobil start clean

automobil:
	g++ -c lib/Automobil.cpp lib/Frontlichter.cpp lib/Motor.cpp main.cpp
	g++ Automobil.o Frontlichter.o Motor.o main.o -o Automobil
	chmod +x Automobil

start:
	./Automobil

clean:
	$(RM) *.o
	$(RM) *.out
	$(RM) Automobil