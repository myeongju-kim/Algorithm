#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <tuple>
using namespace std;

int check(vector<char> v) {
    int mcount = 0;
    int jcount = 0;
    for (int i = 0; i < v.size(); i++) {
        if (v[i] == 'a' || v[i] == 'e' || v[i] == 'i' || v[i] == 'o' || v[i] == 'u') mcount++;
        else jcount++;
    }
    if (mcount >= 1 && jcount >= 2) return 1;
    return 0;
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n, c;
    cin >> n >> c;
    vector<char> v(c);
    vector<int> yes(c);
    fill(yes.begin(), yes.end(), 0);
    for (int i = 0; i < n; i++)
        yes[i] = 1;

    for (int i = 0; i < c; i++) {
        char temp;
        cin >> temp;
        v[i] = temp;
    }
    sort(v.begin(), v.end());
    do {
        vector<char> temp;
        for (int i = 0; i < c; i++) {
            if (yes[i] == 1)
                temp.push_back(v[i]);
        }
        if (check(temp)) {
            for (int i = 0; i < temp.size(); i++)
                cout << temp[i];
            cout << "\n";
        }
    } while (prev_permutation(yes.begin(), yes.end()));

    return 0;
}
