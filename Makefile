all: automobil run clean

automobil:
	g++ -Wall -Og -c lib/Automobil.cpp lib/Frontscheinwerfer.cpp lib/Motor.cpp main.cpp
	g++ -Wall -Og Automobil.o Frontscheinwerfer.o Motor.o main.o -o Automobil
	chmod +x Automobil

run:
	./Automobil

clean:
	$(RM) *.o
	$(RM) *.out
	$(RM) Automobil
