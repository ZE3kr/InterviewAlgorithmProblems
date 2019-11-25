#include <string>

using std::string;

class Solution {
  public:
	int titleToNumber(string &s) {
		int len = int(s.length());
		int z = 1;
		int ans = 0;
		for (int i = 0; i < len; ++i) {
			ans += (s[len - i - 1] - 'A' + 1) * z;
			z *= 26;
		}
		return ans;
	}
};
