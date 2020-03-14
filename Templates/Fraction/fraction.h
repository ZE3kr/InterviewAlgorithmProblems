//
// Created by 郭泽宇 on 2018/10/9.
//

#ifndef C_11_FRACTION_H
#define C_11_FRACTION_H

#include <iosfwd>

class fraction {
  private:
	int numerator;
	int denominator;
	bool sign;
	int gcd(int a, int b);
	int abs(int num);
	void simplify();

  public:
	fraction();
	fraction(int n, int d, bool isSign = true);
	int getNumerator() { return numerator; };
	int getDenominator() { return denominator; };
	bool getSign() { return sign; };
	fraction operator+(fraction &b);
	fraction operator+(int b);
	friend fraction operator+(int a, fraction &b) { return b + a; };
	fraction operator-();
	fraction operator-(fraction &b) {
		fraction c = -b;
		return *this + c;
	};
	fraction operator-(int b) { return *this + -b; };
	friend fraction operator-(int a, fraction &b) {
		fraction c = -b;
		return c + a;
	}
	fraction operator*(fraction &b);
	fraction operator*(int b);
	friend fraction operator*(int a, fraction &b) { return b * a; };
	fraction operator/(fraction &b);
	fraction operator/(int b);
	friend fraction operator/(int a, fraction &b);
	friend std::ostream &operator<<(std::ostream &os, fraction b);
};

#endif // C_11_FRACTION_H
