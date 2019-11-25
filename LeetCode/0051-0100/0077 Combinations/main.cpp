#include <vector>

using namespace std;

class Solution {
  public:
	vector<vector<int>> combine(int n, int k) {
		return cmb(1, n, k);
	}
	vector<vector<int>> cmb(int start, int end, int count) {
		vector<vector<int>> ans;
		if(count == 0) {
			return ans;
		}
		if(count == 1) {
			for (int i = start; i <= end; ++i) {
				vector<int> key(1);
				key[0] = i;
				ans.push_back(key);
			}
			return ans;
		}
		for (int i = start; i <= end + 1 - count; i++) {
			for (auto &k:cmb(i+1, end, count-1)) {
				vector<int> key(count);
				key[0] = i;
				for (int j = 0; j < count - 1; ++j) {
					key[j+1] = k[j];
				}
				ans.push_back(key);
			}
		}
		return ans;
	}
};
