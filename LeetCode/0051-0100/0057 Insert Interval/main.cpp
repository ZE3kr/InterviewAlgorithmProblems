#include <algorithm>
#include <vector>

struct Interval {
	int start;
	int end;
	Interval() : start(0), end(0) {}
	Interval(int s, int e) : start(s), end(e) {}
};

using namespace std;

inline bool operator<(const Interval &a, const Interval &b) {
	return a.start < b.start;
}

class Solution {
  public:
	vector<Interval> insert(vector<Interval> &ans2, Interval b) {
		auto ans = ans2;
		auto a = lower_bound(ans.begin(), ans.end(), b);
		if (ans.empty()) {
			ans.push_back(b);
			return ans;
		}
		if (a != ans.end()) {
			if (a != ans.begin()) {
				--a;
				if (a != ans.end() && a->end >= b.start) {
					b.start = a->start;
					b.end = max(b.end, a->end);
					ans.erase(a);
				}
			}
			auto c = b;
			c.start = b.end;
			a = upper_bound(ans.begin(), ans.end(), c);
			if (a != ans.begin()) {
				--a;
				if (a->start <= b.end && a->start >= b.start &&
				    a->end > b.end) {
					b.end = a->end;
				}
			}
			vector<vector<Interval>::iterator> toDelete;
			for (a = upper_bound(ans.begin(), ans.end(), b);
			     a != ans.end() && a->start <= b.end; a++) {
				toDelete.push_back(a);
			}
			while (!toDelete.empty()) {
				ans.erase(toDelete.back());
				toDelete.pop_back();
			}
		} else if (a != ans.begin()) {
			a--;
			if (b.start <= a->end) {
				b.start = a->start;
				b.end = max(b.end, a->end);
			}
		}
		a = lower_bound(ans.begin(), ans.end(), b);
		if (a->start == b.start) {
			ans.erase(a);
		}
		ans.emplace_back(Interval(b.start, b.end));
		for (int i = 0; i < ans.size(); i++) {
			if (ans[i].start > b.start) {
				for (auto j = ans.size()-1; j > i ; --j) {
					ans[j] = ans[j-1];
				}
				ans[i] = b;
				break;
			}
		}
		return ans;
	}
};
