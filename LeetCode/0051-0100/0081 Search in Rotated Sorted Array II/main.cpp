#include <vector>

using namespace std;

class Solution {
  public:
	bool search(vector<int> &nums, int target) {
		if (nums.empty()) {
			return false;
		}
		int start = 0;
		for (int i = 0; i < nums.size() - 1; ++i) {
			if (nums[i] > nums[i + 1]) {
				start = i + 1;
				break;
			}
		}
		auto nums2 = nums;
		for (int j = start; j < start + nums.size(); ++j) {
			nums2[j-start] = nums[j%nums.size()];
		}
		auto t = lower_bound(nums2.begin(), nums2.end(), target);
		if (t == nums2.end() || *t != target) {
			return false;
		}
		return true;
	}
};
