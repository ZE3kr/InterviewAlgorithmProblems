#include <vector>

using namespace std;

class Solution {
public:
	vector<vector<int>> subsets(vector<int>& nums) {
		vector<vector<int>> ans;
		for (auto i = nums.size(); i > 0 ; --i) {
			for (int j = 0; j <= nums.size() - i; ++j) {
				vector<int> key(i);
				for (auto k = j; k < i + j; ++k) {
					key[k-j]=nums[k];
				}
				ans.push_back(key);
			}
		}
		vector<int> empty(0);
		ans.push_back(empty);
		return ans;
	}
};
