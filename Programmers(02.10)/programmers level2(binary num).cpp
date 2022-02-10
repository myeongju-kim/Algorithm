#include <string>
#include <vector>

using namespace std;

int check(int n){
    int cnt=0;
    while(n>0){
        if(n%2!=0) cnt++;
        n/=2;
    }
    return cnt;

}

int solution(int n) {
    int answer = 0;
    int i=1;
    while(1){
        if(check(n)==check(n+i)){
            answer=n+i;
            break;
        }
        i++;
    }
    return answer;
}