#pragma once
#include "Fighter.h"
class Robot :

	public Fighter
{
protected:
	int energy = 0;
	int maxEnergy = 0;
	int bonusDamage = 0;
	bool useabilityused = true;

public:
	Robot(string name_in, int hitPoints_in, int strength_in, int speed_in, int magic_in);
	int getDamage();
	void reset();
	bool useAbility();
	~Robot();
};

