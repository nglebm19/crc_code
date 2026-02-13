#include <iostream>
#include <utility>
using namespace std;
#include "Encrypt.h" // include definition of class Encrypt

Encrypt::Encrypt(int data) {
  int encryptedData; // data to be encrypted
  cout << "** The default constructor is called" << endl;
  cout << "   and the passed in number is " << data << "." << endl;

  // DONE: if the number is less than or equal to o, set to 9436
  if (data <= 0) {
    data = 9436;
    cout << "XXX The inputed number is less than or equal to 0" << endl;
    cout << "    The number is reset to " << data << ". XXX" << endl;
  }

  // extract last 4 digits and store in digits[0] to digits[3]
  for (int i = 3; i >= 0; --i) {
    digits[i] = data % 10;
    data /= 10;
  }

  displayOriginalData();
  encryptData();
  displayEncryptedData();
  cout << "\n";

} // end Encrypt constructor

void Encrypt::displayOriginalData() {
  cout << "    The original data is ";
  for (int i = 0; i < 4; ++i) {
    cout << digits[i] << " ";
  }
  cout << "\n";
} // end function displayOriginalData

void Encrypt::storeData(int data) {
  for (int i = 3; i >= 0; --i) {
    digits[i] = data % 10;
    data /= 10;
  }
  encryptData();
} // end function storeData

void Encrypt::displayEncryptedData() {
  cout << "    The encrypted data is ";
  for (int i = 0; i < 4; ++i) {
    cout << digits[i + 4] << " ";
  }
  cout << "\n";
} // end function displayEncryptedData

void Encrypt::encryptData() {
  // replace digit
  for (int i = 0; i < 4; ++i) {
    digits[i + 4] = (digits[i] + 7) % 10;
  }
  // swap digit
  swap(digits[4], digits[6]);
  swap(digits[5], digits[7]);

} // end function encryptData
void swap_digit(int a, int b) {
  int temp = a;
  a = b;
  b = temp;
}
