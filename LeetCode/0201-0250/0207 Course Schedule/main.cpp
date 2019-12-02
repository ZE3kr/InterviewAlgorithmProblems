#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
	bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
		// Graph problem. Topological sort.
		// Try to remove all nodes in the graph with 0-degree.
		vector<vector<int>> table(numCourses, vector<int>{});
		vector<int> inDeg(numCourses,0);
		vector<bool> inGraph(numCourses,false);
		int total = 0;
		for(auto &a :prerequisites){
			inGraph[a[0]] = inGraph[a[1]] = true;
			table[a[0]].push_back(a[1]);
			inDeg[a[1]]++;
		}
		for (int i = 0; i < numCourses; ++i) {
			if(inGraph[i]){
				total++;
			}
		}
		while (total > 0) {
			int init = total;
			for (int i = 0; i < numCourses; ++i) {
				if(inGraph[i] && inDeg[i] == 0){
					for (auto j : table[i]) {
						inDeg[j]--;
					}
					inGraph[i] = false;
					total--;
				}
			}
			if(init == total){ // All nodes that still in the graph are 0 in-degree.
				return false;
			}
		}
		return true;
	}
};

int main() {
	Solution a;
	vector<vector<int>> pre = {{1,0}};

	cout << a.canFinish(2,pre) << endl;

	pre = {{1,0},{2,1},{3,2},{4,3},{5,1},{5,2},{5,3},{5,4},{2,5}};
	cout << a.canFinish(6,pre);

	return 0;
}