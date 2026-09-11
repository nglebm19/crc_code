// Name: Johnny Le
// CISP400V10A7.cpp
// This program creates 10 integer vectors.
// The program displays each original vector, sorts it
// using quicksort, and then displays the sorted vector.

#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

// Function prototypes
// These tell the compiler that these functions will be written later in the file.
void createRandomValues(vector<int> &list, int listSize);
void printBeforeSort(const vector<int> &list);
void printAfterSort(const vector<int> &list);
void printList(const vector<int> &list);
void quickSortHelper(vector<int> &list, int lowIndex, int highIndex);
int partitionFirstElement(vector<int> &list, int lowIndex, int highIndex);
string ordinalName(int number);

int main()
{
  // Seed the random number generator.
  // This makes the random numbers different each time the program runs.
  srand(static_cast<unsigned int>(time(0)));

  // The assignment requires 10 vectors.
  const int TOTAL_LISTS = 10;

  // This loop creates, displays, sorts, and displays 10 different vectors.
  for (int group = 1; group <= TOTAL_LISTS; group++)
  {
    // Randomly choose the size of the vector from 0 to 20.
    // rand() % 21 gives possible values: 0, 1, 2, ..., 20.
    int listSize = rand() % 21;

    // Create an empty integer vector.
    vector<int> list;

    // Fill the vector with random values from 0 to 100.
    createRandomValues(list, listSize);

    // Display the set number and the size of the vector in parentheses.
    // Example: The 1st set of data(18):
    cout << "The " << ordinalName(group) << " set of data("
         << list.size() << "):" << endl;

    // Display the vector before sorting.
    printBeforeSort(list);

    // A vector with 0 or 1 element is already sorted.
    // Therefore, quicksort is only needed if the vector has at least 2 values.
    if (list.size() > 1)
    {
      // Sort the whole vector.
      // The first index is 0.
      // The last index is list.size() - 1.
      quickSortHelper(list, 0, static_cast<int>(list.size()) - 1);
    }

    // Display the vector after sorting.
    printAfterSort(list);

    // Print a blank line between each set of data.
    cout << endl;
  }

  return 0;
}

// This function fills the vector with random integer values.
// The vector is passed by reference, so changes made inside this function
// will affect the original vector in main.
void createRandomValues(vector<int> &list, int listSize)
{
  // Repeat listSize times.
  for (int count = 0; count < listSize; count++)
  {
    // rand() % 101 gives values from 0 to 100.
    // Each random value is added to the end of the vector.
    list.push_back(rand() % 101);
  }
}

// This function displays the vector before it is sorted.
// The vector is passed as a const reference because this function only prints it.
// It does not change the vector.
void printBeforeSort(const vector<int> &list)
{
  // Case 1: The vector has no values.
  if (list.empty())
  {
    cout << "  The vector is empty." << endl;
    cout << endl;
  }

  // Case 2: The vector has exactly one value.
  else if (list.size() == 1)
  {
    cout << "  Initial vector value is:" << endl;
    cout << "  " << list[0] << endl;
  }

  // Case 3: The vector has two or more values.
  else
  {
    cout << "  Initial vector values are:" << endl;
    printList(list);
  }
}

// This function displays the vector after it has been sorted.
void printAfterSort(const vector<int> &list)
{
  // Case 1: Empty vector.
  // There is nothing to sort.
  if (list.empty())
  {
    cout << "  The sorted vector is empty." << endl;
  }

  // Case 2: One-value vector.
  // A vector with one value is already sorted.
  else if (list.size() == 1)
  {
    cout << "  Vector is sorted:" << endl;
    cout << "  " << list[0] << endl;
  }

  // Case 3: Vector has two or more values.
  // Print all values after quicksort has finished.
  else
  {
    cout << "  The sorted vector values are:" << endl;
    printList(list);
  }
}

// This function prints all values in the vector on one line.
void printList(const vector<int> &list)
{
  // Add two spaces before the list values to match the expected output style.
  cout << "  ";

  // Go through each value in the vector.
  for (size_t index = 0; index < list.size(); index++)
  {
    // Print the value at the current index.
    cout << list[index];

    // Print a space after each value except the last value.
    // This avoids an extra space at the end of the line.
    if (index < list.size() - 1)
    {
      cout << " ";
    }
  }

  // Move to the next line after printing the whole vector.
  cout << endl;
}

