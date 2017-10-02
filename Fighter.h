#pragma once
#include "FighterInterface.h"
using namespace std;

class Fighter :
	public FighterInterface
{
protected:
	string name = "";
	int hitPoints = 0;
	int strength = 0;
	int speed = 0;
	int magic = 0;
	int currentHP = 0;
	int newStrength = 0;

public:

	
	Fighter(string name_in, int hitPoints_in, int strength_in, int speed_in, int magic_in);
	string getName() const;
	int getMaximumHP() const;
	int getCurrentHP() const;
	int getStrength() const;
	int getSpeed() const;
	int getMagic() const;
	int getDamage(); //int damage
	void takeDamage(int damage);
	void reset();
	void regenerate();
	bool useAbility();

	~Fighter();
};

