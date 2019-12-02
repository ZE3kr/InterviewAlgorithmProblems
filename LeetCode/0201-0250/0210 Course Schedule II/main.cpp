#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
	vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
		// Graph problem. Topological sort.
		// Try to remove all nodes in the graph with 0-degree.
		vector<int> ans;
		vector<vector<int>> table(numCourses, vector<int>{});
		vector<int> inDeg(numCourses,0);
		vector<bool> inGraph(numCourses,false);
		int total = 0;
		for(auto &a :prerequisites){
			inGraph[a[1]] = inGraph[a[0]] = true;
			table[a[1]].push_back(a[0]);
			inDeg[a[0]]++;
		}
		for (int i = 0; i < numCourses; ++i) {
			if(inGraph[i]){
				total++;
			} else {
				ans.push_back(i);
			}
		}
		while (total > 0) {
			int init = total;
			for (int i = 0; i < numCourses; ++i) {
				if(inGraph[i] && inDeg[i] == 0){
					ans.push_back(i);
					for (auto j : table[i]) {
						inDeg[j]--;
					}
					inGraph[i] = false;
					total--;
				}
			}
			if(init == total){
				return vector<int>{};
			}
		}
		return ans;
	}
};

int main() {
	Solution a;
	vector<vector<int>> pre = {{1,0},{2,0},{3,1},{3,2}};

	for(int n: a.findOrder(4,pre)){
		cout << n << ' ';
	}
	cout << endl;

	return 0;
}