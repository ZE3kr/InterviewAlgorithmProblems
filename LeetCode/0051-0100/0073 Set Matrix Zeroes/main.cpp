#include <vector>

using namespace std;

class Solution {
  public:
	void setZeroes(vector<vector<int>> &matrix) {
		if (matrix.empty() || matrix[0].empty()) {
			return;
		}
		bool firstRow = false;
		int m = matrix.size();
		int n = matrix[0].size();
		for (int i = 0; i < m; ++i) {
			if (matrix[i][0] == 0) {
				firstRow = true;
				continue;
			}
			for (int j = 1; j < n; ++j) {
				if (matrix[i][j] == 0) {
					matrix[i][0] = 0;
				}
			}
		}
		for (int j = 1; j < n; ++j) {
			for (int i = 0; i < m; ++i) {
				if (matrix[i][j] == 0) {
					for (int k = 0; k < m; ++k) {
						matrix[k][j] = 0;
					}
					break;
				}
			}
		}
		for (int i = 0; i < m; ++i) {
			if (matrix[i][0] == 0) {
				for (int j = 1; j < n; ++j) {
					matrix[i][j] = 0;
				}
			}
		}
		if(firstRow) {
			for (int j = 0; j < m; ++j) {
				matrix[j][0] = 0;
			}
		}
	}
};
