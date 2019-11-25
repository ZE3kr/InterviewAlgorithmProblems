#include <iostream>

using namespace std;

class Solution {
  public:
	int uniquePaths(int m, int n) { return c(m + n - 2, min(m, n) - 1); }
	int c(int n, int k) {
		unsigned long long ans = 1;
		for (int i = n; i > n - k; i--) {
			ans *= i;
			ans /= n - i + 1;
		}
		return int(ans);
	}
};
