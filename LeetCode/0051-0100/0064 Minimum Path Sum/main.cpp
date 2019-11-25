#include <vector>

using namespace std;

class Solution {
  public:
	int minPathSum(vector<vector<int>> &grid);
	int minPathSum(vector<vector<int>> &grid, int x, int y, int m, int n,
	               int **cache);
};

int Solution::minPathSum(vector<vector<int>> &grid) {
	if (grid.empty() || grid[0].empty()) {
		return 0;
	}
	int m = int(grid.size() - 1);
	int n = int(grid[0].size() - 1);
	int **cache = new int *[m + 1];
	for (int i = 0; i <= m; ++i) {
		cache[i] = new int[n + 1];
		for (int j = 0; j <= n; ++j) {
			cache[i][j] = -1;
		}
	}
	return minPathSum(grid, 0, 0, m, n, cache);
}

int Solution::minPathSum(vector<vector<int>> &grid, int x, int y, int m, int n,
                         int **cache) {
	if (x == m && y == n) {
		return grid[x][y];
	}
	if (cache[x][y] != -1) {
		return cache[x][y] + grid[x][y];
	}
	int ans = (1 << 31) - 1;
	if (x < m) {
		ans = min(ans, minPathSum(grid, x + 1, y, m, n, cache));
	}
	if (y < n) {
		ans = min(ans, minPathSum(grid, x, y + 1, m, n, cache));
	}
	cache[x][y] = ans;
	return ans + grid[x][y];
}
