//
// Created by 郭泽宇 on 2019-05-06.
//

#ifndef FINALPROJECT_FRACTION_H
#define FINALPROJECT_FRACTION_H

#include <iostream>

typedef long long integer;

class fraction {
  private:
	integer numerator;
	integer denominator;
	bool sign; // 符号。true 为正，false 为负，默认为正
	integer gcd(integer a, integer b);
	integer abs(integer num);
	void simplify();

  public:
	fraction();
	fraction(integer n, integer d, bool isSign = true);
	fraction(
	    int n); // 允许使用整数初始化，没有加 explict 标签，是为了允许隐式转化
	integer getNumerator() const { return numerator; };
	integer getDenominator() const { return denominator; };
	bool getSign() const { return sign; };

	// 分数加分数
	fraction operator+(const fraction &b) const;

	// 分数加整数
	fraction operator+(integer b) const;

	// 整数加分数
	friend fraction operator+(integer a, const fraction &b) { return b + a; };

	// 取反
	fraction operator-() const;

	// 分数减分数
	fraction operator-(const fraction &b) const { return *this + (-b); };

	// 分数减整数
	fraction operator-(integer b) const { return *this + -b; };

	// 整数减分数
	friend fraction operator-(integer a, const fraction &b) {
		fraction c = -b;
		return c + a;
	}

	// 分数乘分数
	fraction operator*(const fraction &b) const;

	// 分数乘整数
	fraction operator*(integer b) const;

	// 整数乘分数
	friend fraction operator*(integer a, const fraction &b) { return b * a; };

	// 分数除分数
	fraction operator/(const fraction &b) const;

	// 分数除整数
	fraction operator/(integer b) const;

	// 整数除分数
	friend fraction operator/(integer a, const fraction &b);

	// 重载打印运算符
	friend std::ostream &operator<<(std::ostream &os, const fraction &b);

	// 重载 += -= *=
	fraction operator+=(const fraction &f) {
		*this = *this + f;
		return *this;
	}
	fraction operator-=(const fraction &f) {
		*this = *this - f;
		return *this;
	}
	fraction operator*=(const fraction &f) {
		*this = *this * f;
		return *this;
	}

	fraction operator^(unsigned y) const;

	bool operator<(const fraction &a) const;
	bool operator<=(const fraction &a) const;
	bool operator>(const fraction &a) const;
	bool operator>=(const fraction &a) const;
	bool operator==(const fraction &a) const;
	bool operator!=(const fraction &a) const { return !(*this == a); }
};

#endif // FINALPROJECT_FRACTION_H
