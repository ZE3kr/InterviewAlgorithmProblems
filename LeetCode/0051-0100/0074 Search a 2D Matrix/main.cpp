#include <vector>

using namespace std;

bool operator<(const vector<int> &a, const vector<int> &b) {
	return a[0] < b[0];
}

class Solution {
  public:
	bool searchMatrix(vector<vector<int>> &matrix, int target) {
		if (matrix.empty() || matrix[0].empty()) {
			return false;
		}
		vector<int> tmp(1);
		tmp[0] = target+1;
		auto find1 = lower_bound(matrix.begin(), matrix.end(), tmp);
		if (find1 == matrix.begin()) {
			return false;
		}
		find1--;
		auto find2 = lower_bound(find1->begin(), find1->end(), target);
		if (*find2 == target) {
			return true;
		}
		return false;
	}
};
