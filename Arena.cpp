#include "Arena.h"
#include "ArenaInterface.h"
#include "Cleric.h"
#include "Archer.h"
#include "Robot.h"
#include <sstream>
#include <iostream>
#include <vector>
using namespace std;

Arena::Arena()
{

}

bool Arena::addFighter(string info)
{
	istringstream in(info);
	in >> name >> type >> health >> strength >> speed >> magic;
	if (in.fail() || !in.eof())
	{
		return false;
	}
//	cout << "\nValues in: \nName: " << name << " Type: " << type << " Health: " << health << " Strength: " << strength << " Speed: " << speed << " Magic: " << magic << "\n";

	if (getFighter(name))
	{
		return false;
	}
	if (health < 1)
	{
		return false;
	}
	if (strength < 1)
	{
		return false;
	}
	if (speed < 1)
	{
		return false;
	}
	if (magic < 1)
	{
		return false;
	}

	if (type == "C")
	{
		Cleric* bob = new Cleric(name, health, strength, speed, magic);
		fighters.push_back(bob);
//		cout << "\nCleric name, health, strength, speed, magic: " << name << " " << type << " " << health << " " << strength << " " << speed << " " << magic << "\n";
	}
	else if (type == "A")
	{
		Archer* steve = new Archer(name, health, strength, speed, magic);
		fighters.push_back(steve);
//		cout << "\nArcher name, health, strength, speed, magic: " << name << " " << type << " " << health << " " << strength << " " << speed << " " << magic << "\n";
	}
	else if (type == "R")
	{
		Robot* fred = new Robot(name, health, strength, speed, magic);
		fighters.push_back(fred);
//		cout << "\nRobot name, health, strength, speed, magic: " << name << " " << type << " " << health << " " << strength << " " << speed << " " << magic << "\n";
	}
	else
	{
		return false;
	}


	return true;
}

/*
*	removeFighter(string)
*
*	Removes the fighter whose name is equal to the given name.  Does nothing if
*	no fighter is found with the given name.
*
*	Return true if a fighter is removed; false otherwise.
*/
bool Arena::removeFighter(string name)
{
	for (int i = 0; i < fighters.size(); i++)
	{
		if (fighters[i]->getName() == name)
		{
			fighters.erase(fighters.begin() +i); 
			return true;
		}
	}
	return false;
}

FighterInterface* Arena::getFighter(string name)
{
	for (int i = 0; i < fighters.size(); i++)
	{
		if (fighters[i]->getName() == name)
			return fighters[i];
	}
		return NULL;
}

int Arena::getSize() const
{
	return fighters.size();
}


Arena::~Arena()
{
}
