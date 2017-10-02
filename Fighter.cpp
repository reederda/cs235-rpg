#include "Fighter.h"
#include <iostream>
using namespace std;

Fighter::Fighter(string name_in, int hitPoints_in, int strength_in, int speed_in, int magic_in)
{
	name = name_in;
	hitPoints = hitPoints_in;
	currentHP = hitPoints;
	speed = speed_in;
	magic = magic_in;
	strength = strength_in;
	//newStrength = strength;
}

string Fighter::getName() const
{
	return name;
}
int Fighter::getMaximumHP() const
{
	return hitPoints;
}
int Fighter::getCurrentHP() const
{
	return currentHP;
}
int Fighter::getStrength() const
{
;	return strength;
}
int Fighter::getSpeed() const
{
	return speed;
}
int Fighter::getMagic() const
{
	return magic;
}
int Fighter::getDamage() //int damage
{
		return 0; //damage
}
void Fighter::takeDamage(int damage)
{
	int totalDamage = damage;
//	cout << "\nIncoming takeDamage is " << damage;
	totalDamage -= speed / 4;
//	cout << "\nSpeed = " << speed;
//	cout << "\nAdjusted totalDamage is " << totalDamage;
	if (totalDamage < 1)
	{
		totalDamage = 1;
		currentHP -= totalDamage;
//		cout << "\nFighter class received Final Adjusted damage of " << totalDamage;
	}
	else
	{
		currentHP -= totalDamage;
//		cout << "\nFighter class received Final damage of " << totalDamage;// << " in, currentHP is " << currentHP << " before attack ";
	}

}
void Fighter::reset()
{
//	cout << "\nBefore reset in fighter class, currentHP is " << currentHP;
	currentHP = hitPoints;
//	strength = newStrength;
//	cout << "\nAfter reset, currentHP is " << currentHP;
}
void Fighter::regenerate()
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
}
bool Fighter::useAbility()
{
	return true;
}

Fighter::~Fighter()
{
}
