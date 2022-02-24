#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n, int s) {
    if(n>=s)return {-1};
    vector<int> answer;
    int mid=s/n;
    while(n!=0){
        answer.push_back(s/n);
        s-=s/n;
        n-=1;
    }
    return answer;
}