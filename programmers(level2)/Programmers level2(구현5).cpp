#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
int check(long long n) {
    if (n == 1)return 0;
    for (int i = 2; i <= sqrt(n); i++)
        if (n % i == 0)return 0;
    return 1;
}
int solution(int n, int k) {
    int answer = 0;
    string str;
    while (n > 0) {
        if (n % k == 0) str.push_back('0');
        else {
            char a = '0' + n % k;
            str.push_back(a);
        }
        n /= k;
    }
    vector<long long> v;
    reverse(str.begin(), str.end());
    string temp;
    for (int i = 0; i < str.size(); i++) {
        if (str[i] == '0') {
            if (temp.empty())continue;
            v.push_back(stoll(temp));
            temp = "";
        }
        else temp.push_back(str[i]);
    }
    if(!temp.empty()) v.push_back(stoll(temp));
    for (int i = 0; i < v.size(); i++) {
        if (check(v[i])) answer++;
    }
    return answer;
}