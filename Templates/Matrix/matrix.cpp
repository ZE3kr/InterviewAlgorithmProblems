//
// Created by 郭泽宇 on 2019-05-07.
// Using C++11 standard
//

#include "matrix.h"
#include <iostream>
#include <sstream>

using std::cout;
using std::endl;

matrix::matrix(const fraction *d, int r, int c) {
	if (r < 0 || c < 0) {
		throw "error size for the matrix";
	}
	row = r;
	col = c;
	data = new fraction[r * c];
	memcpy(data, d, sizeof(fraction) * r * c);
}

matrix::~matrix() { delete[] data; }

matrix::matrix(const matrix &m) {
	data = new fraction[m.row * m.col];
	row = m.row;
	col = m.col;
	memcpy(data, m.data, sizeof(fraction) * m.row * m.col);
}

// 重载了输出运算符
ostream &operator<<(ostream &os, const matrix &mat1) {
	if (mat1.data == nullptr) {
		os << "[]";
		return os;
	}

	int max = 0;
	for (int i = 0; i < mat1.col * mat1.row; i++) {
		std::ostringstream str;
		{ str << mat1.data[i]; }
		int l = str.str().length();
		if (l > max) {
			max = l;
		}
	}

	// 首行
	os << "┌ ";
	os << std::string(mat1.col * (max + 1), ' ');
	os << "┐\n";

	// 每一个元素
	for (int i = 0; i < mat1.row; ++i) {
		os << "│";
		for (int j = 0; j < mat1.col; ++j) {
			std::ostringstream str;
			// Code found on StackOverflow
			{ str << mat1.data[mat1.p(i, j)]; }
			os << std::string(max + 1 - str.str().length(), ' ');
			os << mat1.data[mat1.p(i, j)];
		}
		os << " │\n";
	}

	// 最后一行
	os << "└ ";
	os << std::string(mat1.col * (max + 1), ' ');
	os << "┘";
	return os;
}

matrix &matrix::operator=(const matrix &m) {
	delete[] data;
	data = new fraction[m.row * m.col];
	row = m.row;
	col = m.col;
	memcpy(data, m.data, sizeof(fraction) * m.row * m.col);
	return *this;
}

matrix matrix::operator+(const matrix &m) const {
	if (col != m.col || row != m.row) {
		throw "error size for the matrix to add";
	}
	if (col == 0 || row == 0) {
		throw "cannot add empty matrix";
	}
	matrix ans;
	ans.data = new fraction[row * col];
	ans.row = row;
	ans.col = col;

	for (int i = 0; i < row; ++i) {
		for (int j = 0; j < col; ++j) {
			ans.data[p(i, j)] = data[p(i, j)] + m.data[p(i, j)];
		}
	}

	return ans;
}

matrix matrix::operator-() const {
	matrix ans;
	ans.data = new fraction[row * col];
	ans.row = row;
	ans.col = col;
	for (int i = 0; i < row; ++i) {
		for (int j = 0; j < col; ++j) {
			ans.data[p(i, j)] = -data[p(i, j)];
		}
	}
	return ans;
}

matrix matrix::operator-(const matrix &m) const {
	if (col != m.col || row != m.row) {
		throw "error size for the matrix to minus";
	}
	if (col == 0 || row == 0) {
		throw "cannot add empty matrix";
	}
	matrix ans;
	ans.data = new fraction[row * col];
	ans.row = row;
	ans.col = col;

	for (int i = 0; i < row; ++i) {
		for (int j = 0; j < col; ++j) {
			ans.data[p(i, j)] = data[p(i, j)] - m.data[p(i, j)];
		}
	}

	return ans;
}

matrix matrix::operator*(const matrix &m) const {
	// 使用最简单的定义计算
	// 时间复杂度 O(n^3)
	// 这样算系数比较小，计算小矩阵乘法速度很快
	if (row == 0 || col == 0 || m.row == 0 || m.col == 0) {
		throw "cannot multiply empty matrix";
	}
	if (col != m.row) {
		// 普通的矩阵乘法前者的列数需要等于后者的行数
		throw "error size for the matrix to multiply";
	}
	matrix ans;
	ans.data =
	    new fraction[row * m.col](); // 根据 ISO C++03 5.3.4
	                                 // 标准，最后加上这个括号可以 new
	                                 // 数组时执行 0 值初始化（默认构造函数）

	for (int i = 0; i < row; ++i) {
		for (int j = 0; j < m.col; ++j) {
			for (int k = 0; k < col; ++k) {
				ans.data[p(i, j)] += data[p(i, k)] * m.data[p(k, j)];
			}
		}
	}

	ans.row = row;
	ans.col = m.col;
	return ans;
}

