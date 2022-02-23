#include <iostream>

using namespace std;
int jegu(int n, int a, int b){
    int mid=n/2;
    if(a<=mid && b<=mid) return jegu(n/2,a,b);
    else if(a>mid && b>mid) return jegu(n/2,a-mid,b-mid);
    else{
        int cnt=0;
        while(n>1){
            cnt++;
            n/=2;
        }
        return cnt;
    }
}
int solution(int n, int a, int b)
{
    int answer = 0;

    answer=jegu(n,a,b);

    return answer;
}
