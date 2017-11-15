all: automobil run clean

automobil:
	g++ -c lib/Automobil.cpp lib/Frontscheinwerfer.cpp lib/Motor.cpp main.cpp
	g++ Automobil.o Frontscheinwerfer.o Motor.o main.o -o Automobil
	chmod +x Automobil

run:
	./Automobil

clean:
	$(RM) *.o
	$(RM) *.out
	$(RM) Automobil