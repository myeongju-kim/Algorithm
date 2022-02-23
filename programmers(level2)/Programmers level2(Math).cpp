#include <string>
#include <vector>

using namespace std;

vector<string> solution(vector<vector<int>> line) {
    vector<string> sol;
    vector <pair<int, int>> point;
    for (int i = 0; i < line.size(); i++) {
        for (int j = i + 1; j < line.size(); j++) {
            long long A = line[i][0], B = line[i][1], E = line[i][2], C = line[j][0], D = line[j][1], F = line[j][2];
            long long ja_x = B * F - E * D;
            long long mo_x = A * D - B * C;
            long long ja_y = E * C - A * F;
            long long mo_y = A * D - B * C;
            if (mo_x == 0 || mo_y == 0) continue;
            if (ja_x % mo_x != 0) continue;
            if (ja_y % mo_y != 0) continue;
            int x = ja_x / mo_x;
            int y = ja_y / mo_y;
            point.push_back({ x,y });
        }
    }
    int col_min = point[0].first;
    int row_max=point[0].second;
    for (int i = 0; i < point.size(); i++) {
        if (row_max < point[i].second) row_max = point[i].second;
        if (col_min > point[i].first) col_min = point[i].first;
    }

    for (int i = 0; i < point.size(); i++) {
        point[i].first -= col_min;
        point[i].second -= row_max;
        point[i].first = abs(point[i].first);
        point[i].second = abs(point[i].second);
    }
    int r_m = point[0].second;
    int c_m = point[0].first;
    for (int i = 0; i < point.size(); i++) {
        if (r_m < point[i].second) r_m = point[i].second;
        if (c_m < point[i].first) c_m = point[i].first;
    }
    for (int i = 0; i <= r_m; i++) {
        string temp;
        for (int j = 0; j <= c_m; j++)
            temp.push_back('.');
        sol.push_back(temp);
    }
    for (int i = 0; i < point.size(); i++) {
        int row = point[i].second;
        int col = point[i].first;
        sol[row][col] = '*';
    }

    return sol;
}