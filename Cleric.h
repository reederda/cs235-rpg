#pragma once
#include "Fighter.h"
class Cleric :
	public Fighter
{
protected:
	int mana = 0;


public:
	Cleric(string name_in, int hitPoints_in, int strength_in, int speed_in, int magic_in);
	int getDamage();
	void reset();
	void regenerate();
	bool useAbility();
	~Cleric();
};

