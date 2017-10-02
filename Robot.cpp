#include "Robot.h"
#include <math.h>
#include <stdio.h>


Robot::Robot(string name_in, int hitPoints_in, int strength_in, 
int speed_in, int magic_in):Fighter(name_in, hitPoints_in, strength_in, speed_in, magic_in)
{
	maxEnergy = magic * 2;
	energy = maxEnergy;
}

int Robot::getDamage()
{
int newDamage = strength + bonusDamage;
bonusDamage = 0;
//		cout << "\nsetting bonusdamage to 0";
//	cout << "\nRobot dealt " << strength << " + " << bonusDamage << " damage.";
//	useabilityused = true;
	return newDamage;
}

void Robot::reset()
{
	energy = magic * 2; //max energy
	bonusDamage = 0;
	currentHP = Fighter::hitPoints;
}

bool Robot::useAbility() //Add in ability
{
	
	
//	cout << "\nRobot::useAbility triggered";
	if (energy >= ROBOT_ABILITY_COST)
	{
		useabilityused = false;
		bonusDamage = 0;
		
/*		if (currentHP > hitPoints)
		{
			currentHP = hitPoints;
		}
*/
//		cout << "\nEnergy: " << energy << "\nMAxEnergy: " << maxEnergy << "\nstrength: " << strength;
		double tempenergy = energy / (double)maxEnergy;
//		cout << "\ntempenergy is " << tempenergy;
		double tempstrength = strength;
		double newDamage = (tempstrength  * pow(tempenergy,4));
//		cout << "\newdamage: " << newDamage;
		energy -= ROBOT_ABILITY_COST;
		
		int finalDamage = newDamage;
		bonusDamage = finalDamage;
//		cout << "\nFinal Damage: " << finalDamage << "\nbonusDamage: " << bonusDamage;
		return true;
	}
	else
	{
		return false;
	}
	return 0;
}

Robot::~Robot()
{
}
