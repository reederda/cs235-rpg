#pragma once
#include "Fighter.h"
class Archer :
	public Fighter
{
protected:
	int damage = 0;
	int respeed = 0;

public:
	Archer(string name_in, int hitPoints_in, int strength_in, int speed_in, int magic_in);
	int getDamage();
	void reset();
	bool useAbility();
	~Archer();
};

