#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
using namespace std;
bool compare(vector<int> v1, vector<int> v2) {
    return v1.size() < v2.size();
}
vector<int> solution(string s) {
    vector<int> result;
    vector <vector<int>> v;
    s.erase(s.begin()); s.pop_back();
    int i = 0;
    while(1){
        if (i >= s.size())break;
        if (s[i] == '{') {
            vector<int> temp;
            string a = "";
            while (s[++i] != '}') {
                if (s[i] == ',') s[i] = ' ';
                a += s[i];
            }
            stringstream ss(a);
            string buf;
            while (ss >> buf)
                temp.push_back(stoi(buf));
            v.push_back(temp);
        }
        i++;
    }
    sort(v.begin(), v.end(), compare);
    result.push_back(v[0][0]);
    for (int i = 1; i < v.size(); i++) {
        for (int j = 0; j < v[i].size(); j++) {
            if (find(result.begin(), result.end(), v[i][j]) == result.end()) {
                result.push_back(v[i][j]);
                break;
            }
        }
    }
    return result;
}