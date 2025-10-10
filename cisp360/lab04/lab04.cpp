// Lab04.cpp : This file contains the 'main' function. Program execution begins and ends there.

// Your NAME here: Andrew Le

/* R E Q U I R E M E N T S
1) Call the "DisplayName" function to display the title of the program at the beginning.
2) Call the "GetRandomNumber" function in a looping style of your choosing (while, do/while, for) until the number returned is a multiple of 7
	2a) The number you pick should be between 1 and 100 so you should use these as floor and ceiling values for your function call
	2b) Make sure to track the "count" as you loop. The count is the number of times you have went through the loop while seeking your number
	2c) Make sure to end the loop when you find your number
3) Once you have your number and the loop count, use these values to call the "PrintFinal" function and use count and number as your input values. 
4) Don't forget to put your full name on the comment line above these requirements, for credit. */

#include <iostream>
#include <random>
#include <string>
#include <stdlib.h>
using namespace std;

/* Function Prototypes */
void DisplayName();
int GetRandomNumber(int floor, int ceiling);
void PrintFinal(int count, int number);

int main()
{
	// TODO: Do ALL of your coding inside this main function. Do NOT change any of the custom function code below. Zero points for assignment if you do.
	DisplayName();

  int count = 0;
	int number = 0;
  while (true) {
        number = GetRandomNumber(1, 100);
        count++;
        if (number % 7 == 0) {
            break;
        }
    }
  PrintFinal(count, number);
	// End Student code here (Do NOT code below this line!)
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////
/* This will display the name of the assignment. */
void DisplayName() {
	cout << "L A B   # 4" << endl;
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

/* This prints out the final report based on the findings */
void PrintFinal(int count, int number) {
	cout << "Count: " << std::to_string(count) << ", Number: " << std::to_string(number) << endl;
}