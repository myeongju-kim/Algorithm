#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(string sk, vector<string> skt) {
    int answer = 0;
    for (int k = 0; k < skt.size(); k++) {
        int flag = 1;
        int temp = find(skt[k].begin(), skt[k].end(), sk[0]) - skt[k].begin();
        if (temp == skt[k].size()) temp = 1000;
        for (int i = 1; i < sk.size(); i++) {
            int temp2 = find(skt[k].begin(), skt[k].end(), sk[i]) - skt[k].begin();
            if (temp == 1000 && temp2 != skt[k].size()) {
                flag = 0;
                break;
            }
            else if (temp2 == skt[k].size()) temp2 = 1000;
            if (temp > temp2) {
                flag = 0;
                break;
            }
            temp = temp2;
        }
        if (flag)answer++;
    }
    return answer;
}