// This is the recursive quicksort function.
// It receives the starting index and ending index of the current subvector.
// Example: if lowIndex = 0 and highIndex = 9,
// the function sorts the section from index 0 to index 9.
void quickSortHelper(vector<int> &list, int lowIndex, int highIndex)
{
  // Base case:
  // If lowIndex is not less than highIndex, then the subvector has
  // zero or one value, so it is already sorted.
  if (lowIndex < highIndex)
  {
    // Partition the current subvector.
    // This places the first element of the subvector into its final sorted position.
    int pivotFinalIndex = partitionFirstElement(list, lowIndex, highIndex);

    // Recursively sort the left subvector.
    // These are the values before the pivot.
    quickSortHelper(list, lowIndex, pivotFinalIndex - 1);

    // Recursively sort the right subvector.
    // These are the values after the pivot.
    quickSortHelper(list, pivotFinalIndex + 1, highIndex);
  }
}

// This function performs the partitioning step required by the assignment.
//
// Required logic from the assignment:
// 1. Take the first element of the unsorted subvector as the pivot.
// 2. Starting from the right side, find a value smaller than the pivot.
// 3. Swap that value with the pivot.
// 4. Starting from the left side, find a value greater than the pivot.
// 5. Swap that value with the pivot.
// 6. Repeat until the pivot reaches its final sorted location.
//
// After this function finishes:
// - all values on the left side of the pivot are less than or equal to the pivot
// - all values on the right side of the pivot are greater than or equal to the pivot
// - the pivot is in its final sorted position
int partitionFirstElement(vector<int> &list, int lowIndex, int highIndex)
{
  // The assignment says to use the first element of the subvector as the pivot.
  // Instead of saving the pivot value separately, this program tracks
  // where the pivot is currently located.
  int pivotIndex = lowIndex;

  // leftIndex starts at the beginning of the subvector.
  int leftIndex = lowIndex;

  // rightIndex starts at the end of the subvector.
  int rightIndex = highIndex;

  // Continue partitioning until the left and right indexes meet.
  while (leftIndex < rightIndex)
  {
    // Step 1:
    // Start scanning from the right side.
    // Move rightIndex left while the value is greater than or equal to the pivot.
    // We are looking for a value smaller than the pivot.
    while (rightIndex > pivotIndex &&
           list[rightIndex] >= list[pivotIndex])
    {
      rightIndex--;
    }

    // Step 2:
    // If rightIndex does not stop on the pivot,
    // that means we found a value smaller than the pivot.
    // Swap that smaller value with the pivot.
    if (rightIndex != pivotIndex)
    {
      int temporary = list[pivotIndex];
      list[pivotIndex] = list[rightIndex];
      list[rightIndex] = temporary;

      // After the swap, the pivot has moved to rightIndex.
      pivotIndex = rightIndex;
    }

    // Step 3:
    // Now scan from the left side.
    // Move leftIndex right while the value is less than or equal to the pivot.
    // We are looking for a value greater than the pivot.
    while (leftIndex < pivotIndex &&
           list[leftIndex] <= list[pivotIndex])
    {
      leftIndex++;
    }

    // Step 4:
    // If leftIndex does not stop on the pivot,
    // that means we found a value greater than the pivot.
    // Swap that greater value with the pivot.
    if (leftIndex != pivotIndex)
    {
      int temporary = list[pivotIndex];
      list[pivotIndex] = list[leftIndex];
      list[leftIndex] = temporary;

      // After the swap, the pivot has moved to leftIndex.
      pivotIndex = leftIndex;
    }
  }

  // When the loop ends, the pivot is in its final sorted position.
  // Return that position so quicksort can sort the left and right subvectors.
  return pivotIndex;
}

// This function returns the ordinal form for numbers 1 through 10.
// This is used to display:
// 1st, 2nd, 3rd, 4th, ..., 10th
string ordinalName(int number)
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