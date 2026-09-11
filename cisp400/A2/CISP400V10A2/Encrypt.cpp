// Name: Andrew Le
// Assignment Number: A2
// Encrypt.cpp
// Implementation of class Encrypt
// Member-function definitions for class Encrypt from Encrypt.h
#include <iostream>
using namespace std;
#include "Encrypt.h" // include definition of class Encrypt

// Constructor: takes an integer, stores last 4 digits, encrypts, and displays
// results. If input <= 0, resets to 9436.
Encrypt::Encrypt(int data) {
  cout << "** The default constructor is called" << endl;
  cout << "   and the passed in number is " << data << ".**" << endl;
  cout << "\n";

  // if the number is less than or equal to o, set to 9436
  if (data <= 0) {
    data = 9436;
    cout << " XXX The inputed number is less than or equal to 0." << endl;
    cout << "     The number is reset to " << data << ". XXX" << endl;
    cout << "\n";
  }
  // extract last 4 digits and store in digits[0] to digits[3]
  for (int i = 3; i >= 0; --i) {
    digits[i] = data % 10;
    data /= 10;
  }

  displayOriginalData();  // show original data
  encryptData();          // encrypt data
  displayEncryptedData(); // show encrypted data
  cout << "\n";

} // end Encrypt constructor

// Displays the original 4 digits stored in digits[0] to digits[3]
void Encrypt::displayOriginalData() {
  cout << "     The original data is ";
  for (int i = 0; i < 4; ++i) {
    cout << digits[i] << " ";
  }
  cout << "\n";
} // end function displayOriginalData

// Stores the last 4 digits of the passed integer and encrypts them
void Encrypt::storeData(int data) {
  cout << "\n";
  if (data <= 0) {
    data = 9436;
    cout << " XXX The inputed number is less than or equal to 0." << endl;
    cout << "     The number is reset to " << data << ". XXX" << endl;
  }
  for (int i = 3; i >= 0; --i) {
    digits[i] = data % 10;
    data /= 10;
  }
  encryptData(); // encrypt the new stored data
} // end function storeData

// Displays the encrypted 4 digits stored in digits[4] to digits[7]
void Encrypt::displayEncryptedData() {
  cout << "     The encrypted data is ";
  for (int i = 0; i < 4; ++i) {
    cout << digits[i + 4] << " ";
  }
  cout << "\n";
} // end function displayEncryptedData

// Encrypts by replacing each digit with (digit + 7) % 10,
// then swaps 1st with 3rd and 2nd with 4th.
void Encrypt::encryptData() {
  // replace digit
  for (int i = 0; i < 4; ++i) {
    digits[i + 4] = (digits[i] + 7) % 10;
  }
  // swap 1st with 3rd, 2nd with 4th
  swapDigit(digits[4], digits[6]);
  swapDigit(digits[5], digits[7]);

} // end function encryptData

// Swaps two integers by reference.
void Encrypt::swapDigit(int &a, int &b) {
  int temp = a;
  a = b;
  b = temp;
}
