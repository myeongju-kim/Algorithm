#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
// 모두 같은 경우는 무조건 -1
// 회문인 경우 -> AABBAA -> 하나만 제거해도 회문안됨
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    string str;
    cin >> str;
    // (1) 모두 같은 문자인가?
    if (count(str.begin(), str.end(), str[0]) == str.size()) {
        cout << "-1\n";
        return 0;
    }
    // (2) 회문인가?
    int s = 0, e = str.size() - 1;
    bool t = true;
    for (int i = 0; i < str.size(); i++) {
        if (str[i] != str[e - i]) {
            t = false;
            break;
        }
    }
    if (t) cout << str.size() - 1 << "\n";
    else cout << str.size() << "\n";
    return 0;
}