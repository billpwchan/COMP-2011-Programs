/*
 * Submit this source file (pa1.cpp) only
 * Right-click on the project in Eclipse's project explorer and choose "Properties" to see the source file location
 *
 * Follow all the instructions in the comments and the assignment description page very carefully
 */

#include <iostream>
#include <cmath>

using namespace std;

/*
 * You are allowed to add new helper functions,
 * but NO global variables please.
 * Also do NOT modify any of the given variables and constants.
 * Complete all the given functions (except the main function which is already completed and should not be modified)
 * without modifying their names, return types, and formal parameters.
 */

const int ANIMAL_COUNT = 4; // Total number of animals
const int ANIMAL_NAME_MAX_LENGTH = 256; // How long can an animal name be (for array declaration below)

// The animal names; ANIMAL_NAME[0] is "DOG" (we say 0 is the animal index of DOG), and so on
// You probably do not need to use this array in your code
const char ANIMAL_NAME[ANIMAL_COUNT][ANIMAL_NAME_MAX_LENGTH] =
{
	"DOG",
	"CAT",
	"RAT",
	"ELEPHANT"
};

// Map dimensions; for example, the minimum x coordinate is -10 according to the following settings
const int MAP_MIN_X = -10;
const int MAP_MAX_X = 10;
const int MAP_MIN_Y = -20;
const int MAP_MAX_Y = 20;

int myX, myY; // X and Y positions of the player
int animalX[ANIMAL_COUNT]; // X and Y positions of the animals; animalX[0] gives the x position of DOG, and so on
int animalY[ANIMAL_COUNT]; // X and Y positions of the animals; animalY[0] gives the y position of DOG, and so on
int isAnimalCaught[ANIMAL_COUNT]; // Whether an animal has been caught by the player already

/*
 * Return the Euclidean distance between the player and the animal specified by the animalIndex;
 * always round down the result to the nearest int.
 * Hint: use the sqrt function from the cmath library which is already included
 */
int getAnimalDistance(int animalIndex) // Do NOT modify the function name / return type / parameters
{
	return sqrt(pow(animalX[animalIndex] - myX, 2) + pow(animalY[animalIndex] - myY, 2));
}

/*
 * Output (cout) either "CLOSE", "AROUND", or "FAR" based on the distance between the player and the animal specified by its index
 * Distance being less than or equal to 3 is considered as "CLOSE".
 * Distance being more than 3 yet less than or equal to 6 is considered as "AROUND".
 * Other distances are considered as "FAR".
 * Be very careful with the exact spellings.
 * No extra spaces or newlines (e.g. endl or '\n') should be output.
 * Your output must be *exactly* the same as the sample output.
 */
void outputDistanceDescription(int animalIndex) // Do NOT modify the function name / return type / parameters
{
	int distance = getAnimalDistance(animalIndex);
	if (distance > 0 && distance <= 3) {
		cout << "CLOSE";
	} else if (distance > 3 && distance <= 6) {
		cout << "AROUND";
	} else {
		cout << "FAR";
	}
}

/*
 * Return the animal index of the animal that is closest to the player
 */
int getClosestAnimalIndex() // Do NOT modify the function name / return type / parameters
{
	int closet_animal_index = 0, distance=0;
	for (int i = 0; i < ANIMAL_COUNT; i++) {
		distance = getAnimalDistance(i);
		if (distance < getAnimalDistance(closet_animal_index)) {
			if (isAnimalCaught[i] == false) {closet_animal_index = i;}
		}
	}
	return closet_animal_index;
}

/*
 * Return true if (x, y) is valid / inside of the map; return false otherwise
 */
bool isInMap(int x, int y) // Do NOT modify the function name / return type / parameters
{
	if ((x > MAP_MAX_X || x < MAP_MIN_X) && (y > MAP_MAX_Y || y < MAP_MIN_Y)) {
		return false;
	}
	return true;
}

/*
 * Update the isAnimalCaught array and return true if the animal specified by the animal index can be caught,
 * simply return false otherwise.
 */
