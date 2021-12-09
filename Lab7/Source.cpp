#include "BattleShip.h"
#include <iomanip>
#include <string>
#include <iostream>
#include <random>
#include <stdio.h>
#include <stdlib.h>
#include <ctime>

using namespace std;
/*

	Nikola Trajanovski
	Lab7
	Due: 12/08/2021

	This battleship game is based on a 10x10 grid. It starts of with the user placeing his ships, with an initial coordinate and then 
	the direction in which the ships will face. Then the user chooses a spot to shoot at based on that the program will return HIT/MISS.
	If its a hit then the user/computer get an extra try.

*/
bool checkInput(int& x, int& y, char d);
//Post: Check if the parameters are within the bounds of the grid and checks if the char parameter is a valid char.
//		Also decrements x and y by 1, because the user will input numbers 1-10, and the arrays work with numbers 0-9

BattleShip Computer;
BattleShip User;
int main() {
	int x =0; // x variable for x coordinate on grid
	int y= 0;// y variable for y coordinate on grid
	string direction;// direction in which the user places his ship
	char playAgain = 'y'; // variable that controls the while loop
	bool won = true;// bool won, is logical expression that controls the last nested while loop(this loop controls the fire/winning/losing portion of the game)

	while (playAgain != 'n') {
		cout << "Do you want to start a new game(y/n)? "<<endl;
		cin >> playAgain;

		//ends the program if something other than y is entered
		if (playAgain == 'n')
			break;
		else if (playAgain != 'y' && playAgain != 'n')
			break;


		switch (tolower(playAgain)) {
		case 'y': 
		
				//zero out arrays
				Computer.StartNewGame();
				User.StartNewGame();

				Computer.randomGrid();

				//preview
				//Computer.getSetupGrid(); //prints out the computers grid of boats beforehand for error checks
				User.getSetupGrid();
				cout << endl;
				cout << endl << endl << endl;
				
				cout << "This game works by entering coordinates x and y (1-10) on the grid" << endl;
				cout << "Enter the initial grid coordinates (x, y) of your Carrier, \nand state the direction in which it faces(rigth, left, up, down)" << endl;
				cin >> x >> y >> direction;
				if (checkInput(x, y, direction.at(0)) && User.placeCarrier(x, y, direction.at(0))) {
					User.placeCarrier(x, y, direction.at(0));
				}
				else {
					won = false;
					cout << "Coordinates invalid or out of bounds" << endl;
					break;
				}
				User.getSetupGrid();
				
				cout << endl << "Enter the initial grid coordinates (x, y) of your Battleship, \nand state the direction in which it faces(rigth, left, up, down)" << endl;
				cin >> x >> y >> direction;
				if (checkInput(x, y, direction.at(0)) && User.placeBattleship(x, y, direction.at(0))) {
					User.placeBattleship(x, y, direction.at(0));
				}
				else {
					won = false;
					cout << "Coordinates invalid or out of bounds" << endl;
					break;
				}
				User.getSetupGrid();
				
				cout << endl << "Enter the initial grid coordinates (x, y) of your Cruiser, \nand state the direction in which it faces(rigth, left, up, down)" << endl;
				cin >> x >> y >> direction;
				if (checkInput(x, y, direction.at(0)) && User.placeCruiser(x, y, direction.at(0))) {
					User.placeCruiser(x, y, direction.at(0));
				}
				else {
					won = false;
					cout << "Coordinates invalid or out of bounds" << endl;
					break;
				}
				User.getSetupGrid();
				
				cout << endl << "Enter the initial grid coordinates (x, y) of your Submarine, \nand state the direction in which it faces(rigth, left, up, down)" << endl;
				cin >> x >> y >> direction;
				if (checkInput(x, y, direction.at(0)) && User.PlaceSub(x, y, direction.at(0))) {
					User.PlaceSub(x, y, direction.at(0));
				}
				else {
					won = false;
					cout << "Coordinates invalid or out of bounds" << endl;
					break;
				}
				User.getSetupGrid();
				
				cout << endl << "Enter the initial grid coordinates (x, y) of your Destroyer, \nand state the direction in which it faces(rigth, left, up, down)" << endl;
				cin >> x >> y >> direction;
				if (checkInput(x, y, direction.at(0))) {
					User.placeDestroyer(x, y, direction.at(0));
				}
				else {
					won = false;
					cout << "Coordinates invalid or out of bounds" << endl;
					break;
				}
				cout << endl << endl << endl;
				User.getSetupGrid();
				break;
		case 'n': break;
		default: cout << "Please enter y for yes, or n for no";
		}

		//User attacks first:
		
		bool x1;
		string userPreference;
		srand(time(0));
		int randX = 1 + (rand() % 10);
		int randY = 1 + (rand() % 10);
		while (won) {
			cout << "Do you want to fire, view grid or, surrender ?" << endl;
			cin >> userPreference;
			if (userPreference.at(0) == 'f' || userPreference.at(0) == 'v') {
				if (userPreference.at(0) == 'v')
					User.getSetupGrid();
				else if (userPreference.at(0) == 'f') {
					cout << endl << "Enter x, y coordinates to attack ?(1-10)" << endl;
					cin >> x >> y;
					if ((x <= 10 && y <= 10) && (x > 0 && y > 0)) {

						x1 = Computer.attack(x, y);
						User.attack2(x, y, x1);
						User.getAttackGrid();
						if (x1) {
							while (x1) { // could be a infinite loop if user keeps entering the same x y coordinates
								cout << endl;
								if (Computer.checkArray()) {
									cout << "You won ! " << endl;
									won = false;
									break;
								}
								cout << "Next attack : ";
								cin >> x >> y;
								x1 = Computer.attack(x, y);
								User.attack2(x, y, x1);
								User.getAttackGrid();
							}
						}
					}
					else
						cout << "Enter a valid coordinate pls" << endl;
					//*******************************************************************************************
					if (won) {
						randX = 1 + (rand() % 10);
						randY = 1 + (rand() % 10);
						cout << "The computer shot at coordinates: (" << randX << ", " << randY << ")" << endl;;

						x1 = User.attack(randX, randY);
						User.getSetupGrid();
						while (x1) {
							if (User.checkArray()) {
								cout << "Computer won!" << endl;
								won = false;
								break;
							}
							randX = 1 + (rand() % 10);
							randY = 1 + (rand() % 10);
							cout << " Computer will shoot again at cooridnates: (" << randX << ", " << randY << ")" << endl;
							x1 = User.attack(randX, randY);
							User.getSetupGrid();
						}
					}
				}
			}
			else if (userPreference.at(0) == 's') {
				cout << "computer won ! ";
				won = false;
				break;
			}
			else
				cout << "Enter a valid option (fire, view grid, surrender)";
		}
	}
	return 0;
}


bool checkInput(int& x, int& y, char d) {

	d = tolower(d);

	if (d == 'r' || d == 'l' || d == 'd' || d == 'u') { //checks if char is valid
		if ((x >0 && y >0) && (x <= 10 && y <=10)) {//check if x and y are within bounds and decrement them
			x = x - 1;
			y = y - 1;
		}
		else {
			cout << "Enter a valid x/y coordinate (range 1-10)" <<endl << endl;
			User.StartNewGame();
			return false;
		}


	}
	else {
		cout << "Enter a valid direction " << endl << endl;
		User.StartNewGame();
		return false;
	}


	return true;
}