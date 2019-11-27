#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
	bool isValid(string input) {
		input = "()" + input + "()";
		vector<char> stack;
		stack.push_back('0');
		for (int i = 0; input[i] != '\0' ; ++i) {
			if(input[i] == '(' || input[i] == '[' || input[i] == '{') {
				stack.push_back(input[i]);
			} else {
				if(input[i] == ')') {
					input[i] = '(';
				} else if(input[i] == ']') {
					input[i] = '[';
				}else if(input[i] == '}') {
					input[i] = '{';
				}
				if(input[i] == stack.back()){
					stack.pop_back();
				} else {
					return false;
				}
			}
		}
		if (stack.back() == '0'){
			return true;
		}
		return false;
	}
};

int main() {
	Solution a;
	printf("%d", a.isValid("(){{[]()}[]}"));
}
