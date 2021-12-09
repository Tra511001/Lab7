#include "BattleShip.h"
#include <iostream>
#include <iomanip>
#include <string>
#include <random>
#include <stdio.h>
#include <stdlib.h>
#include <ctime>

using namespace std;

bool BattleShip::checkArray()
{
	for (int row = 0; row < 10;row++) {
		for (int col = 0; col < 10; col++) {
			if (setupArr[row][col] == '#') {
				return false;
			}
		}
	}
	return true;
}

void BattleShip::StartNewGame(){

	for (int row = 0; row < 10; row++) {
		for (int col = 0; col < 10; col++) {
			setupArr[row][col] = '~';
			attackArr[row][col] = '~';
		}
	}
}

void BattleShip::getSetupGrid() { // his was changed in git hub
	int a[10];
	a[0] = 1;
	for (int i = 1; i < 10; i++) {
		a[i] = i + 1;
	}
	cout << "  1 2 3 4 5 6 7 8 9 10" << endl;
	for (int row = 0; row < 10; row++) {
		if (row != 9)
			cout << a[row] << "  ";
		else
			cout << a[row] << " ";
		for (int col = 0; col < 10; col++) {
			cout << setupArr[row][col] << " ";
		}
		cout << endl;
	}
}

void BattleShip::getAttackGrid() { //this was changed in git hub couldnt figure out how to update the code
	int a[10];
	a[0] = 1;
	for (int i = 1; i < 10; i++) {
		a[i] = i + 1;
	}
	cout << "  1 2 3 4 5 6 7 8 9 10" << endl;
	for (int row = 0; row < 10; row++) {
		if (row != 9)
			cout << a[row] << "  ";
		else
			cout << a[row] << " ";
		for (int col = 0; col < 10; col++) {
			cout << setupArr[row][col] << " ";
		}
		cout << endl;
	}
}

bool BattleShip::placeCarrier(int x, int y, char d)
{
	switch (tolower(d)) {
	case 'u': 
		if (x - 4 >= 0) {// ifstatemnt prevents the boats from going out of bounds, x is already decremented by one(this is done by checkInput())
			for (int i = 0; i < 5; i++) {
				setupArr[x - i][y] = '#';
			}
			return true;
		}
		else
			return false;
	case 'd':
		if (x + 5 <= 10) {
			for (int i = 0; i < 5; i++) {
				setupArr[x + i][y] = '#';
			}
			return true;
		}
		else
			return false;
	
	case 'l':
		if (y-4 >=0) {// ifstatemnt prevents the boats from going out of bounds, y is already decremented by one(this is done by checkInput())
			for (int i = 0; i < 5; i++) {
				setupArr[x][y - i] = '#';
			}
			return true;
		}
		else
			return false;
	case 'r':
		if (y + 5 <= 10) {
			for (int i = 0; i < 5; i++) {
				setupArr[x][y + i] = '#';
			}
			return true;
		}
		else
			return false;
	default: "error with placing carrier ship";
		return false;
	}
	return true;
}

bool BattleShip::placeBattleship(int x, int y, char d)
{
	switch (tolower(d)) {
	case 'u': 
		if (x-3 >=0) {// ifstatemnt prevents the boats from going out of bounds, x is already decremented by one(this is done by checkInput())
			for (int i = 0; i < 4; i++) {
				if (setupArr[x - i][y] != '#') {// this if statement makes sure the boats dont overlap 
					setupArr[x - i][y] = '#';
				}
				else
					return false;
			}
			return true;
		}
		else
			return false;
	case 'd':
		if (x + 4 <=10) {
			for (int i = 0; i < 4; i++) {
				if (setupArr[x + i][y] != '#') {
					setupArr[x + i][y] = '#';
				}
				else
					return false;
			}
			return true;
		}
		else
			return false;
	case 'l':
		if (y-3 >=0) {
			for (int i = 0; i < 4; i++) {
				if (setupArr[x][y-i] != '#') {
					setupArr[x][y - i] = '#';
				}
				else
					return false;
			}
			return true;
		}
		else
			return false;
	case 'r':
		if (y+4 <=10) {
			for (int i = 0; i < 4; i++) {
				if (setupArr[x][y + i] != '#') {
					setupArr[x][y + i] = '#';
				}
				else
					return false;
			}
			return true;
		}
		return false;
	default: "error with placing Battleship";
		return false;
	}
}