void matrix::swapRows(int a, int b) {
	for (int i = 0; i < col; i++) {
		fraction temp(data[p(a, i)]);
		data[p(a, i)] = data[p(b, i)];
		data[p(b, i)] = temp;
	}
}

// 转化为上三角矩阵（难点）
int matrix::toUpperTriangularMat(bool step) {
	if (row <= 0) {
		throw "cannot calculate the upper triangular mat of an empty mat";
	}
	if (row > col) {
		throw "row is greater than col";
	}
	int ans(1);

	// 化简为上三角矩阵
	// l 作为行，i 作为列数
	// 以每一行的第一个数作为因子化简
	for (int i = 1; i < row; ++i) {
		// 第一步：行交换，如果遇到一行前几项为 0，则将这一行放在后面
		// 根据定理，每次交换行时需要将答案取相反数
		int l = i - 1;
		for (; l < row && data[p(l, i - 1)] == 0; l++) {
		}
		if (l != i - 1) {
			swapRows(l, i - 1);
			ans = -ans;
			if (step) {
				cout << "r" << l + 1 << " <-> "
				     << "r" << i << endl;
				cout << *this << endl;
			}
		}
		// 第二步：将每一行乘以相应系数，消去后几行的前几项
		fraction inv(1 / data[p(i - 1, i - 1)]);
		for (int k = i; k < row; k++) {
			fraction numToMul(inv * -data[p(k, i - 1)]);
			if (step) {
				cout << "r" << k + 1 << " + (" << numToMul << ")r" << i << endl;
			}
			for (int j = 0; j < col; ++j) {
				data[p(k, j)] += numToMul * data[p(i - 1, j)];
			}
		}
		if (step) {
			cout << *this << endl;
		}
	}
	return ans;
}

// 转化为下三角矩阵，方法与转化为上三角矩阵一样，只不过正好对称
// 必须先运行转化为上三角矩阵，再运行此函数才有意义
int matrix::toLowerTriangularMat(bool step) {
	if (row <= 0) {
		throw "cannot calculate the upper triangular mat of an empty mat";
	}
	if (row > col) {
		throw "row is greater than col";
	}
	int ans(1);

	for (int i = row - 2; i >= 0; --i) {
		fraction inv(1 / data[p(i + 1, i + 1)]);
		for (int k = 0; k <= i; k++) {
			fraction numToMul(inv * -data[p(k, i + 1)]);
			if (step) {
				cout << "r" << k + 1 << " + (" << numToMul << ")r" << i + 2
				     << endl;
			}
			for (int j = 0; j < col; ++j) {
				data[p(k, j)] += numToMul * data[p(i + 1, j)];
			}
		}
		if (step) {
			cout << *this << endl;
		}
	}
	return ans;
}

// 计算行列式（难点）
fraction matrix::det(bool step) const {
	// 此方法是使用行化简的方法计算的行列式
	// 时间复杂度 O(n^3)
	// 计算行列式绝不能使用定义法计算，那样太太太慢了，具体见报告

	if (step) {
		cout << "Input:\n" << *this << endl;
	}

	// 复制一个新的矩阵，以避免修改对象数据
	matrix a(*this);

	// 转化为上三角矩阵，使用初等行变换，ans 记录符号
	fraction ans = a.toUpperTriangularMat(step);

	// 答案就是矩阵的 trace 的乘积咯，注意系数
	for (int i = 0; i < row; ++i) {
		ans *= a.data[p(i, i)];
	}
	return ans;
}

