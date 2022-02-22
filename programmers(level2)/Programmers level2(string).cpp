#include <string>
#include <vector>
#include <map>
using namespace std;

vector<int> solution(string msg) {
    int ss = 27;
    vector<int> answer;
    map<string, int> m;
     for (int i = 1; i <= 26; i++) {
        char a = 'A' + i - 1;
        string temp; temp.push_back(a);
        m[temp] = i;
    }
    for (int i = 0; i < msg.size(); i++) {
        string temp;
        temp.push_back(msg[i]);
        if (m[temp] != 0) {
            int a = i + 1;
            string cur = temp;
            if (a>= msg.size()) {
                answer.push_back(m[cur]);
                continue;
            }
            int index = 0;
            while (1) {
                temp.push_back(msg[a]);
                if (m[temp] == 0) {
                    answer.push_back(m[cur]);
                    m[temp] = ss++;
                    break;
                }
                a++;
                index++;
                cur = temp;
            }
            i += index;
        }
    }
    return answer;
}