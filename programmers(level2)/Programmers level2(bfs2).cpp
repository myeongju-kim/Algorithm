#include <vector>
#include <queue>
using namespace std;
int dx[4]={1,-1,0,0};
int dy[4]={0,0,1,-1};
int visited[101][101];
queue<pair<int,int>> que;
void bfs(int x,int y, vector<vector<int>> map, int n, int m){
    que.push({x,y});
    visited[x][y]=1;
    while(!que.empty()){
        int x=que.front().first;
        int y=que.front().second;
        que.pop();
        for(int i=0; i<4; i++){
            int nx=dx[i]+x;
            int ny=dy[i]+y;
            if(nx>=0 && nx<n && ny>=0 && ny<m && !visited[nx][ny] && map[nx][ny]){
                que.push({nx,ny});
                visited[nx][ny]=visited[x][y]+1;
            }
        }
    } 
}
int solution(vector<vector<int>> maps)
{
    int n=maps.size();
    int m=maps[0].size();
    bfs(0,0,maps,n,m);
    if(visited[n-1][m-1]==0) return -1;
    return visited[n-1][m-1];
}