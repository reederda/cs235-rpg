#include "Fighter.h"
#include "ArenaInterface.h"
#include <vector>

class Arena :
	public ArenaInterface
{
protected:
	string nameInfo[100];
	int nameInfoCount = 0;
	string name;
	string type;
	int health;
	int strength;
	int speed;
	int magic;
	vector <Fighter*> fighters;

public:
	
	Arena();
	~Arena();

	/*
	*	addFighter(string)
	*
	*	Adds a new fighter to the collection of fighters in the arena. Do not allow
	*	duplicate names.  Reject any string that does not adhere to the format
	*	outlined in the lab specs.
	*   (name) (type) (maximum hit points) (strength) (speed) (magic)
	*
	*	Return true if a new fighter was added; false otherwise.
	*/
	bool addFighter(string info);

	/*
	*	removeFighter(string)
	*
	*	Removes the fighter whose name is equal to the given name.  Does nothing if
	*	no fighter is found with the given name.
	*
	*	Return true if a fighter is removed; false otherwise.
	*/
	bool removeFighter(string name);

	/*
	*	getFighter(string)
	*
	*	Returns the memory address of a fighter whose name is equal to the given
	*	name.  Returns NULL if no fighter is found with the given name.
	*
	*	Return a memory address if a fighter is found; NULL otherwise.
	*/
	FighterInterface* getFighter(string name);

	/*
	*	getSize()
	*
	*	Returns the number of fighters in the arena.
	*
	*	Return a non-negative integer.
	*/
	int getSize() const;
};
