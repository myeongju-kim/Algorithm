#include <string>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;
bool compare(pair<string, int> p1, pair<string, int> p2) {
    return p1.second > p2.second;
}
vector<string> solution(vector<string> orders, vector<int> course) {
    vector<string> result;
    for (int k = 0; k < course.size(); k++) {
        map<string, int> m;
        int n = course[k];
        for (int i = 0; i < orders.size(); i++) {
            if (orders[i].size() < n) continue;
            vector<int> a(orders[i].size(), 0);
            sort(orders[i].begin(), orders[i].end());
            for (int j = 0; j < n; j++) a[j] = 1;
            do {
                string temp;
                for (int j = 0; j < orders[i].size(); j++)
                    if (a[j] == 1) temp.push_back(orders[i][j]);
                m[temp]++;
            } while (prev_permutation(a.begin(), a.end()));
        }
        if (m.empty())continue;
        vector<pair<string, int>> t(m.begin(), m.end());
        sort(t.begin(), t.end(), compare);
        int max = t[0].second;
        if (t[0].second == 1)continue;
        result.push_back(t[0].first);
        for (int i = 1; i < t.size(); i++) {
            if (max == t[i].second)result.push_back(t[i].first);
            else break;
        }
    }
    sort(result.begin(), result.end());
    return result;
}
