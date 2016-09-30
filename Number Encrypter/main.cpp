#include <iostream>
#include <iomanip>
using namespace std;

int originalNumber, key, encryptedNumber, originalDigitOne, originalDigitTwo, originalDigitThree, encryptedDigitOne, encryptedDigitTwo, encryptedDigitThree; //global integer variables, they are needed in all the procedures
int main()
{
	cout << ("Enter the original three-digit number: "); //output asking for three-digit number
	cin >> originalNumber; //input the entered three-digit number
	cout << ("Enter the key: "); //output asking for a one-digit key
	cin >> key; //input the entered key
	void isolateDigits(); //declaration
	isolateDigits(); //call
	void replaceDigits(); //declaration
	replaceDigits(); //call
	void swapDigit1WithDigit3(); //declaration
	swapDigit1WithDigit3(); //call
	void recomposeEncryptedNumber(); //declaration
	recomposeEncryptedNumber(); //call
	cout << "The encrypted number for " << setw(3) << setfill('0') << originalNumber << " is " << setw(3) << setfill('0') << encryptedNumber << "." << endl; //output the three-digit encrypted number, if there are any blank spaces they will be represented by 0's
	system("pause");
	return(0);
}

void isolateDigits() //definition
{ //find out the 3 digits that make up the number
	originalDigitOne = (originalNumber / 100);
	originalDigitTwo = ((originalNumber % 100) / 10);
	originalDigitThree = (originalNumber % 10);
}

void replaceDigits() //definition
{ //’encrypt’ each of the three digits
	encryptedDigitOne = ((originalDigitOne + key) % 10);
	encryptedDigitTwo = ((originalDigitTwo + key) % 10);
	encryptedDigitThree = ((originalDigitThree + key) % 10);
}


void swapDigit1WithDigit3() //definition
{ //swap first and last digit
    int temp; //local integer variable, only needed in this one procedure
	temp = encryptedDigitOne; //set temp to the value of encryptedDigitOne
	encryptedDigitOne = encryptedDigitThree; //set encryptedDigitOne to the value of encryptedDigitThree
	encryptedDigitThree = temp; //set encryptedDigitThree to the value of temp (originally encryptedDigitOne)
}

void recomposeEncryptedNumber() //definition
{ //recreate encrypted number from ‘encrypted’ values
	encryptedNumber = (encryptedDigitOne * 100) + (encryptedDigitTwo * 10) + encryptedDigitThree;
}