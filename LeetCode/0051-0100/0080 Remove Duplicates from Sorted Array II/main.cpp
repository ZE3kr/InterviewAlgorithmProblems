#include <vector>

using namespace std;

class Solution {
public:
	int removeDuplicates(vector<int>& nums) {
		int prev1 = (1<<31)-1;
		int prev2 = (1<<31)-1;
		int ans = nums.size();
		vector<vector<int>::iterator> toDelete;
		for (auto k = nums.begin(); k != nums.end(); k++) {
			int tmp = *k;
			if(prev1 == prev2 && prev2 == *k) {
				*k = (1<<31)-1;
				ans--;
			}
			prev2 = prev1;
			prev1 = tmp;
		}
		int j = 0;
		for (int i = 0; i < nums.size(); ++i) {
			if(nums[i] == (1<<31)-1) {
				continue;
			}
			nums[j] = nums[i];
			j++;
		}
		return ans;
	}
};
