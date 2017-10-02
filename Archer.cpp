#include "Archer.h"
#include <cmath>

Archer::Archer(string name_in, int hitPoints_in, int strength_in, int speed_in, int magic_in):Fighter(name_in, hitPoints_in, strength_in, speed_in, magic_in)
{
	respeed = speed_in;
//	cout << "\nArcher's initial speed is: " << speed;
}

int Archer::getDamage()
{

//	cout << "\noutgoing takeDamage is " << damage;

//	cout << "\nArcher's getDamage initial speed is: " << speed;
	if (speed < 1)
	{
//		cout << "\nSending Final Adjusted damage of " << speed;
		return 1;
	}
	else
	{
//		cout << "\nSending Final damage of " << speed;// << " in, currentHP is " << currentHP << " before attack ";
		return speed;

	}
}

void Archer::reset()
{
//	cout << "\narcher reset called";
	speed = respeed;
	currentHP = Fighter::hitPoints;
}

bool Archer::useAbility()
{
//	cout << "\nArcher::useAbility triggered";
	speed++;
	return speed;
}


Archer::~Archer()
{
}