bool BattleShip::placeCruiser(int x, int y, char d)
{
	switch (tolower(d)) {
	case 'u': 
		if (x-2 >=0) {
			for (int i = 0; i < 3; i++) {
				if (setupArr[x - i][y] != '#') {
					setupArr[x - i][y] = '#';
				}
				else
					return false;
			}
			return true;
		}
		else
			return false;
	case 'd':
		if (x+3 <=10) {
			for (int i = 0; i < 3; i++) {
				if (setupArr[x + i][y] != '#') {
					setupArr[x + i][y] = '#';
				}
				else
					return false;
			}
			return true;
		}
		else
			return false;
	case 'l':
		if (y - 2 >= 0) {
			for (int i = 0; i < 3; i++) {
				if (setupArr[x][y - i] != '#') {
					setupArr[x][y - i] = '#';
				}
				else
					return false;
			}
			return true;
		}
		else
			return false;
	case 'r':
		if (y + 3 <=10) {
			for (int i = 0; i < 3; i++) {
				if (setupArr[x][y + i] != '#') {
					setupArr[x][y + i] = '#';
				}
				else
					return false;
			}
			return true;
		}
		else
			return false;
	default: "error with placing Cruiser";
		return false;
	}
}

bool BattleShip::PlaceSub(int x, int y, char d)
{
	switch (tolower(d)) {
	case 'u':
		if (x - 2 >= 0) {
			for (int i = 0; i < 3; i++) {
				if (setupArr[x - i][y] != '#') {
					setupArr[x - i][y] = '#';
				}
				else
					return false;
			}
			return true;
		}
		else
			return false;
	case 'd':
		if (x + 3 <= 10) {
			for (int i = 0; i < 3; i++) {
				if (setupArr[x + i][y] != '#') {
					setupArr[x + i][y] = '#';
				}
				else
					return false;
			}
			return true;
		}
		else
			return false;
	case 'l':
		if (y - 2 >= 0) {
			for (int i = 0; i < 3; i++) {
				if (setupArr[x][y - i] != '#') {
					setupArr[x][y - i] = '#';
				}
				else
					return false;
			}
			return true;
		}
		else
			return false;
	case 'r':
		if (y + 3 <= 10) {
			for (int i = 0; i < 3; i++) {
				if (setupArr[x][y + i] != '#') {
					setupArr[x][y + i] = '#';
				}
				else
					return false;
			}
			return true;
		}
		else
			return false;
	default: "error with placing Submarine";
		return false;
	}
}

bool BattleShip::placeDestroyer(int x, int y, char d)
{
	switch (tolower(d)) {
	case 'u': 
		if (x - 1 >= 0) {
			for (int i = 0; i < 2; i++) {
				if (setupArr[x - i][y] != '#') {
					setupArr[x - i][y] = '#';
				}
				else
					return false;
			}
			return true;
		}
		else
			return false;
	case 'd':
		if (x+2 <=10) {
			for (int i = 0; i < 2; i++) {
				if (setupArr[x + i][y] != '#') {
					setupArr[x + i][y] = '#';
				}
				else
					return false;
			}
			return true;
		}
		else
			return false;
	case 'l':
		if (y-1 >=0) {
			for (int i = 0; i < 2; i++) {
				if (setupArr[x][y - i] != '#') {
					setupArr[x][y - i] = '#';
				}
				else
					return false;
			}
			return true;
		}
		else
			return false;
	case 'r':
		if (y + 2 <= 10) {
			for (int i = 0; i < 2; i++) {
				if (setupArr[x][y + i] != '#') {
					setupArr[x][y + i] = '#';
				}
				else
					return false;
			}
			return true;
		}
		else
			return false;
	default: "error with placing Destroyer";
		return false;
	}
}

bool BattleShip::attack(int x, int y)
{
	if (setupArr[x-1][y-1] == '#') { // the reason the values are -1 is because the user i/o is set to be 1-10
		cout << endl <<" HIT" << endl;
		setupArr[x - 1][y - 1] = 'H';
		
		return true;
	}
	else {
		cout << endl << "MISS" << endl;
		setupArr[x - 1][y - 1] = 'M';
	}
		
	return false;
}

void BattleShip::attack2(int x, int y, bool x1) {
	if (x1) {
		attackArr[x-1][y-1] = 'H';// the reason the values are -1 is because the user i/o is set to be 1-10
	}
	else {
		attackArr[x-1][y-1] = 'M';
	}
}

