class Encrypt {
public:
  Encrypt(int); // constructor
  void storeData(int);
  void displayOriginalData(); // display the app1's current original data.
  void displayEncryptedData();
  void encryptData();
  void swapDigit(int, int);

private:
  int digits[8]; // data to be encrypted
};
