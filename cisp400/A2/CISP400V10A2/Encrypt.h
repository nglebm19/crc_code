// Name: Andrew Le
// Assignment Number: A2
// Encrypt.h
// Declaration of the class Encrypt
// Defines a class Encrypt that encrypts last four digits of a number
class Encrypt {
public:
  Encrypt(int);                 // constructor
  void storeData(int);          // store new data and encrypt it
  void displayOriginalData();   // display the original data.
  void displayEncryptedData();  // display the encrypted data.
  void encryptData();           // encrypt the data.
  void swapDigit(int &, int &); // swap two digits in the data.

private:
  int digits[8]; // store original data and encrypted data
};
