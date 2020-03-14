//
// Created by 郭泽宇 on 2019-05-06.
//

#include "fraction.h"

#include <iostream>

fraction::fraction() {
	// 默认分数为 +0/1
	numerator = 0;
	denominator = 1;
	sign = true;
}

fraction::fraction(integer n, integer d, bool isSign) {
	if(d == 0) {
		throw "Cannot divide zero when initializing the object!";
	}
	numerator = n;
	denominator = d;
	sign = isSign;
	simplify();
}

fraction::fraction(int n){
	denominator = 1;
	if(n < 0) {
		numerator = -n;
		sign = false;
	} else {
		numerator = n;
		sign = true;
	}

}

void fraction::simplify() {
	if ((numerator < 0) != (denominator < 0)) {
		sign = !sign;
	}
	numerator = abs(numerator);
	denominator = abs(denominator);
	integer num = gcd(numerator, denominator);
	if (!num) {
		return;
	}
	numerator /= num;
	denominator /= num;
}

integer fraction::abs(integer num) {
	// 绝对值
	if (num < 0) {
		return -num;
	}
	return num;
}

integer fraction::gcd(integer a, integer b) {
	// 一个简单的欧几里得辗转相处求最大公约数程序
	if (!b) {
		return a;
	}
	return gcd(b, a % b);
}

std::ostream &operator<<(std::ostream &os, const fraction &b) {
	if (!b.denominator) {
		if (!b.numerator) {
			os << "undefined";
			return os;
		} else {
			os << "INF";
			return os;
		}
	}
	if (!b.sign && b.numerator) {
		os << '-';
	}
	if(b.denominator == 1) {
		os << b.numerator;
	} else {
		os << b.numerator << '/' << b.denominator;
	}
	return os;
}

fraction fraction::operator+(const fraction &b) const {
	fraction ans;
	if (!sign) {
		if (!b.sign) {
			ans =
			    fraction(-numerator * b.denominator - b.numerator * denominator,
			             denominator * b.denominator);
		} else {
			ans =
			    fraction(-numerator * b.denominator + b.numerator * denominator,
			             denominator * b.denominator);
		}
	} else {
		if (!b.sign) {
			ans =
			    fraction(numerator * b.denominator - b.numerator * denominator,
			             denominator * b.denominator);
		} else {
			ans =
			    fraction(numerator * b.denominator + b.numerator * denominator,
			             denominator * b.denominator);
		}
	}
	return ans;
}

fraction fraction::operator+(integer b) const {
	if (!sign) {
		fraction ans(-numerator + b * denominator, denominator);
		return ans;
	}
	fraction ans(numerator + b * denominator, denominator);
	return ans;
}

fraction fraction::operator-() const {
	fraction ans = *this;
	ans.sign = !sign;
	return ans;
}

fraction fraction::operator*(const fraction &b) const {
	fraction ans(numerator * b.numerator, denominator * b.denominator,
	             sign == b.sign);
	return ans;
}

fraction fraction::operator*(integer b) const {
	fraction ans = *this;
	ans.numerator *= b;
	ans.simplify();
	return ans;
}

fraction fraction::operator/(const fraction &b) const {
	if(b.numerator == 0) {
		throw "Cannot divide a zero fraction!";
	}
	fraction ans(numerator * b.denominator, denominator * b.numerator,
	             sign == b.sign);
	return ans;
}

fraction fraction::operator/(integer b) const {
	if(b == 0) {
		throw "Cannot divide a zero integer!";
	}
	fraction ans = *this;
	ans.denominator *= b;
	ans.simplify();
	return ans;
}

fraction operator/(integer a, const fraction &b) {
	if(b.numerator == 0) {
		throw "Integer cannot divide a zero fraction!";
	}
	fraction ans(a * b.denominator, b.numerator, b.sign);
	return ans;
}

fraction fraction::operator^(unsigned y) const {
	if(y == 0){
		return 1;
	}
	if(y == 1) {
		return *this;
	}
	if(y == 2) {
		return *this * *this;
	}
	fraction half = *this ^ (y/2);
	if(y%2){
		return half * half * (*this);
	}
	return half * half;
}

bool fraction::operator==(const fraction &a) const {
	return (numerator == a.numerator && denominator == a.denominator) && (numerator == 0 || (sign == a.sign));
}

bool fraction::operator<(const fraction &a) const {
	fraction temp = *this - a;
	return !temp.sign;
}

bool fraction::operator>=(const fraction &a) const {
	fraction temp = *this - a;
	return temp.sign;
}

bool fraction::operator>(const fraction &a) const {
	return a < *this;
}

bool fraction::operator<=(const fraction &a) const {
	return a >= *this;
}
