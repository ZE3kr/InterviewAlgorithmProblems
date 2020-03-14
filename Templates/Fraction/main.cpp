#include "fraction.cpp"

using namespace std;

int main() {
	fraction a(-7, 11);
	fraction b(3, 5);
	cout << a << '+' << b << '=' << a + b << endl;
	cout << a << '+' << 17 << '=' << a + 17 << endl;
	cout << 17 << '+' << a << '=' << 17 + a << endl;
	cout << endl;

	cout << a << '-' << b << '=' << a - b << endl;
	cout << a << '-' << 17 << '=' << a - 17 << endl;
	cout << 17 << '-' << a << '=' << 17 - a << endl;
	cout << endl;

	cout << a << '*' << b << '=' << a * b << endl;
	cout << a << '*' << 17 << '=' << a * 17 << endl;
	cout << 17 << '*' << a << '=' << 17 * a << endl;
	cout << endl;

	cout << '(' << a << ")/(" << b << ")=" << a / b << endl;
	cout << '(' << a << ")/(" << 17 << ")=" << a / 17 << endl;
	cout << '(' << 17 << ")/(" << a << ")=" << 17 / a << endl;
	cout << endl;

	cout << "0/0=" << fraction(0, 0) << endl;
	cout << "1/0=" << fraction(1, 0) << endl;
	cout << endl;
}
