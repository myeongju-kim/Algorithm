#include <string>
#include <vector>

using namespace std;
vector<pair<int, int>> v;
void find(int g, int s, int b, int y) {
    if (g * s == b + y) {
        if ((g - 2) * (s - 2) == y) {
            v.push_back({ g,s });
            return;
        }
    }
    if (g == s) {
        find(g + 1, 3, b,  y);
    }
    else if (g > s) {
        find(g, s + 1,  b, y);
    }
}
vector<int> solution(int b, int y) {
    find(3,3,b,y);
    return {v[0].first, v[0].second};
}