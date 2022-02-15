#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

long long solution(string a) {
    long long answer = 0;
    vector<string> temp;
    vector<char> f;
    string ts = "";
    for (int i = 0; i < a.size(); i++) {
        if (a[i] == '-' || a[i] == '*' || a[i] == '+') {
            temp.push_back(ts);
            ts = "";
            ts.push_back(a[i]);
            if (find(f.begin(), f.end(), a[i]) == f.end())
                f.push_back(a[i]);
            temp.push_back(ts);
            ts = "";
            continue;
        }
        ts += a[i];
    }
    temp.push_back(ts);
    sort(f.begin(), f.end());
    do {
        vector<string> temp2(temp.begin(), temp.end());
        for (int i = 0; i < f.size(); i++) {
            for (int j = 0; j < temp2.size()-1; j++) {
                if (temp2[j][0] == f[i]) {
                    long long a = stoll(temp2[j - 1]);
                    long long b = stoll(temp2[j + 1]);
                    long long re;
                    if (f[i] == '*') re = a * b;
                    else if (f[i] == '+') re = a + b;
                    else re = a - b;
                    temp2[j - 1] = to_string(re);
                    temp2.erase(temp2.begin() + j);
                    temp2.erase(temp2.begin() + j);
                    j = j - 1;
                }
            }
        }
        long long alpa = abs(stoll(temp2[0]));
        if (answer < alpa)
            answer = alpa;
    } while (next_permutation(f.begin(), f.end()));

    return answer;
}