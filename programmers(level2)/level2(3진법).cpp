#include <string>
#include <vector>
#include <algorithm>
using namespace std;

string solution(int n) {
    string a = "";
    while (n > 0) {
        if (n % 3 != 0)a += to_string(n % 3);
        else {
            a += "4";
            n--;
        }
        n /= 3;
    }
    reverse(a.begin(), a.end());
    return a;
}