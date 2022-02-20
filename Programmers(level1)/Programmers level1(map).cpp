#include <string>
#include <vector>
#include <map>
#include <iostream>
#include <algorithm>
using namespace std;

vector<int> solution(vector<string> id_list, vector<string> report, int k) {
    vector<int> answer;
    map<string, vector<string>> m;
    map<string, int> c;
    for(int i=0; i<report.size(); i++){
        int a=report[i].find(' ');
        string t1=report[i].substr(0,a); string t2=report[i].substr(a+1,report[i].size());
        if(m[t1].empty()){
            m[t1].push_back(t2);
            c[t2]++;
        }
        else{
            if(find(m[t1].begin(),m[t1].end(),t2)==m[t1].end()){
                m[t1].push_back(t2);
                c[t2]++;
            }
        }
    }
    for(int i=0; i<id_list.size(); i++){
        int cnt=0;
        string id=id_list[i];
        for(auto iter=c.begin(); iter!=c.end(); iter++){
            if(iter->second>=k){
                string f=iter->first;
                if(find(m[id].begin(), m[id].end(), f)!=m[id].end()) cnt++;
            }
        }
        answer.push_back(cnt);
    }
    return answer;
}