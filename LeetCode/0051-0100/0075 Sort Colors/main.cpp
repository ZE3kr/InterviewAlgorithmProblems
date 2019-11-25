#include <vector>

using namespace std;

class Solution {
public:
	void sortColors(vector<int>& nums) {
		int counting[4] = {0};
		for (auto k : nums) {
			counting[k]++;
		}
		int p = 0;
		for (int i = 0; i < 3; ++i) {
			for (int j = 0; j < counting[i]; ++j) {
				nums[p+j] = i;
			}
			p += counting[i];
		}
	}
};
