//
// Created by 郭泽宇 on 2019-05-07.
// Using C++11 standard
//

#ifndef FINALPROJECT_MATRIX_H
#define FINALPROJECT_MATRIX_H

#include "cstdio"
#include "fraction.h"
#include <ostream>
#include <string>

using std::ostream;
using std::string;

class matrix {
  private:
	fraction *data;
	int row;
	int col;

  protected:
	// Utility

	// 返回坐标位置
	int p(int i, int j) const { return i * col + j; }
	// 交换行
	void swapRows(int a, int b);

  public:
	matrix() : data(nullptr), row(0), col(0){}; // 默认构造函数
	matrix(const fraction *d, int r, int c); // 常用的构造函数
	~matrix(); // 析构函数
	matrix(const matrix &m); // 复制构造函数

	int getRow() { return row; };
	int getCol() { return col; };

	matrix &operator=(const matrix &m);

	matrix operator+(const matrix &m) const;
	matrix operator-(const matrix &m) const;
	matrix operator*(const matrix &m) const;
	matrix operator-() const;

	matrix operator+=(const matrix &m) {
		*this = *this + m;
		return *this;
	};
	matrix operator-=(const matrix &m) {
		*this = *this - m;
		return *this;
	};
	matrix operator*=(const matrix &m) {
		*this = *this * m;
		return *this;
	};

	// 转化为上三角矩阵，in-place 计算，返回需要乘的系数
	int toUpperTriangularMat(bool step = false);
	// 转化为下三角矩阵，in-place 计算
	int toLowerTriangularMat(bool step = false);

	fraction det(bool step = false) const;
	matrix transpose() const;
	matrix inv(bool step) const;
	matrix inv2(const matrix &c, bool step) const;

	friend ostream &operator<<(ostream &os, const matrix &mat1); // Print
};

#endif // FINALPROJECT_MATRIX_H
