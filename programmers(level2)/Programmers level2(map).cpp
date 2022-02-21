#include <string>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

string solution(int n, int t, int m, int p) {
   int s = 0;
    map<int, string> Map;
    for (int i = 1; i <= m; i++)
        Map[i] = "";
    int index = 1;
    while (t > Map[p].size()) {
        int temp = s;
        string ch;
        while (temp > 0) {
            if (temp % n == 0) ch.push_back('0');
            else {
                int a = temp % n;
                if (a >= 10) {
                    ch.push_back('A' + a - 10);
                }
                else ch.push_back('0' + temp % n);
            }
            temp /= n;
        }
        if (s == 0) ch.push_back('0');
        else reverse(ch.begin(), ch.end());
        for (int i = 0; i < ch.size(); i++) {
            if (Map[p].size() == t)break;
            Map[index].push_back(ch[i]);
            index++;
            if (index > m) index = 1;
        }
        s++;
    }
    return Map[p];
}