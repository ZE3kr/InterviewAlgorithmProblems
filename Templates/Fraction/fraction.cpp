//
// Created by 郭泽宇 on 2018/10/9.
//

#include "fraction.h"
#include <iostream>

fraction::fraction() {
	numerator = 0;
	denominator = 0;
	sign = true;
}

fraction::fraction(int n, int d, bool isSign) {
	numerator = n;
	denominator = d;
	sign = isSign;
	simplify();
}

void fraction::simplify() {
	if ((numerator < 0) != (denominator < 0)) {
		sign = !sign;
	}
	numerator = abs(numerator);
	denominator = abs(denominator);
	int num = gcd(numerator, denominator);
	if(!num){
		return;
	}
	numerator /= num;
	denominator /= num;
}

int fraction::abs(int num) {
	if (num < 0) {
		return -num;
	}
	return num;
}

int fraction::gcd(int a, int b) {
	if (!b) {
		return a;
	}
	return gcd(b, a % b);
}

std::ostream& operator<<(std::ostream &os, fraction b) {
	if(!b.denominator){
		if(!b.numerator){
			os << "undefined";
			return os;
		} else {
			os << "INF";
			return os;
		}
	}
	if(!b.sign && b.numerator){
		os << '-';
	}
	os << b.numerator << '/' << b.denominator;
	return os;
}

fraction fraction::operator+(fraction &b) {
	fraction ans;
	if(!sign){
		if(!b.sign){
			ans = fraction(-numerator * b.denominator - b.numerator * denominator, denominator * b.denominator);
		} else {
			ans = fraction(-numerator * b.denominator + b.numerator * denominator, denominator * b.denominator);
		}
	} else {
		if(!b.sign){
			ans = fraction(numerator * b.denominator - b.numerator * denominator, denominator * b.denominator);
		} else {
			ans = fraction(numerator * b.denominator + b.numerator * denominator, denominator * b.denominator);
		}
	}
	return ans;
}

fraction fraction::operator+(int b) {
	if(!sign){
		fraction ans(-numerator + b * denominator, denominator);
		return ans;
	}
	fraction ans(numerator + b * denominator, denominator);
	return ans;
}

fraction fraction::operator-() {
	fraction ans = *this;
	ans.sign = !sign;
	return ans;
}

fraction fraction::operator*(fraction &b) {
	fraction ans(numerator*b.numerator, denominator * b.denominator, sign == b.sign);
	return ans;
}

fraction fraction::operator*(int b) {
	fraction ans = *this;
	ans.numerator *= b;
	ans.simplify();
	return ans;
}

fraction fraction::operator/(fraction &b) {
	fraction ans(numerator*b.denominator, denominator * b.numerator, sign == b.sign);
	return ans;
}

fraction fraction::operator/(int b) {
	fraction ans = *this;
	ans.denominator *= b;
	ans.simplify();
	return ans;
}

fraction operator/(int a, fraction & b){
	fraction ans(a*b.denominator, b.numerator, b.sign);
	return ans;
}
