#include <iostream>
#include <map>
#include <vector>
using namespace std;

// Based on https://github.com/onehumanbeing/leetcode/blob/596f43d2428fe3a7cb4c5b03cc68124fb41865ec/algorithm/0003/res.cpp

class Solution {
  public:
	int lengthOfLongestSubstring(string s) {
		int answer = 0;
		int start = 0;
		int length;
		unordered_map<char, int> charPlace;
		for (int i = 0; i < s.length(); i++) {
			if (charPlace.find(s[i]) != charPlace.end()) {
				if (charPlace[s[i]] >= start) {
					start = charPlace[s[i]] + 1;
				}
			}

			charPlace[s[i]] = i;

			length = i - start + 1;
			if (length > answer) {
				answer = length;
			}
		}
		return answer;
	}
};

int main() {
	Solution s = Solution();
	cout << s.lengthOfLongestSubstring("pwwkew") << endl;
	return 0;
}
