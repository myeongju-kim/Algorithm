#include <string>
#include <vector>

using namespace std;

int one_cnt=0;
int zero_cnt=0;
vector<vector<int>> map;
bool check(int row, int col, int n){
    int s=map[row][col];
    for(int i=row; i<row+n; i++){
        for(int j=col; j<col+n; j++)
            if(s!=map[i][j])return false;
    }
    return true;
}
void dfs(int row, int col, int n){
    if(check(row, col, n)){
        if(map[row][col]==1) one_cnt++;
        else zero_cnt++;
        return;
    }
    dfs(row,col,n/2);
    dfs(row+n/2,col,n/2);
    dfs(row,col+n/2,n/2);
    dfs(row+n/2,col+n/2,n/2);
    
}
vector<int> solution(vector<vector<int>> arr) {
    vector<int> answer;
    map=arr;
    dfs(0,0,arr.size());
    answer.push_back(zero_cnt);
    answer.push_back(one_cnt);
    return answer;
}