all: automobil run clean

automobil:
	g++ -Wall -Og -c src/Automobil.cpp src/Frontscheinwerfer.cpp src/Motor.cpp src/main.cpp
	g++ -Wall -Og Automobil.o Frontscheinwerfer.o Motor.o main.o -o Automobil
	chmod +x Automobil

run:
	./Automobil

clean:
	$(RM) *.o
	$(RM) *.out
	$(RM) Automobil
