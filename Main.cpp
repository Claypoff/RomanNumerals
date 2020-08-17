#include<iostream>
#include<string>

using namespace std;

//this function is used to convert a number to the roman symbol based on its place value
string numToSymbol(int placeValue, char number) {
	if (number == '9') {
		if (placeValue == 3) return "CM";
		if (placeValue == 2) return "XC";
		if (placeValue == 1) return "IX";
	}
	else if (number == '8') {
		if (placeValue == 3) return "DCCC";
		if (placeValue == 2) return "LXXX";
		if (placeValue == 1) return "VIII";
	}
	else if (number == '7') {
		if (placeValue == 3) return "DCC";
		if (placeValue == 2) return "LXX";
		if (placeValue == 1) return "VII";
	}
	else if (number == '6') {
		if (placeValue == 3) return "DC";
		if (placeValue == 2) return "LX";
		if (placeValue == 1) return "VI";
	}
	else if (number == '5') {
		if (placeValue == 3) return "D";
		if (placeValue == 2) return "L";
		if (placeValue == 1) return "V";
	}
	else if (number == '4') {
		if (placeValue == 3) return "CD";
		if (placeValue == 2) return "XL";
		if (placeValue == 1) return "IV";
	}
	else if (number == '3') {
		if (placeValue == 4) return "MMM";
		if (placeValue == 3) return "CCC";
		if (placeValue == 2) return "XXX";
		if (placeValue == 1) return "III";
	}
	else if (number == '2') {
		if (placeValue == 4) return "MM";
		if (placeValue == 3) return "CC";
		if (placeValue == 2) return "XX";
		if (placeValue == 1) return "II";
	}
	else if (number == '1') {
		if (placeValue == 4) return "M";
		if (placeValue == 3) return "C";
		if (placeValue == 2) return "X";
		if (placeValue == 1) return "I";
	}
	else {											// If number is 0, returns empty string
		return "";
	}
}

