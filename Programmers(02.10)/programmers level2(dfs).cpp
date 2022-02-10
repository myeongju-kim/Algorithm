#include <string>
#include <vector>

using namespace std;
void dfs(int x, int y, int n, vector<vector<int>>& arr) {
    if (n == 1)return;
    int one_count = 0;
    int zero_count = 0;
    for (int i = x; i < n+x; i++) {
        for (int j = y; j < n+y; j++) {
            if (arr[i][j] == 1) one_count++;
            else zero_count++;

        }
    }
    if (one_count == n * n) {
        for (int i = x; i < n+x; i++) {
            for (int j = y; j < n+y; j++) {
                arr[i][j] = 2;
            }
        }
        arr[x][y]=1;
        return;
    }
    else if (zero_count == n * n) {
        for (int i = x; i < n+x; i++) {
            for (int j = y; j < n+y; j++) {
                arr[i][j] = 2;
            }
        }
        arr[x][y]=0;
        return;
    }
    dfs(x, y, n / 2,  arr);
    dfs(x, y + n / 2,n / 2,  arr);
    dfs(x + n / 2, y,  n / 2, arr);
    dfs(x + n / 2, y + n / 2, n / 2, arr);

}


vector<int> solution(vector<vector<int>> arr) {
    vector<int> answer;
    int zero=0, one=0;
    dfs(0,0,arr.size(), arr);
    for(int i=0; i<arr.size(); i++){
        for(int j=0; j<arr[i].size(); j++){
            if(arr[i][j]==0) zero++;
            else if (arr[i][j]==1)one++;
        }
    }
    answer.push_back(zero);
    answer.push_back(one);
    return answer;
}