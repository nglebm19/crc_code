// Name: Andrew Le
// File: CISP400V10A7.cpp
// Purpose: This program creates 10 integer vectors with random sizes from 0 to 20
//          and random values from 0 to 100, displays the original vectors, sorts
//          them using quicksort, and then displays the sorted vectors.

#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

// Function prototypes
void fillVector(vector<int> &numbers, int size);
void displayInitialVector(const vector<int> &numbers);
void displaySortedVector(const vector<int> &numbers);
void printVectorValues(const vector<int> &numbers);
void quickSortHelper(vector<int> &numbers, int start, int end);
int partitionVector(vector<int> &numbers, int start, int end);
string getOrdinal(int number);

// Main function
int main()
{
  // Seed the random-number generator
  srand(static_cast<unsigned int>(time(0)));

  const int NUMBER_OF_VECTORS = 10;

  for (int setNumber = 1; setNumber <= NUMBER_OF_VECTORS; setNumber++)
  {
    int vectorSize = rand() % 21; // random size from 0 to 20
    vector<int> numbers;

    fillVector(numbers, vectorSize);

    cout << "The " << getOrdinal(setNumber) << " set of data("
         << numbers.size() << "):" << endl;

    displayInitialVector(numbers);

    // A vector with 0 or 1 element is already sorted, so only call
    // quicksort when there are at least 2 elements
    if (numbers.size() > 1)
    {
      quickSortHelper(numbers, 0, static_cast<int>(numbers.size()) - 1);
    }

    displaySortedVector(numbers);

    cout << endl;
  }

  return 0;
}

// Fill the vector with random integers from 0 to 100
void fillVector(vector<int> &numbers, int size)
{
  for (int i = 0; i < size; i++)
  {
    numbers.push_back(rand() % 101);
  }
}

// Display the vector before sorting
void displayInitialVector(const vector<int> &numbers)
{
  if (numbers.size() == 0)
  {
    cout << "  The vector is empty." << endl
         << endl;
  }
  else if (numbers.size() == 1)
  {
    cout << "  Initial vector value is:" << endl;
    cout << "  " << numbers[0] << endl;
  }
  else
  {
    cout << "  Initial vector values are:" << endl;
    printVectorValues(numbers);
  }
}

// Display the vector after sorting
void displaySortedVector(const vector<int> &numbers)
{
  if (numbers.size() == 0)
  {
    cout << "  The sorted vector is empty." << endl;
  }
  else if (numbers.size() == 1)
  {
    cout << "  Vector is sorted:" << endl;
    cout << "  " << numbers[0] << endl;
  }
  else
  {
    cout << "  The sorted vector values are:" << endl;
    printVectorValues(numbers);
  }
}

// Print all vector values on one line, separated by spaces
void printVectorValues(const vector<int> &numbers)
{
  cout << "  ";
  for (size_t i = 0; i < numbers.size(); i++)
  {
    cout << numbers[i];

    if (i < numbers.size() - 1)
    {
      cout << " ";
    }
  }

  cout << endl;
}

// Recursive quicksort helper function
// Receives the starting and ending indices of the (sub)vector to sort
void quickSortHelper(vector<int> &numbers, int start, int end)
{
  // Base case: a subvector with 0 or 1 element is already sorted
  if (start < end)
  {
    // Partition places the pivot in its final sorted position and
    // returns that position
    int pivotLocation = partitionVector(numbers, start, end);

    // Recursively sort the left subvector (values less than pivot)
    quickSortHelper(numbers, start, pivotLocation - 1);

    // Recursively sort the right subvector (values greater than pivot)
    quickSortHelper(numbers, pivotLocation + 1, end);
  }
}

// Partition step described in the assignment:
// The first element is the pivot. Scan from the right for a value
// less than the pivot, swap it with the pivot, then scan from the
// left for a value greater than the pivot, swap it with the pivot,
// and keep alternating until the scanning indices meet. The pivot
// is then in its final sorted position.
int partitionVector(vector<int> &numbers, int start, int end)
{
  int pivotIndex = start; // current position of the pivot value
  int left = start;       // left scanning index
  int right = end;        // right scanning index

  // Continue partitioning until the two indices meet at the pivot
  while (left < right)
  {
    // Step 1: Scan from the right.
    // Move 'right' leftward until we find a value less than the pivot
    // or until 'right' reaches the pivot's current position
    while (right > pivotIndex && numbers[right] >= numbers[pivotIndex])
    {
      right--;
    }

    // If we found a value less than the pivot, swap it with the pivot
    if (right != pivotIndex)
    {
      int temp = numbers[pivotIndex];
      numbers[pivotIndex] = numbers[right];
      numbers[right] = temp;

      pivotIndex = right; // pivot has moved to the right index
    }

    // Step 2: Scan from the left.
    // Move 'left' rightward until we find a value greater than the
    // pivot or until 'left' reaches the pivot's current position.
    while (left < pivotIndex && numbers[left] <= numbers[pivotIndex])
    {
      left++;
    }

    // If we found a value greater than the pivot, swap it with the pivot
    if (left != pivotIndex)
    {
      int temp = numbers[pivotIndex];
      numbers[pivotIndex] = numbers[left];
      numbers[left] = temp;

      pivotIndex = left; // pivot has moved to the left index
    }
  }

  // The pivot is now in its final sorted position
  return pivotIndex;
}

// Return the ordinal string for numbers 1 through 10
string getOrdinal(int number)
{
  switch (number)
  {
  case 1:
    return "1st";
  case 2:
    return "2nd";
  case 3:
    return "3rd";
  case 4:
    return "4th";
  case 5:
    return "5th";
  case 6:
    return "6th";
  case 7:
    return "7th";
  case 8:
    return "8th";
  case 9:
    return "9th";
  case 10:
    return "10th";
  default:
    return "";
  }
}