int main() {

	// Initialize constant values and symbol values of number limit. Initialize the user string and boolean that runs the while loop
	const int NUMBER_LIMIT = 4000;
	const int I_VALUE = 1;
	const int V_VALUE = 5;
	const int X_VALUE = 10;
	const int L_VALUE = 50;
	const int C_VALUE = 100;
	const int D_VALUE = 500;
	const int M_VALUE = 1000;
	string userString = "";
	bool runLoop = true;

	cout << "Welcome to the Roman Numeral converter!" << endl;
	cout << "valid inputs include numbers ranging from (1 - 3999) and letters: I, V, X, L, C, D, M" << endl << endl;
	while (runLoop) {
		cout << "to quit, please enter \"quit\" or \"q\"" << endl;
		cout << "please enter a Roman Numeral or a number to be converted: ";
		cin >> userString;

		// If user enters "quit" or "q", switches boolean to false in order to exit the while loop
		if (userString == "quit" || userString == "q" || userString == "Quit" || userString == "Q") {
			runLoop = false;
		}

		// This checks to see if the first char is a number to know if the string is to be converted from number to roman symbols
		else if (isdigit(userString.at(0))) {

			// Checks to see if the whole number is less than the 4000 limit and greater than 0 to continue
			if (stoi(userString) >= NUMBER_LIMIT || stoi(userString) <= 0) {
				cout << "invalid input!" << endl;
				cout << "valid inputs include numbers ranging from (1 - 3999) and letters: I, V, X, L, C, D, M" << endl << endl;
			}
			else {
				string romanString = "";
				for (unsigned int i = 0; i < userString.size(); ++i) {
					if (isdigit(userString.at(i))) {												// Checks to see if character is a digit
						romanString.append(numToSymbol(userString.size() - i, userString.at(i)));	// Uses function to convert digit to char and appends
					}
					else {
						romanString = "invalid";													// If character isn't a digit, sets string to invalid
						break;																		// and breaks out of for loop
					}
				}

				// checks to see if string was valid and outputs string
				if (romanString != "invalid") {													
					cout << "Your Roman Numeral is: " << romanString << endl << endl;
				}
				else {
					cout << "invalid input!" << endl;
					cout << "valid inputs include numbers ranging from (1 - 3999) and letters: I, V, X, L, C, D, M" << endl << endl;
				}
			}
		}

		// This checks to see if the string is a letter to know if the string is to be converted from roman numerals to number 
		else if (isalpha(userString.at(0))) {
			int numSum = 0;															
			char prevChar = userString.at(userString.size() - 1);					// Uses previous Char to know if it must add, subtract, or it's invalid
			
			// Uses a for loop to go through the string to adds/subtracts values and check if it's valid roman numeral statement
			for (int i = userString.size() - 1; i >= 0; --i) {						
				if (userString.at(i) == 'I' || userString.at(i) == 'i') {
					if (prevChar == 'L' || prevChar == 'C' || prevChar == 'D' || prevChar == 'M') {
						numSum = -1;
						break;														// If previous char is a larger place value than the current character
					}																//  sets sum to -1 and breaks out of for loop
					else if (prevChar == 'V' || prevChar == 'X') {					
						numSum -= I_VALUE;											// If previous char is the same place value, substracts value from sum
					}
					else {
						numSum += I_VALUE;
						prevChar = toupper(userString.at(i));						// Sets previous char to upper case to facilitate comparing in case of lowercase
					}
				}				
				else if (userString.at(i) == 'V' || userString.at(i) == 'v') {
					if (prevChar == 'X' || prevChar == 'L' || prevChar == 'C' || prevChar == 'D' || prevChar == 'M') {
						numSum = -1;
						break;														// If previous char is a larger place value than the current character
					}																// sets sum to -1 and breaks out of for loop
					else {
						numSum += V_VALUE;
						prevChar = toupper(userString.at(i));
					}
				}
				else if (userString.at(i) == 'X' || userString.at(i) == 'x') {
					if (prevChar == 'D' || prevChar == 'M') {
						numSum = -1;												// If previous char is a larger place value than the current character
						break;														// sets sum to -1 and breaks out of for loop
					}
					else if (prevChar == 'L' || prevChar == 'C') {					// If previous char is the same place value, substracts value from sum
						numSum -= X_VALUE;
					}
					else {
						numSum += X_VALUE;
						prevChar = toupper(userString.at(i));
					}
				}
				else if (userString.at(i) == 'L' || userString.at(i) == 'l') {
					if (prevChar == 'C' || prevChar == 'D' || prevChar == 'M') {
						numSum = -1;												// If previous char is a larger place value than the current character
						break;														// sets sum to -1 and breaks out of for loop
					}
					else {
						numSum += L_VALUE;
						prevChar = toupper(userString.at(i));
					}
				}
				else if (userString.at(i) == 'C' || userString.at(i) == 'c') {
					if (prevChar == 'D' || prevChar == 'M') {						// If previous char is the same place value, substracts value from sum
						numSum -= C_VALUE;	
					}
					else {
						numSum += C_VALUE;
						prevChar = toupper(userString.at(i));
					}
				}
				else if (userString.at(i) == 'D' || userString.at(i) == 'd') {
					if (prevChar == 'M') {											// If previous char is a larger place value than the current character
						numSum = -1;												// sets sum to -1 and breaks out of for loop
						break;
					}
					else {
						numSum += D_VALUE;
						prevChar = toupper(userString.at(i));
					}
				}
				else if (userString.at(i) == 'M' || userString.at(i) == 'm') {
					numSum += M_VALUE;
					prevChar = toupper(userString.at(i));
				}
				else {																// If the character not a letter and 1 of the 7 roman numerals
					numSum = -1;													// sets the sum to -1 and breaks out of for loop
					break;
				}
			}

			// checks to see if Roman Numeral was valid and outputs the Sum if so
			if (numSum >= 0 && numSum < NUMBER_LIMIT) {
				cout << "Your number is: " << numSum << endl << endl;
			}
			else {
				cout << "invalid input" << endl;
				cout << "valid inputs include numbers ranging from (1 - 3999) and letters: I, V, X, L, C, D, M" << endl << endl;
			}
		}

		// If the string isn't a digit or letter, outputs invalid
		else {
			cout << "invalid input" << endl;
			cout << "valid inputs include numbers ranging from (1 - 3999) and letters: I, V, X, L, C, D, M" << endl << endl;
		}
	}

	cout << endl << "Thank You!";

	return 0;
}