// 计算矩阵逆（难点）
matrix matrix::inv(bool step) const {
	// 若使用伴随矩阵法，其时间复杂度为 O(n^5)
	// 这里使用行变换法，时间复杂度仅为 O(n^3)
	if (row <= 0 || col <= 0) {
		throw "cannot calculate inverse of an empty matrix";
	}
	if (row != col) {
		throw "not mat square";
	}
	// 创建一个新的增广矩阵 (A, E)
	matrix mat;
	mat.data = new fraction[col * row * 2];
	mat.row = row;
	mat.col = 2 * col;
	for (int r = 0; r < row; ++r) {
		for (int c = 0; c < col; ++c) {
			mat.data[mat.p(r, c)] = data[p(r, c)];
		}
	}
	for (int r = 0; r < row; ++r) {
		mat.data[p(1 + r * 2, r)] = 1;
	}
	if (step) {
		cout << "Let's assume the new Matrix B" << endl;
		cout << mat << endl;
	}

	// 化简为上三角矩阵
	mat.toUpperTriangularMat(step);

	// 检查矩阵的 Rank
	fraction test(1);
	for (int i = 0; i < mat.row; ++i) {
		test *= mat.data[mat.p(i, i)];
	}
	if (test == 0) {
		throw "the determinant is 0";
	}

	// 现在做半侧已经是上三角矩阵，下面将做半侧化简为对角矩阵。
	mat.toLowerTriangularMat(step);

	// 转化为单位矩阵
	for (int i = 0; i < mat.row; ++i) {
		if (mat.data[mat.p(i, i)] != 1) {
			fraction inv(1 / mat.data[mat.p(i, i)]);
			if (step) {
				cout << "r" << i + 1 << " x (" << inv << ")" << endl;
			}
			for (int j = 0; j < mat.col; ++j) {
				mat.data[mat.p(i, j)] *= inv;
			}
		}
	}

	if (step) {
		cout << mat << endl;
	}

	// 取结果为右半边的矩阵
	matrix ans;
	ans.col = col;
	ans.row = row;
	ans.data = new fraction[col * row];
	for (int i = 0; i < row; ++i) {
		for (int j = 0; j < col; ++j) {
			ans.data[p(i, j)] = mat.data[p(i * 2 + 1, j)];
		}
	}
	return ans;
}

// 计算增广矩阵的逆（难点）
matrix matrix::inv2(const matrix &c, bool step) const {
	// 若使用伴随矩阵法，其时间复杂度为 O(n^5)
	// 这里使用行变换法，时间复杂度仅为 O(n^3)
	if (row <= 0 || col <= 0) {
		throw "cannot calculate inverse of an empty matrix";
	}
	if (row != col || row != c.row) {
		throw "not mat square";
	}
	fraction det1 = det();
	if (det1 == 0) {
		throw "the determinant is 0";
	}
	// 创建一个新的增广矩阵 (A, C)
	matrix mat;
	mat.data = new fraction[(col + c.col) * row];
	mat.row = row;
	mat.col = c.col + col;
	for (int r = 0; r < row; ++r) {
		for (int c1 = 0; c1 < col; ++c1) {
			mat.data[mat.p(r, c1)] = data[p(r, c1)];
		}
	}
	// 设置右半边矩阵
	for (int r = 0; r < row; ++r) {
		for (int c1 = 0; c1 < c.col; ++c1) {
			mat.data[mat.p(r, col + c1)] = c.data[c.p(r, c1)];
		}
	}
	if (step) {
		cout << "Let's assume the new Matrix B" << endl;
		cout << mat << endl;
	}

	// 化简为上三角矩阵
	mat.toUpperTriangularMat(step);

	// 检查矩阵的 Rank
	fraction test(1);
	for (int i = 0; i < mat.row; ++i) {
		test *= mat.data[mat.p(i, i)];
	}
	if (test == 0) {
		throw "the determinant is 0";
	}

	// 现在做半侧已经是上三角矩阵，下面将做半侧化简为对角矩阵。
	mat.toLowerTriangularMat(step);

	// 转化为单位矩阵
	for (int i = 0; i < mat.row; ++i) {
		if (mat.data[mat.p(i, i)] != 1) {
			fraction inv(1 / mat.data[mat.p(i, i)]);
			if (step) {
				cout << "r" << i + 1 << " x (" << inv << ")" << endl;
			}
			for (int j = 0; j < mat.col; ++j) {
				mat.data[mat.p(i, j)] *= inv;
			}
		}
	}

	if (step) {
		cout << mat << endl;
	}

	// 取结果为右半边的矩阵
	matrix ans;
	ans.col = c.col;
	ans.row = c.row;
	ans.data = new fraction[c.col * c.row];
	for (int i = 0; i < c.row; ++i) {
		for (int j = 0; j < c.col; ++j) {
			ans.data[c.p(i, j)] = mat.data[mat.p(i, col + j)];
		}
	}
	return ans;
}

matrix matrix::transpose() const {
	matrix ans;
	ans.row = row;
	ans.col = col;
	ans.data = new fraction[row*col];
	for (int i = 0; i < col; ++i) {
		for (int j = 0; j < row; ++j) {
			ans.data[p(j, i)] = data[p(i, j)];
		}
	}
	return ans;
}
