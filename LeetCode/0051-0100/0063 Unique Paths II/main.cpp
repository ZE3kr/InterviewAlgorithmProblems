#include <vector>

using namespace std;

class Solution {
  public:
	int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid);
	int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid, int x,
	                             int y, int m, int n, int **cache);
};

int Solution::uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid) {
	if (obstacleGrid.empty() || obstacleGrid[0].empty() || obstacleGrid[0][0]) {
		return 0;
	}
	int m = int(obstacleGrid.size() - 1);
	int n = int(obstacleGrid[0].size() - 1);
	int** cache = new int*[m+1];
	for (int i = 0; i <= m; ++i) {
		cache[i] = new int[n+1];
		for (int j = 0; j <= n; ++j) {
			cache[i][j] = -1;
		}
	}
	return uniquePathsWithObstacles(obstacleGrid, 0, 0, m, n, cache);
}

int Solution::uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid, int x,
                                       int y, int m, int n, int **cache) {
	if (x == m && y == n && obstacleGrid[x][y] == 0) {
		return 1;
	}
	if (cache[x][y] != -1) {
		return cache[x][y];
	}
	int ans = 0;
	if (x < m && obstacleGrid[x+1][y] == 0) {
		ans += uniquePathsWithObstacles(obstacleGrid, x+1, y, m, n, cache);
	}
	if (y < n && obstacleGrid[x][y+1] == 0) {
		ans += uniquePathsWithObstacles(obstacleGrid, x, y+1, m, n, cache);
	}
	cache[x][y] = ans;
	return ans;
}
