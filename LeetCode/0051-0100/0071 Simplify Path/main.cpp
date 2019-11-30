#include <vector>
#include <list>
#include <string>
#include <iostream>

using namespace std;

class Solution {
public:
	static string simplifyPath(const string & path) {
		list<string> li;
		string tmp;
		for(char c : path) {
			if(c == '/') {
				if(!tmp.empty()){
					li.emplace_back(tmp); // Add the file name
				}
				if(tmp == ".") {
					if(!li.empty()) {
						li.pop_back();
					}
					tmp = "";
					continue;
				} else if (tmp == "..") {
					for (int i = 0; i < 3; ++i) {
						if(!li.empty()) {
							li.pop_back();
						}
					}
					if(li.empty()){
						li.emplace_back("/");
					}
					tmp = "";
					continue;
				} else if (!li.empty() && li.back() == "/") {  // for multiple "/"
					continue;
				}
				// Normal case
				tmp = "";
				li.emplace_back("/");
			} else {
				// Append the character
				tmp += c;
			}
		}
		if(tmp == ".") {
			if(!li.empty()) {
				li.pop_back();
			}
			tmp = "";
		} else if (tmp == "..") {
			for (int i = 0; i < 3; ++i) {
				if(!li.empty()) {
					li.pop_back();
				}
			}
			if(li.empty()){
				li.emplace_back("/");
			}
			tmp = "";
		}
		if(!tmp.empty()){
			li.emplace_back(tmp);
		}

		if(!li.empty() && li.back() == "/") {
			li.pop_back();
		}
		tmp = "";
		for (const string &s : li) {
			tmp += s;
		}
		if(tmp.empty()){
			return "/";
		}
		return tmp;
	}
};

int main() {
	Solution a;
	cout << a.simplifyPath("///d///home") << endl;
	cout << a.simplifyPath("/home/") << endl;
	cout << a.simplifyPath("/../") << endl;
	cout << a.simplifyPath("/home//foo/") << endl;
	cout << a.simplifyPath("/a/./b/../../c/") << endl;
	cout << a.simplifyPath("/a//b////c/d//././/..") << endl;
	return 0;
}