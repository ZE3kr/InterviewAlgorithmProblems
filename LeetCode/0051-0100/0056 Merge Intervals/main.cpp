#include <map>
#include <vector>

struct Interval {
	int start;
	int end;
	Interval() : start(0), end(0) {}
	Interval(int s, int e) : start(s), end(e) {}
};

using namespace std;

class Solution {
  public:
	vector<Interval> merge(vector<Interval> &intervals) {
		map<int, int> ans;
		while (!intervals.empty()) {
			auto b = intervals.back();
			auto a = ans.lower_bound(b.start);
			if (a != ans.end()) {
				if(a != ans.begin()) {
					--a;
					if (a != ans.end() && a->second >= b.start) {
						b.start = a->first;
						b.end = max(b.end, a->second);
						ans.erase(a->first);
					}
				}
				a = ans.upper_bound(b.end);
				if(a != ans.begin()) {
					--a;
					if (a->first <= b.end && a->first >= b.start &&
						a->second > b.end) {
						b.end = a->second;
					}
				}
				vector<int> toDelete;
				for (a = ans.upper_bound(b.start);
				     a != ans.end() && a->first <= b.end; a++) {
					toDelete.push_back(a->first);
				}
				while (!toDelete.empty()) {
					ans.erase(toDelete.back());
					toDelete.pop_back();
				}
			} else if (a != ans.begin()) {
				a--;
				if(b.start <= a->second) {
					b.start = a->first;
					b.end = max(b.end, a->second);
				}
			}
			ans[b.start] = b.end;
			intervals.pop_back();
		}
		vector<Interval> rAns;
		for (auto i = ans.begin(); i != ans.end(); i++) {
			rAns.emplace_back(Interval(i->first, i->second));
		}
		return rAns;
	}
};
