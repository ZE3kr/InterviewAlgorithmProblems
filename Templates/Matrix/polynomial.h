//
// Created by 郭泽宇 on 2019-05-06.
//

#ifndef FINALPROJECT_POLYNOMIAL_H
#define FINALPROJECT_POLYNOMIAL_H

#include "fraction.h"
#include <map>

using std::map;

class polynomial : public map<unsigned, fraction> {
  public:
	polynomial derivative(unsigned n = 1) const; // 导数
	polynomial integral() const; // 不定积分（忽略常数）
	fraction calc(const fraction &x) const;
	fraction definiteIntegral(const fraction &lower,
	                          const fraction &upper) const;
	polynomial operator+(const polynomial &) const;
	polynomial operator-(const polynomial &) const;
	polynomial operator*(const polynomial &)const;
	polynomial operator-() const; // 取反
	friend std::ostream &operator<<(std::ostream &os, const polynomial &f);
};

#endif // FINALPROJECT_POLYNOMIAL_H
