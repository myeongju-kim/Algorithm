#include <iostream>
#include <set>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

vector<string> g{ "a","b","c","d","a","d","d","d","a","a","c","c" };
vector<int> p{ 100,300,400,150,100,300,200,600,700,110,900,9000 };

struct cmp {
	bool operator()(const pair<int, int>& a, const pair<int, int>& b) const {
		if (a.first == b.first) {
			return a.second < b.second;
		}
		return a.first > b.first;
	}
};
bool cmv(const pair<string, int>& a, const pair<string, int>& b) {
	return a.second > b.second;
}

int main() {
	vector<int> answer;
	map<string, int> m;
	for (int i = 0; i < g.size(); i++)
		m[g[i]] += p[i];
	vector<pair<string, int>> vec(m.begin(), m.end());
	sort(vec.begin(), vec.end(), cmv);
	for (int n = 0; n < vec.size(); n++){
		set<pair<int, int>, cmp>s;
		int full = 0;
		for (int i = 0; i < g.size(); i++) {
			if (vec[n].first == g[i]) {
				s.insert({ p[i],i });
			}
		}
		for (auto iter = s.begin(); iter != s.end(); iter++) {
			if (full == 2)break;
			answer.push_back(iter->second);
			full++;
		}
	}
	
	for (int i = 0; i < answer.size(); i++)
		cout << answer[i] << " ";
}