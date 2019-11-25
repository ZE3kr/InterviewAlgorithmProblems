#include <vector>

using namespace std;

class Node {
public:
	int val;
	vector<Node*> neighbors;

	Node() {}

	Node(int _val, vector<Node*> _neighbors) {
		val = _val;
		neighbors = _neighbors;
	}
};

using namespace std;

class Solution {
	Node* n[105];
public:
	Solution(){
		for (auto & i : n) {
			i = nullptr;
		}
	}
	Node* cloneGraph(Node* node) {
		for (auto & i : n) {
			delete i;
			i = nullptr;
		}
		return cloneGraphHelper(node);
	}
	Node* cloneGraphHelper(Node * node){
		if(node == nullptr) {
			return nullptr;
		} else if(n[node->val]){
			return n[node->val];
		} else {
			Node * ans = new Node;
			n[node->val] = ans;
			ans->val =  node->val;
			ans->neighbors = node->neighbors;
			for (auto & i : ans->neighbors) {
				i = cloneGraphHelper(i);
			}
			return ans;
		}
	}
};
