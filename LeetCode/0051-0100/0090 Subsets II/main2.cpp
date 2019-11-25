// 16ms
#include <algorithm>
#include <vector>
#include <map>

using namespace std;

class Solution {
  public:
	vector<vector<int>> subsetsWithDup(vector<int> &nums) {
		return ss(nums, 0);
	}
	vector<vector<int>> ss(vector<int> &nums, int start) {
		vector<vector<int>> ans;
		vector<int> empty(0);
		map<vector<int>, bool> isSet;
		for (int i = start; i < nums.size(); ++i) {
			auto recur = ss(nums, i + 1);
			for (auto &arr : recur) {
				arr.push_back(nums[i]);
				sort(arr.begin(), arr.end());
				if(!isSet[arr]) {
					isSet[arr] = true;
					ans.push_back(arr);
				}
			}
		}
		ans.push_back(empty);
		return ans;
	}
};
