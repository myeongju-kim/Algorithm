#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
using namespace std;

vector<int> solution(int n, vector<string> words) {
    vector<int> answer(2,0);
    vector<string> tr;
    map<int, int> m;
    for(int i=0; i<n; i++) m[i]=0;
    for(int i=0; i<words.size(); i++){
        if(tr.empty()){
            tr.push_back(words[i]);
            m[1]++;
            continue;
        }
        if(words[i].front()!=words[i-1].back()){
            if((i+1)%n==0) answer[0]=n;
            else answer[0]=(i+1)%n;
            answer[1]=m[(i+1)%n]+1;
            break;
        }
        if(find(tr.begin(),tr.end(),words[i])!=tr.end()){
            if((i+1)%n==0)answer[0]=n;
            else answer[0]=(i+1)%n;
            answer[1]=m[(i+1)%n]+1;
            break;
        }
        tr.push_back(words[i]);
        m[(i+1)%n]++;
    }

    return answer;
}