#include <conio.h>
#include <iostream>
#include <string.h>
#include <sstream>
#include <regex>
#include "Rational.h"

using namespace std;

bool regexCheck(string fraction);
bool regexWhole(string fraction);

string firstFraction;
string secondFraction;

class Validator
{
public:
	bool inputMechanism(string* inputString)
	{

		char tempKey = ' ';
		const static int maxLineLength = 0;
		bool empty = false;

		do{
			tempKey = _getch();
			if ((tempKey >= 47 && tempKey <= 57))
			{
				//when valid char pressed, accept and print to screen
				if (maxLineLength >= (*inputString).length())
				{
					(*inputString) += tempKey;
					printf("%c", tempKey);
					empty = true;
				}
			}//end if
			if (tempKey == 8)//ascii backspace
			{
				//if back pressed, pop char off string, and erase from screen
				if ((*inputString).length() > 0)
				{
					(*inputString).erase((*inputString).length() - 1, 1);
					printf("\b \b");
				}
			} //end else if
			else if (tempKey == -32)//drop off any arrow key pressed
			{
				_getch();
			}// end else if

		} while (tempKey != 13 || empty == false);

		printf("\n");
		return true;
	}//end method inputMechanism
};//end class

ostream& operator<<(ostream &output, Rational &rat){

	output << rat.numerator << "/" << rat.denominator;
	return output;
}

int main(){

	Rational rat1;
	Rational rat2;

	cin >> rat1;
	cin >> rat2;
	Rational rat3 = rat1 + rat2;
	cout << rat1 << " + " << rat2 << " = " << rat3 << endl;
	rat3 = rat1 - rat2;
	cout << rat1 << " - " << rat2 << " = " << rat3 << endl;
	rat3 = rat1 * rat2;
	cout << rat1 << " * " << rat2 << " = " << rat3 << endl;
	rat3 = rat1 / rat2;
	cout << rat1 << " / " << rat2 << " = " << rat3 << endl;
	if (rat1 == rat2){
		cout << rat1 << " == " << rat2 << endl;
	}
	else{
		cout << rat1 << " != " << rat2 << endl;
	}
	if (rat1 < rat2){
		cout << rat1 << " < " << rat2 << endl;
	}
	if (rat1 > rat2){
		cout << rat1 << " > " << rat2 << endl;
	}


	_getch();

	return 0;

}

void operator>>(istream &input, Rational &rat){

	//string str;

	Validator val;
	bool validFirst = false;
	while (validFirst == false){
		cout << "Enter the fraction:  " << endl;
		string temp;
		cin >> firstFraction;		
	/*	if (val.inputMechanism(&temp) == true){
		firstFraction = temp;
		}*/

		validFirst = regexCheck(firstFraction);
		
		if (validFirst == true){
			cout << "Number accepted" << endl;
			string delimeter = "/";
			int numerator = stoi(firstFraction.substr(0, firstFraction.find(delimeter)));
			int denominator = stoi(firstFraction.substr(firstFraction.find(delimeter) + 1, firstFraction.length()));

			

			if (denominator < 0 && numerator > 0){
				numerator = numerator * -1;
				denominator = denominator * -1;
			}
			if (denominator < 0 && numerator < 0){
				numerator = numerator * -1;
				denominator = denominator * -1;
			}

			rat.numerator = numerator;
			rat.denominator = denominator;
		}
		else if(regexWhole(firstFraction) == true){

			cout << "Number accepted" << endl;
			rat.numerator = stoi(firstFraction);
			rat.denominator = 1;
			validFirst = true;

		}

		else{
			cout << "Number not accepted" << endl;
		}

	}

}

bool regexWhole(string fraction){

	regex rx("[-]?[0-9]+");

	if (regex_match(fraction, rx) == true){
		return true;
	}
	else{
		return false;
	}

}

bool regexCheck(string fraction){

	regex rx("[-]?[0-9]+[/][-]?[0-9]+"); 

	if (regex_match(fraction, rx) == true){
		return true;
	}
	else{
		return false;
	}

}