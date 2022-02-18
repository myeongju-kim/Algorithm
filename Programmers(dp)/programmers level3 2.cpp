int solution(int m, int n, vector<vector<int>> p) {
    int dp[200][200];
    int map[200][200];
    for(int i=0; i<p.size(); i++)
        map[p[i][1]][p[i][0]]=1;
    dp[1][1]=1;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            if (i==1 && j==1)continue;
            if(map[i][j]==1){
                dp[i][j]=0;
                continue;
            }
            dp[i][j]=(dp[i-1][j]+dp[i][j-1])%1000000007;
        }
    }
    return dp[n][m];
}