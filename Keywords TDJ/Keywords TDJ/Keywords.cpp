/*
Travis Downey Jr.

CSC215

Assignment: Keywords - Building Code Breaker Training Simulation
Program for CIA Recruits

November 18, 2019
*/

#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {
	enum fields {CODE,HINT,NUM_FIELDS}; //enumeration fields to hold the amount of code words and their respective hints
	const int NUM_CODES = 10; //constant int variable set to 10
	const string CODES[NUM_CODES][NUM_FIELDS] = {
		{"saber", "A type of sword."},
		{"biology", "A field of science dealing with living creatures."},
		{"contract", "Document two or more people or businesses enter in a professional agreement."},
		{"tomahawk", "A kind of throwing axe."},
		{"guitar", "A six-string instrument that has acoustic and electric forms."},
		{"joker", "A type of card in a card deck and a well known Batman villain."},
		{"flamingo", "A tropical bird that feeds on small crustaceans, has pink or white feathers, and is known for standing on one leg."},
		{"processor", "Central unit of all computers, is in charge of keeping the computer running at its best performance possible."},
		{"water", "Covers 71% of Earth's surface, most of which is undrinkable due high sodium content."},
		{"magic", "Something that is unexplainable by science, used in Fantasy books and games to give people extraordinary powers."},
	};

	srand(static_cast<unsigned int>(time(0)));
	int choice1 = (rand() % NUM_CODES);
	string chosenCode1 = CODES[choice1][CODE]; //Code word the person needs to guess
	string chosenHint1 = CODES[choice1][HINT]; //Corresponding hint with the chosen code word

	int choice2 = (rand() % NUM_CODES);
	string chosenCode2 = CODES[choice2][CODE]; //Second code word the person needs to guess
	string chosenHint2 = CODES[choice2][HINT]; //Correspoding hint with the second chosen code

	int choice3 = (rand() % NUM_CODES);
	string chosenCode3 = CODES[choice3][CODE]; //Third code word the person needs to guess
	string chosenHint3 = CODES[choice3][HINT]; //Corresponding hint with the third chosen code

	//Scramble the first chosen code word
	string scramble1 = chosenCode1; //string variable to hold the scramble code word
	int length1 = scramble1.size();
	for (int i = 0; i < length1; i++) {
		int index1 = (rand() % length1);
		int index2 = (rand() % length1);
		char temp = scramble1[index1];
		scramble1[index1] = scramble1[index2];
		scramble1[index2] = temp;
	}

	//Scramble the second chosen code word
	string scramble2 = chosenCode2;
	int length2 = scramble2.size();
	for (int i = 0; i < length2; i++) {
		int index1 = (rand() % length2);
		int index2 = (rand() % length2);
		char temp = scramble2[index1];
		scramble2[index1] = scramble2[index2];
		scramble2[index2] = temp;
	}

	//Scramble the third chosen code word
	string scramble3 = chosenCode3;
	int length3 = scramble3.size();
	for (int i = 0; i < length3; i++) {
		int index1 = (rand() % length3);
		int index2 = (rand() % length3);
		char temp = scramble3[index1];
		scramble3[index1] = scramble3[index2];
		scramble3[index2] = temp;
	}

	cout << "\tWelcome to the Code Breaker\n\n";
	cout << "Unscramble the code word to crack the code.\n";
	cout << "Enter 'hint' for a hint\n";
	cout << "The code is: " << scramble1;

	string guess1;
	cout << "\nYour guess: ";
	cin >> guess1;

	float incorrectGuess{};
	float correctGuess{};

	while (guess1 != chosenCode1) {
		if (guess1 == "hint") {
			cout << chosenHint1;
		}
		else {
			cout << "Incorrect answer";
			incorrectGuess++;
		}
		cout << "\nYour guess: ";
		cin >> guess1;
	}

	if (guess1 == chosenCode1) {
		cout << "\nCorrect answer";
		correctGuess++;
	}

	
	cout << "\nNow for the second code word.";
	cout << "\nThe second code word is: " << scramble2;
	string guess2;
	cout << "\nYour guess: ";
	cin >> guess2;

	while (guess2 != chosenCode2) {
		if (guess2 == "hint") {
			cout << chosenHint2;
		}
		else {
			cout << "Incorrect answer";
			incorrectGuess++;
		}
		cout << "\nYour guess: ";
		cin >> guess2;
	}

	if (guess2 == chosenCode2) {
		cout << "\nCorrect answer";
		correctGuess++;
	}

	cout << "\nNow to guess the final word.";
	cout << "\nThe third and final code word is: " << scramble3;
	string guess3;
	cout << "\nYour guess: ";
	cin >> guess3;

	while (guess3 != chosenCode3) {
		if (guess3 == "hint") {
			cout << chosenHint3;
		}
		else {
			cout << "Incorrect answer";
				incorrectGuess++;
		}
		cout << "\nYour guess: ";
		cin >> guess3;
	}

	if (guess3 == chosenCode3) {
		cout << "\nCorrect answer";
		correctGuess++;
	}

	float percent = ((correctGuess / incorrectGuess) * 100);


	cout << "\nTraining complete.";
	cout << "\nStats: " << percent << "%";
}