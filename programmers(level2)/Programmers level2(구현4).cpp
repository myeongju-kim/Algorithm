#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> solution(string s) {
    vector<int> answer(2,0);
    while(1){
        if(s=="1")break;
        for(int i=0; i<s.size(); i++){
            if(s[i]=='0'){
                s.erase(s.begin()+i);
                answer[1]++;
                i--;
            }
        }
        int temp=s.size(); s.clear();
        while(temp>0){
            if(temp%2==0) s.push_back('0');
            else s.push_back('1');
            temp/=2;
        }
        reverse(s.begin(),s.end());
        answer[0]++;
    }
    return answer;
}