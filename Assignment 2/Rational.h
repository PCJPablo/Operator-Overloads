#ifndef Rational_H
#define Rational_H
#include <sstream>

class Rational{

private: 

	int numerator;
	int denominator;
	int firstNumerator;
	int firstDenominator;
	int secondNumerator;
	int secondDenominator;

public:
	Rational(void);
	Rational(int numerator, int denominator);
	Rational(int wholeNumber);
	//virtual ~Rational(void);
	void lcm();
	Rational operator*(Rational &multiply);
	Rational operator+(Rational &add);
	Rational operator-(Rational &subtract);
	Rational operator/(Rational &divide);
	bool operator==(Rational &equal);
	bool operator>(Rational &greater);
	bool operator<(Rational &less);
	friend void operator>>(std::istream &input, Rational &rat);
	friend std::ostream& operator<<(std::ostream &output, Rational &rat);

};

#endif