void BattleShip::randomGrid() {

	srand(time(0));
	int theNumber = (rand() % 10);
	int theNumber2 = (rand() % 10);
	//CARRIER PLACEMENT WHILE LOOP BLOCK
	while (true) {
		if (setupArr[theNumber][theNumber2] == '~') {
			
			// ***********Check down 5 spots
			if (setupArr[theNumber + 1][theNumber2] == '~' && theNumber + 1 < 10
				&& setupArr[theNumber + 2][theNumber2] == '~' && theNumber + 2 < 10
				&& setupArr[theNumber + 3][theNumber2] == '~' && theNumber + 3 < 10
				&& setupArr[theNumber + 4][theNumber2] == '~' && theNumber + 4 < 10) {
				for (int i = 0; i < 5; i++) {
					setupArr[theNumber + i][theNumber2] = '#';
				}
				break;
			}
			//Check right 5 spots
			if (setupArr[theNumber][theNumber2 + 1] == '~' && theNumber2 + 1 < 10
				&& setupArr[theNumber][theNumber2 + 2] == '~' && theNumber2 + 2 < 10
				&& setupArr[theNumber][theNumber2 + 3] == '~' && theNumber2 + 3 < 10
				&& setupArr[theNumber][theNumber2 + 4] == '~' && theNumber2 + 4 < 10) {
				for (int i = 0; i < 5; i++) {
					setupArr[theNumber][theNumber2 + i] = '#';
				}
				break;
			}
			//Check up 5 spots
			if (setupArr[theNumber - 1][theNumber2] == '~' && theNumber - 1 >= 0
				&& setupArr[theNumber - 2][theNumber2] == '~' && theNumber - 2 >= 0
				&& setupArr[theNumber - 3][theNumber2] == '~' && theNumber - 3 >= 0
				&& setupArr[theNumber - 4][theNumber2] == '~' && theNumber - 4 >= 0) {
				for (int i = 0; i < 5; i++) {
					setupArr[theNumber - i][theNumber2] = '#';
				}
				break;
			}
			//Check left 5 spots
			if (setupArr[theNumber][theNumber2 - 1] == '~' && theNumber2 - 1 >= 0
				&& setupArr[theNumber][theNumber2 - 2] == '~' && theNumber2 - 2 >= 0
				&& setupArr[theNumber][theNumber2 - 3] == '~' && theNumber2 - 3 >= 0
				&& setupArr[theNumber][theNumber2 - 4] == '~' && theNumber2 - 4 >= 0) {
				for (int i = 0; i < 5; i++) {
					setupArr[theNumber][theNumber2 - i] = '#';
				}
				break;
			}
			else {
				theNumber = (rand() % 10);
				theNumber2 = (rand() % 10);
			}
		}
		else {
			theNumber = (rand() % 10);
			theNumber2 = (rand() % 10);
		}
	}
	//BATTLESHIP PLACEMENT WHILE LOOP BLOCK
	while (true) {
		if (setupArr[theNumber][theNumber2] == '~') {
			// ***********Check down 3 spots
			if (setupArr[theNumber + 1][theNumber2] == '~' && theNumber + 1 < 10
				&& setupArr[theNumber + 2][theNumber2] == '~' && theNumber + 2 < 10
				&& setupArr[theNumber + 3][theNumber2] == '~' && theNumber + 3 < 10) {
				for (int i = 0; i < 4; i++) {
					setupArr[theNumber + i][theNumber2] = '#';
				}
				break;
			}
			//Check right 3 spots
			if (setupArr[theNumber][theNumber2 + 1] == '~' && theNumber2 + 1 < 10
				&& setupArr[theNumber][theNumber2 + 2] == '~' && theNumber2 + 2 < 10
				&& setupArr[theNumber][theNumber2 + 3] == '~' && theNumber2 + 3 < 10) {
				for (int i = 0; i < 4; i++) {
					setupArr[theNumber][theNumber2 + i] = '#';
				}
				break;
			}
			//Check up 3 spots
			if (setupArr[theNumber - 1][theNumber2] == '~' && theNumber - 1 >= 0
				&& setupArr[theNumber - 2][theNumber2] == '~' && theNumber - 2 >= 0
				&& setupArr[theNumber - 3][theNumber2] == '~' && theNumber - 3 >= 0) {
				for (int i = 0; i < 4; i++) {
					setupArr[theNumber - i][theNumber2] = '#';
				}
				break;
			}
			//Check left 3 spots
			if (setupArr[theNumber][theNumber2 - 1] == '~' && theNumber2 - 1 >= 0
				&& setupArr[theNumber][theNumber2 - 2] == '~' && theNumber2 - 2 >= 0
				&& setupArr[theNumber][theNumber2 - 3] == '~' && theNumber2 - 3 >= 0) {
				for (int i = 0; i < 4; i++) {
					setupArr[theNumber][theNumber2 - i] = '#';
				}
				break;
			}
			else {
				theNumber = (rand() % 10);
				theNumber2 = (rand() % 10);
			}
		}
		else {
			theNumber = (rand() % 10);
			theNumber2 = (rand() % 10);
		}
	}
	//***************************************CRUISER PLACEMENT WHILE LOOP BLOCK
	while (true) {
		if (setupArr[theNumber][theNumber2] == '~') {
			// ***********Check down 2 spots
			if (setupArr[theNumber + 1][theNumber2] == '~' && theNumber + 1 < 10
				&& setupArr[theNumber + 2][theNumber2] == '~' && theNumber + 2 < 10) {
				for (int i = 0; i < 3; i++) {
					setupArr[theNumber + i][theNumber2] = '#';
				}
				break;
			}
			//Check right 2 spots
			if (setupArr[theNumber][theNumber2 + 1] == '~' && theNumber2 + 1 < 10
				&& setupArr[theNumber][theNumber2 + 2] == '~' && theNumber2 + 2 < 10) {
				for (int i = 0; i < 3; i++) {
					setupArr[theNumber][theNumber2 + i] = '#';
				}
				break;
			}
			//Check left 2 spots
			if (setupArr[theNumber][theNumber2 - 1] == '~' && theNumber2 - 1 >= 0
				&& setupArr[theNumber][theNumber2 - 2] == '~' && theNumber2 - 2 >= 0) {
				for (int i = 0; i < 3; i++) {
					setupArr[theNumber][theNumber2 - i] = '#';
				}
				break;
			}
			//Check up 2 spots
			if (setupArr[theNumber - 1][theNumber2] == '~' && theNumber - 1 >= 0
				&& setupArr[theNumber - 2][theNumber2] == '~' && theNumber - 2 >= 0) {
				for (int i = 0; i < 3; i++) {
					setupArr[theNumber - i][theNumber2] = '#';
				}
				break;
			}
			else {
				theNumber = (rand() % 10);
				theNumber2 = (rand() % 10);
			}
		}
		else {
			theNumber = (rand() % 10);
			theNumber2 = (rand() % 10);
		}
	}
	// SUB PLACEMENT WHILE LOOP BLOCK
	while (true) {
		if (setupArr[theNumber][theNumber2] == '~') {
			// ***********Check down 2 spots
			if (setupArr[theNumber + 1][theNumber2] == '~' && theNumber + 1 < 10
				&& setupArr[theNumber + 2][theNumber2] == '~' && theNumber + 2 < 10) {
				for (int i = 0; i < 3; i++) {
					setupArr[theNumber + i][theNumber2] = '#';
				}
				break;
			}
			//Check right 2 spots
			if (setupArr[theNumber][theNumber2 + 1] == '~' && theNumber2 + 1 < 10
				&& setupArr[theNumber][theNumber2 + 2] == '~' && theNumber2 + 2 < 10) {
				for (int i = 0; i < 3; i++) {
					setupArr[theNumber][theNumber2 + i] = '#';
				}
				break;
			}
			//check up 2 spots
			if (setupArr[theNumber - 1][theNumber2] == '~' && theNumber - 1 >= 0
				&& setupArr[theNumber - 2][theNumber2] == '~' && theNumber - 2 >= 0) {
				for (int i = 0; i < 3; i++) {
					setupArr[theNumber - i][theNumber2] = '#';
				}
				break;
			}
			//Check left 2 spots
			if (setupArr[theNumber][theNumber2 - 1] == '~' && theNumber2 - 1 >= 0
				&& setupArr[theNumber][theNumber2 - 2] == '~' && theNumber2 - 2 >= 0) {
				for (int i = 0; i < 3; i++) {
					setupArr[theNumber][theNumber2 - i] = '#';
				}
				break;
			}
			else {
				theNumber = (rand() % 10);
				theNumber2 = (rand() % 10);
			}
		}
		else {
			theNumber = (rand() % 10);
			theNumber2 = (rand() % 10);
		}
	}
	// DESTROYER PLACEMENT WHILE LOOP BLOCK
	while (true) {
		if (setupArr[theNumber][theNumber2] == '~') {
			// ***********Check down 2 spots
			if (setupArr[theNumber + 1][theNumber2] == '~' && theNumber + 1 < 10) {
				for (int i = 0; i < 2; i++) {
					setupArr[theNumber + i][theNumber2] = '#';
				}
				break;
			}
			//Check right 2 spots
			if (setupArr[theNumber][theNumber2 + 1] == '~' && theNumber2 + 1 < 10) {
				for (int i = 0; i < 2; i++) {
					setupArr[theNumber][theNumber2 + i] = '#';
				}
				break;
			}
			//check up 2 spots
			if (setupArr[theNumber - 1][theNumber2] == '~' && theNumber - 1 >= 0) {
				for (int i = 0; i < 2; i++) {
					setupArr[theNumber - i][theNumber2] = '#';
				}
				break;
			}
			//Check left 2 spots
			if (setupArr[theNumber][theNumber2 - 1] == '~' && theNumber2 - 1 >= 0) {
				for (int i = 0; i < 2; i++) {
					setupArr[theNumber][theNumber2 - i] = '#';
				}
				break;
			}
			else {
				theNumber = (rand() % 10);
				theNumber2 = (rand() % 10);
			}
		}
		else {
			theNumber = (rand() % 10);
			theNumber2 = (rand() % 10);
		}
	}
}