bool catchAnimal(int animalIndex) // Do NOT modify the function name / return type / parameters
{
	switch (animalIndex) {
	case 0: {
		if (getAnimalDistance(0) >= 0 && getAnimalDistance(0) <= 6) {
			isAnimalCaught[0] = true;
			return true;
		}
		else {return false;}
	} break;

	case 1: {
		if (getAnimalDistance(1) >= 3 && getAnimalDistance(1) <= 6) {
			isAnimalCaught[1] = true;
			return true;
		}
		else {return false;}
	} break;

	case 2: {
		if (getAnimalDistance(2) >= 0 && getAnimalDistance(2) <= 9) {
			isAnimalCaught[2] = true;
			return true;
		}
		else {return false;}
	} break;

	case 3: {
		if (getAnimalDistance(3) >= 0 && getAnimalDistance(3) <= 3) {
			isAnimalCaught[3] = true;
			return true;
		}
		else {return false;}
	}

	default:
		cout << "Unknown error, please try again. " << endl;
		return false;
		break;
	}
}

/*
 * Return the total number of animals that are caught
 */
int countAnimalsCaught() // Do NOT modify the function name / return type / parameters
{
	int count = 0;
	for (int i = 0; i < ANIMAL_COUNT; i++) {
		if (isAnimalCaught[i]) {
			count++;
		}
	}
	return count;
}

/*
 * The entry point of the program;
 * do NOT modify any of it
 */
int main()
{
	// Initialize The isAnimalCaught array - all animals are not caught yet
	for (int i = 0; i < ANIMAL_COUNT; i++)
		isAnimalCaught[i] = false;

	// Print a welcome message
	cout << "Welcome to Pocket Animal!" << endl;
	cout << "What are you gonna catch today? You know, we gotta catch 'em all!" << endl;

	// Ask for the world settings
	cout << endl << "Before we begin, tell us about your world..." << endl;
	cout << "Where are you? [x y]" << endl;
	cin >> myX >> myY;
	for (int i = 0; i < ANIMAL_COUNT; i++)
	{
		cout << "Where is the " << ANIMAL_NAME[i] << "? [x y]" << endl;
		cin >> animalX[i] >> animalY[i];
	}

	// Now here is a loop to keep asking for player actions until option 3 (quit) is selected
	int option = 0;
	while (option != 3)
	{
		cout << endl << "Currently..." << endl << endl;

		// List the animals and their distance description which is either CLOSE, AROUND, or FAR
		for (int i = 0; i < ANIMAL_COUNT; i++)
		{
			if (!isAnimalCaught[i]) // Only list the animals that are not caught yet
			{
				cout << "(" << i << ") " << ANIMAL_NAME[i] << " is ";
				outputDistanceDescription(i);
				cout << "!";
				cout << " (" << getAnimalDistance(i) << " unit(s) away)" << endl;
			}
		}

		// Show which animal is the closest
		cout << ANIMAL_NAME[getClosestAnimalIndex()] << " is closest to you!" << endl;

		// Ask for a player action
		cout << endl << "Now what to do? [1:move OR 2:catch OR 3:quit]" << endl;
		cin >> option;

		if (option == 1) // Move to a new position
		{
			// Ask for the new position
			int x, y;
			cout << "Where to move to? [x y]" << endl;
			cin >> x >> y;

			if (isInMap(x, y)) // only move if the (x, y) is actually in the map
			{
				myX = x;
				myY = y;
				cout << "You have moved to " << myX << " " << myY << "!" << endl << endl;
			}
			else // Do nothing but warn the player otherwise
			{
				cout << "Knowing the move would place you out of the map, you decided to stand still!" << endl;
			}
		}
		else if (option == 2) // Catch an animal
		{
			// Ask for the animal index
			int animalIndex;
			cout << "Which animal to catch? [animal index]" << endl;
			cin >> animalIndex;

			if (catchAnimal(animalIndex)) // If succeeded
			{
				cout << "You have caught " << ANIMAL_NAME[animalIndex] << " !" << endl;
			}
			else // If failed
			{
				cout << ANIMAL_NAME[animalIndex] << " has escaped from you!" << endl;
			}
		}
	}

	// Show the game result and exit
	cout << endl << "You have caught " << countAnimalsCaught() << " of them!" << endl;
	cout << endl << "Bye!" << endl;

	return 0;
}
