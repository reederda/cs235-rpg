CC = g++
CFLAGS = -g -Wall -std=c++11

default: lab1

lab1: Fighter.o Archer.o Cleric.o Robot.o Arena.o main.o
	$(CC) $(CFLAGS) -o lab1 Fighter.o Archer.o Cleric.o Robot.o Arena.o main.o

Fighter.o: Fighter.cpp Fighter.h 
	$(CC) $(CFLAGS) -c Fighter.cpp

Archer.o: Archer.cpp Fighter.h Archer.h
	$(CC) $(CFLAGS) -c Archer.cpp

Cleric.o: Cleric.cpp Fighter.h Cleric.h 
	$(CC) $(CFLAGS) -c  Cleric.cpp

Robot.o: Robot.cpp Fighter.h Robot.h 
	$(CC) $(CFLAGS) -c Robot.cpp

Arena.o: Arena.cpp Fighter.h Archer.h Robot.h Cleric.h Arena.h FighterInterface.h
	$(CC) $(CFLAGS) -c  Arena.cpp

main.o: main.cpp Arena.h 
	$(CC) $(CFLAGS) -c main.cpp

clean:
	$(RM) lab1 *.o *.~
