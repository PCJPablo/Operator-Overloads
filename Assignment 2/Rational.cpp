#include <string>
#include <iostream>
#include "Rational.h"

using namespace std;

//Construtors
Rational::Rational(void)
:numerator(0), denominator(1){}
Rational::Rational(int numerator, int denominator)
:numerator(numerator), denominator(denominator){}
Rational::Rational(int wholeNumber)
:numerator(wholeNumber), denominator(1){}

//Gets the lowest common multiple
void Rational::lcm(){

	int tempNum1 = firstDenominator;
	int tempNum2 = secondDenominator;
	
	while (tempNum1 != tempNum2){

		if (tempNum1 < tempNum2){
			tempNum1 = tempNum1 + firstDenominator;
		}
		else{
			tempNum2 = tempNum2 + secondDenominator;
		}

	}
	int num = firstDenominator / tempNum1;
	firstDenominator, secondDenominator = tempNum1;
	firstNumerator = firstNumerator / num;
	secondNumerator = secondNumerator / num;
	 	
}

//Gets the greatest common divisble
int gcd(int num, int den){

	num = abs(num);
	den = abs(den);

	int lesser;

	if (num > den){
		lesser = den;
	}
	else{
		lesser = num;
	}

	for (int i = lesser; i > 0; i--){

		if (num%i == 0 && den%i == 0){
			return i;
		}

	}
	return 0;
}

//overloads the * operator
Rational Rational:: operator*(Rational &multiply){
	
	Rational newRat;
	int gcD;
	newRat = Rational((this->numerator * multiply.numerator), (this->denominator * multiply.denominator));

	gcD = gcd(newRat.numerator, newRat.denominator);
	if (newRat.numerator != 0){

		newRat.numerator = newRat.numerator / gcD;
		newRat.denominator = newRat.denominator / gcD;

	}
	else{
		newRat.numerator = 0;
		newRat.denominator = 1;
	}


	return newRat;

}

//overloads the + operator
Rational Rational:: operator+(Rational &add){

	Rational newRat;
	int gcD;
	newRat = Rational((this->numerator + add.numerator), this->denominator);

	gcD = gcd(newRat.numerator, newRat.denominator);

	if (newRat.numerator != 0){

		newRat.numerator = newRat.numerator / gcD;
		newRat.denominator = newRat.denominator / gcD;

	}
	else{
		newRat.numerator = 0;
		newRat.denominator = 1;
	}

	return newRat;

}

//overloads the - operator
Rational Rational:: operator-(Rational &subtract){

	Rational newRat;
	int gcD;
	newRat = Rational((this->numerator - subtract.numerator), this->denominator);

	gcD = gcd(newRat.numerator, newRat.denominator);

	if (newRat.numerator != 0){

		newRat.numerator = newRat.numerator / gcD;
		newRat.denominator = newRat.denominator / gcD;

	}
	else{
		newRat.numerator = 0;
		newRat.denominator = 1;
	}

	return newRat;

}

//overlaods the / operator
Rational Rational:: operator/(Rational &divide){

	Rational newRat;
	int gcD;
	newRat = Rational((this->numerator * divide.denominator), (this->denominator * divide.numerator));
	newRat.numerator = numerator * divide.denominator;
	newRat.denominator = denominator * divide.numerator;

	gcD = gcd(newRat.numerator, newRat.denominator);

	if (newRat.numerator != 0){

		newRat.numerator = newRat.numerator / gcD;
		newRat.denominator = newRat.denominator / gcD;

	}
	else{
		newRat.numerator = 0;
		newRat.denominator = 1;
	}
	return newRat;

}

// overloads the == operator
bool Rational:: operator==(Rational &equals){

	Rational newRat;

	if (this->numerator * equals.denominator == equals.numerator * this->denominator){
		return true;
	}
	else{
		return false;
	}

}

//overloads the < operator
bool Rational:: operator<(Rational &less){

	Rational newRat;

	if (this->numerator * less.denominator < less.numerator * this->denominator){
		return true;
	}
	else{
		return false;
	}


}

//overloads the > operator
bool Rational:: operator>(Rational &greater){

	Rational newRat;

	if (this->numerator * greater.denominator > greater.numerator * this->denominator){
		return true;
	}
	else{
		return false;
	}
}

