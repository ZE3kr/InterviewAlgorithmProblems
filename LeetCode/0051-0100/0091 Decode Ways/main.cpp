#include <string>
#include <vector>

using namespace std;

class Solution {
  public:
	int numDecodings(string s) {
		vector<int> cache(s.size());
		return nD(s.c_str(), 0, cache);
	}
	int nD(const char *s, int p, vector<int> &cache) {
		if (s[p] == '\0') {
			return 1;
		}
		if (s[p + 1] == '\0') {
			if (s[p] == '0') {
				return 0;
			}
			return 1;
		}
		if (cache[p]) {
			return cache[p];
		}
		int ans = 0;
		if (s[p] > '0') {
			ans += nD(s, p + 1, cache);
		}
		if (s[p] == '1' || (s[p] == '2' && s[p + 1] <= '6')) {
			ans += nD(s, p + 2, cache);
		}
		cache[p] = ans;
		return ans;
	}
};
