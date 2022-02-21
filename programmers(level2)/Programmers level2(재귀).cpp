#include <string>
#include <vector>

using namespace std;

int cnt=0;
void find(int s, int n, int sum){
    if(sum==n){
        cnt++;
        return;
    }
    if(sum>n)return;
    find(s+1,n, sum+s+1);
}
int solution(int n) {
    for(int i=1; i<=n; i++)
        find(i,n,i);
    return cnt;
}