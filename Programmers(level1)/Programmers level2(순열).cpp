#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

bool is_true(int n){
    for(int i=2;i<n/2;i++)
        if(n%i==0)
            return false;
    return true;
}
int solution(vector<int> n) {
    int answer = 0;
    vector<int> v(n.size(),0);
    for(int i=0; i<3; i++) v[i]=1;
    do{
        int sum=0;
        for(int i=0; i<n.size(); i++) 
            if(v[i]==1) sum+=n[i];
        if(is_true(sum)) answer++;
        
    }while(prev_permutation(v.begin(),v.end()));
    return answer;
}