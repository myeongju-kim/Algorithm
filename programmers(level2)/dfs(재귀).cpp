#include <string>
#include <vector>

using namespace std;
int cnt=0;

void dfs(int s,int sum, int target, vector<int> numbers){
    if(sum==target && s==numbers.size()){
        cnt++;
        return;
    }   
    if(s>=numbers.size())return;
    dfs(s+1, sum+numbers[s], target, numbers);
    dfs(s+1, sum+numbers[s]*-1, target, numbers);
}
int solution(vector<int> numbers, int target) {
    dfs(0,0,target, numbers);
    return cnt;
}