// You name here (NO NAME, NO CREDIT): Andrew Le

#include <iostream>
#include <random>
#include <string>
#include <stdlib.h>
using namespace std;

// Function Prototypes
int GetRandomNumber(int floor, int ceiling);
void ExitGame();
void DisplayOptions();
int EnterCommand(string prompt);
void ProcessCommand(int choice);

int score;				// Global

int main() {
	// DO NOT MODIFY THE CODE INSIDE OF THE MAIN FUNCTION!
	score = 0;
	cout << "ROCK, PAPER, SCISSORS GAME\n" << endl;
	while (1) {
		DisplayOptions();
		int choice = EnterCommand("Enter Choice: ");
		ProcessCommand(choice);
	}
	// END OF MAIN FUNCTION
}

/* This function will display the options for the game input */
void DisplayOptions() {
	// TODO
	cout << "Score: " << score << endl;
	cout << "1. Rock" << endl;
	cout << "2. Paper" << endl;
	cout << "3. Scissors" << endl;
	cout << "4. Exit" << endl;	
}

/* This function should display the prompt and be capable of retrieving integer values from the keyboard */
int EnterCommand(string prompt) {
	// TODO
	int input;
	cout << prompt;
	cin >> input;
	return input;
}

/* This function interprets the data that was received from the EnterCommand function. */
void ProcessCommand(int choice) {
	// TODO
	if (choice < 1 || choice > 4) {
		cout << "Invalid Choice" << endl;
		return;
	}

	if (choice == 4) {
		ExitGame();
	}

	int computerChoice = GetRandomNumber(1, 3);

	string computerChoiceName;
	if (computerChoice == 1) {
		computerChoiceName = "Rock";
	}
	else if (computerChoice == 2) {
		computerChoiceName = "Paper";
	}
	else {
		computerChoiceName = "Scissors";
	}

	if (choice == computerChoice) {
		cout << "Computer chose " << computerChoiceName << ": You tie!" << endl;
		return;
	}

	bool playerWins = false;

	if (choice == 1 && computerChoice == 3) {
		playerWins = true;
	}
	else if (choice == 2 && computerChoice == 1) {
		playerWins = true;
	}
	else if (choice == 3 && computerChoice == 2) {
		playerWins = true; 
	}

	if (playerWins) {
		cout << "Computer chose " << computerChoiceName << ": You win!" << endl;
		score++;
	}
	else {
		cout << "Computer chose " << computerChoiceName << ": You lose!" << endl;
		score--;
	}

}

/* Helper method to exit game from anywhere (DO NOT MODIFY!) */
void ExitGame() {
	exit(EXIT_SUCCESS);
}

/* Helper function to generate a random number (DO NOT MODIFY!) */
int GetRandomNumber(int floor, int ceiling) {
	if (floor >= ceiling)					return -1;	// Set error code if arguments are improper
	std::random_device r;
	std::default_random_engine e1(r());
	std::uniform_int_distribution<int> uniform_dist(floor, ceiling);
	int ret = uniform_dist(e1);
	return ret;
}