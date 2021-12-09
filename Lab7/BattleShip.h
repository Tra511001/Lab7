#pragma once

class BattleShip{

	char setupArr[10][10];
	char attackArr[10][10];

public:

	bool checkArray();
	//POST: checks to see if there are any boats on the grid(setupGrid()), returns false if there are, true if there are none.
	void StartNewGame();
	//Post: zero out both 2d arrays
	void randomGrid();
	//Post: Randomly places 5 ships on the grid for the coumputer
	void getSetupGrid();
	//Post: pirnts the setup grid
	void getAttackGrid();
	//post prints the attack plan grid
	bool placeCarrier(int x, int y, char d);
	//Pre: the array has to be zeroed out and the inputs must not overlap
	//Post: The function places a carrier ship(that takes up 5 consecutive spaces) in the array based on the users 
	//		input and also checks if the inputs are within bounds and returns true/false
	bool placeBattleship(int x, int y, char d);
	//Pre: the array has to be zeroed out and the inputs must be valid
	//Post: the function places a BattleShip(that takes up 4 consecutive spaces) in the array based on the users input
	// and also checks if the inputs are within bounds and returns true/false, also prevents ships from overlaping(returns false)
	bool placeCruiser(int x, int y, char d);
	//Pre: the array has to be zeroed out and the inputs must be valid
	//Post: the function places a Cruiser ship(that takes up 3 consecutive spaces) in the array based on the users input
	// and also checks if the inputs are within bounds and returns true/false, also prevents ships from overlaping(returns false)
	bool PlaceSub(int x, int y ,char d);
	//Pre: the array has to be zeroed out and the inputs must be valid
	//Post: the function places a SUb(that takes up 3 consecutive spaces) in the array based on the users input
	// and also checks if the inputs are within bounds and returns true/false, also prevents ships from overlaping(returns false)
	bool placeDestroyer(int x, int y, char d);
	//Pre: the array has to be zeroed out and the inputs must be valid
	//Post: the function places a Destroyer ship(that takes up 2 consecutive spaces) in the array based on the users input
	// and also checks if the inputs are within bounds and returns true/false, also prevents ships from overlaping(returns false)
	bool attack(int x, int y);
	//PRE: have valid coordinates x and y 
	//POST: it checks if the (x, y) coordinate given by parameters is a hit(returns true) or a miss(returns false) and 
	//		changes the setup grid for the object that is calling the function
	void attack2(int x, int y, bool x1);
	//PRE: The same cooridnates that go in attack(), also bool variable x1 holds the return value of attack()
	//POST: This function changes the attack grid for the object calling it, because i couldnt get them to work in one function i had to make two.
};