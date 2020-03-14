//
// Created by 郭泽宇 on 2019-05-06.
//

#include "polynomial.h"
#include <iostream>

fraction polynomial::calc(const fraction &x) const {
	fraction frac;
	// 使用了逐项相加法而非秦九韶算法。因为这里计算幂次方时使用的是二分法计算的，效率更高。
	for (auto i = this->begin(); i != this->end(); ++i) {
		frac += i->second * (x ^ i->first);
	}
	return frac;
}

std::ostream &operator<<(std::ostream &os, const polynomial &f) {
	const polynomial *newPoly = &f;
	bool outputPlus = false;
	for (auto i = newPoly->begin(); i != newPoly->end(); ++i) {
		if (outputPlus) {
			os << " + ";
		}
		if (i->first == 0) {
			os << i->second;
		} else {
			if(i->second == 1) {
				os << "x^" << i->first;
			} else {
				os << i->second << "x^" << i->first;
			}
		}
		outputPlus = true;
	}
	if(!outputPlus) {
		os << 0;
	}
	return os;
}

polynomial polynomial::derivative(unsigned n) const {
	if (n == 0) {
		return *this;
	}
	polynomial ans;
	for (auto i = this->begin(); i != this->end(); ++i) {
		if (i->first  >= n) {
			int mul = 1;
			for (int j = i->first; j > i->first - n; --j) {
				mul *= j;
			}
			ans[i->first - n] = i->second * mul;
		}
	}
	return ans;
}

polynomial polynomial::integral() const {
	polynomial ans;
	for (auto i = this->begin(); i != this->end(); ++i) {
		ans[i->first + 1] = i->second / (i->first + 1);
	}
	return ans;
}

fraction polynomial::definiteIntegral(const fraction &lower,
                                      const fraction &upper) const {
	polynomial itgrl = integral();
	return itgrl.calc(upper) - itgrl.calc(lower);
}

polynomial polynomial::operator+(const polynomial &poly1) const {
	// Pm + Pn
	// Pm 代表有 m 个项的多项式
	// Pn 代表有 n 个项的多项式，下同
	// 时间复杂度：O( max(m, n) )
	polynomial ans = *this;
	for (auto i = poly1.begin(); i != poly1.end(); ++i) {
		ans[i->first] += i->second;
	}
	return ans;
}

polynomial polynomial::operator-(const polynomial &poly1) const {
	// Pm - Pn
	// 时间复杂度：O( max(m, n) )
	polynomial ans = *this;
	for (auto i = poly1.begin(); i != poly1.end(); ++i) {
		ans[i->first] -= i->second;
	}
	return ans;
}

polynomial polynomial::operator*(const polynomial &poly1) const {
	// Pm * Pn
	// 时间复杂度：O( m * n )
	polynomial ans;
	for (auto i = this->begin(); i != this->end(); ++i) {
		for (auto j = poly1.begin(); j != poly1.end(); ++j) {
			ans[i->first + j->first] += i->second * j->second;
		}
	}
	return ans;
}

polynomial polynomial::operator-() const {
	polynomial ans;
	for (auto i = this->begin(); i != this->end(); ++i) {
		ans[i->first] = -i->second;
	}
	return ans;
}
