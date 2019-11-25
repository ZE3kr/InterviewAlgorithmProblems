#include <string>

using std::string;

class Solution {
  private:
	string mapping(int n) {
		if (n == 0) {
			return "Z";
		}
		string ans = "0";
		ans[0] = char('A' - 1 + n);
		return ans;
	}

  public:
	string convertToTitle(int n) {
		if (n > 26) {
			if(n % 26 == 0) {
				return convertToTitle(n / 26 - 1) + mapping(n % 26);
			}
			return convertToTitle(n / 26) + mapping(n % 26);
		}
		return mapping(n % 26);
	}
};
