#include <string>
#include <vector>
using namespace std;

string solution(string a) {
    int sign=1;
    for (int i = 0; i < a.size(); i++) {
        if (a[i] == ' ') {
            sign = 1;
            continue;
        }
        if (sign == 1) {
            if (a[i] >= 'a' && a[i] <= 'z') a[i] -= 32;
            sign = 0;
        }
        else 
            if (a[i] >= 'A' && a[i] <= 'Z') a[i] += 32;
    }
    return a;
}