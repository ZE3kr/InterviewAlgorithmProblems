/**
 * 高等数学计算器
 *
 * 支持分数计算、（非负次数的）多项式计算、多项式定积分、多项式不定积分、行列式计算等功能
 *
 * 本程序仅提供可复用的类，尽可能踩遍所有 C++
 * 的坑。该主程序仅是用于测试类的正确性、可靠性
 *
 * @date 2019-04 ~ 2019-05
 * @author Guo Zeyu <ze3kr at emails.bjut.edu.cn>
 * @copyright 2019 Guo Zeyu, All rights reserved
 *
 */
#include "fraction.h"
#include "matrix.h"
#include "polynomial.h"
#include <iostream>

using std::cout;
using std::endl;

void testFraction();
void testPolynomial();

int main() {
	testFraction();
	testPolynomial();

	return 0;
}

void testFraction() {
	cout << "Testing fraction…\n\n";

	// Test fraction class
	fraction frac1(4, 3);
	fraction frac2(3, 2);

	cout << "\tTesting fraction's plus:  4/3 + 3/2 = " << frac1 + frac2 << endl;
	cout << "\tTesting fraction's inv:   -4/3      = " << -frac1 << endl;
	cout << "\tTesting fraction's minus: 3/2 - 4/3 = " << frac2 - frac1 << endl;
	cout << "\tTesting fraction's pow:   (4/3)^4   = " << (frac1 ^ 4) << endl;
	cout << "\t(4/3)^1 + (-3/2) * 4/3 + 4/3 / 3/2  = "
	     << (frac1 ^ 1) + (-frac2) * frac1 + frac1 / frac2 << endl;

	cout << "\n\t (4/3) + 1   = " << frac1 + 1 << endl;
	cout << "\t (4/3) - 1   = " << frac1 - 1 << endl;
	cout << "\t (4/3) * 4   = " << frac1 * 4 << endl;
	cout << "\t (4/3) / 4   = " << frac1 / 4 << endl;
	cout << "\t 1 + (4/3)   = " << 1 + frac1 << endl;
	cout << "\t 1 - (4/3)   = " << 1 - frac1 << endl;
	cout << "\t 4 * (4/3)   = " << 4 * frac1 << endl;
	cout << "\t 4 / (4/3)   = " << 4 / frac1 << endl;

	cout << "Testing Exception…\n\n";

	try {
		fraction(1, 1) / fraction(0, 1);
	} catch (char const *e) {
		std::cout << "\t\tExpected error: " << e << endl;
	}

	try {
		frac1 / 0;
	} catch (char const *e) {
		std::cout << "\t\tExpected error: " << e << endl;
	}

	try {
		fraction(1, 0);
	} catch (char const *e) {
		std::cout << "\t\tExpected error: " << e << endl;
	}

	try {
		1 / fraction(0, 1);
	} catch (char const *e) {
		std::cout << "\t\tExpected error: " << e << endl;
	}
}

void testPolynomial() {
	cout << "\nTesting polynomial…\n\n";
	polynomial poly;
	poly[0] = 1;
	poly[2] = fraction(1, 2);
	poly[5] = 2;
	cout << "\tWhen x = 2" << endl;
	cout << "\t\t" << poly << " = " << poly.calc(2) << endl;
	cout << "\n\tWhen x = -1" << endl;
	cout << "\t\t" << poly << " = " << poly.calc(-1) << endl;
	cout << "\n\tWhen x = -22/7" << endl;
	cout << "\t\t" << poly << " = " << poly.calc(fraction(22, 7, false))
	     << endl;

	polynomial poly2;
	poly2[0] = fraction(1, 4);
	poly2[2] = fraction(5, 6);
	poly2[3] = fraction(1, 12);
	poly2[5] = 2;
	cout << "\n\tThe derivative of " << poly2 << " is: " << endl;
	for (int i = 0; i < 8; ++i) {
		cout << "\t\t" << poly2.derivative(i) << endl;
	}

	cout << "\n\tThe integral of " << poly2 << " is: \n\t\t" << poly2.integral()
	     << endl;

	polynomial poly3;
	poly3[0] = 3;
	poly3[2] = fraction(1, 3);
	poly3[3] = 1;
	cout << "\n\t -(" << poly << ") = " << endl;
	cout << "\t\t" << -poly << endl;
	cout << "\n\t (" << poly << ") + (" << poly3 << ") = " << endl;
	cout << "\t\t" << poly + poly3 << endl;
	cout << "\n\t (" << poly << ") - (" << poly3 << ") = " << endl;
	cout << "\t\t" << poly - poly3 << endl;
	cout << "\n\t (" << poly << ") * (" << poly3 << ") = " << endl;
	cout << "\t\t" << poly * poly3 << endl;

	polynomial poly4;
	poly4[2] = 1;
	cout << "\n\tThe area of " << poly4 << " in range [0, 1] is: \n\t\t"
	     << poly4.definiteIntegral(0, 1) << endl;

	cout << "\n\n\nTesting matrix…\n\n";

	cout << "\n------------\nTesting matrix determination…\n------------\n";
	fraction data[] = {1, -4, 5,  -2, 5,  5, 4, 4,  1,  -5, 4,  -1,
	                   5, 2,  -1, 5,  5,  5, 5, -3, -5, 0,  -1, -3,
	                   0, 5,  -1, -4, -5, 5, 3, -1, 1,  0,  -4, 2};
	matrix mat(data, 6, 6);
	cout << mat.det(true) << endl;

	cout << "\n------------\nTesting matrix inverse…\n------------\n";
	fraction data3[] = {-2, 0, -1, 3, 3,  -2, -4, -3,
	                    -3, 1, 2,  4, -4, -3, -3, -5};
	matrix mat3(data3, 4, 4);
	cout << mat3.inv(true) << endl;

	cout << "\n------------\nTesting extended matrix inverse…\n------------\n";
	fraction data4[] = {1, 1, 1, 0, 2, 5, 2, 5, -1};
	matrix mat4(data4, 3, 3);
	fraction data4c[] = {6, -4, 27};
	matrix mat4c(data4c, 3, 1);
	cout << mat4.inv2(mat4c, true) << endl;

	cout << "\n------------\nTesting matrix transpose…\n------------\n";
	cout << mat << endl;
	cout << mat.transpose() << endl;
}
