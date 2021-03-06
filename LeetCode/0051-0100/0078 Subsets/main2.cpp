#include <vector>

using namespace std;

class Solution {
  public:
	vector<vector<int>> subsets(vector<int> &nums) { return ss(nums, 0); }
	vector<vector<int>> ss(vector<int> &nums, int start) {
		vector<vector<int>> ans;
		vector<int> empty(0);
		for (int i = start; i < nums.size(); ++i) {
			auto recur = ss(nums, i + 1);
			for (auto &arr : recur) {
				arr.push_back(nums[i]);
			}
			ans.insert(ans.end(), recur.begin(), recur.end());
		}
		ans.push_back(empty);
		return ans;
	}
};
