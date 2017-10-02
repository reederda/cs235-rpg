#include "Cleric.h"


Cleric::Cleric(string name_in, int hitPoints_in, int strength_in, int speed_in, int magic_in):Fighter(name_in, hitPoints_in, strength_in, speed_in, magic_in)
{
	mana = magic * 5;
}

int Cleric::getDamage()
{
//	cout << "\nCleric dealt " << magic << " damage.";
	return magic;
}

void Cleric::reset()
{
	mana = magic * 5;
	currentHP = Fighter::hitPoints;
}

void Cleric::regenerate()
{
	//cout << "\nstrength is currently " << strength;
	//	cout << "\ncurrentHP is currently " << currentHP;
	int hp_before = currentHP;
	if ((strength / 6) < 1)
	{
		//cout << "\nStrength / 6 is less than 1, prior to addition. currentHP is " << currentHP;
		currentHP += 1;
		//cout << "\nafter addition, currentHP is now " << currentHP;
	}
	else
	{
		//cout << "\nprior to else addition, currentHP is " << currentHP;
		currentHP += (strength / 6);
		//cout << "\nafter else addition, currentHP is now " << currentHP;
	}
	//	cout << "\ncurrentHP and hitPoints: " << currentHP << ", " << hitPoints;

	if (currentHP > hitPoints)
	{
		//		cout << "\nequalized currentHP and hitPoints: " << currentHP << ", " << hitPoints;
		currentHP = hitPoints;
	}
	//	cout << "\nCurrentHP became " << currentHP;
	if (hp_before > currentHP)
	{
		//		cout << "\n!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!";
	}


	if ((magic / 5) < 1)
	{
		mana++;
	}
	else mana = mana + (magic / 5);
	if (mana > (magic * 5))
	{
		mana = magic * 5;
	}
}

bool Cleric::useAbility()
{
//	cout << "\nCleric::useAbility triggered";
//	cout << "\nCleric Mana is " << mana;
	if (mana >= CLERIC_ABILITY_COST)
	{
		mana -= CLERIC_ABILITY_COST;
		currentHP += magic / 3;

		if (currentHP > hitPoints)
		{
			currentHP = hitPoints;
		}
//		cout << "\nCleric returning True";
		return true;
	}
	else
	{
//		cout << "\nCleric returning False";
		return false;
	}

}

Cleric::~Cleric()
{
}
