#include <string>
#include <vector>
#include <map>
#include <sstream>
#include <iostream>
#include <cmath>
using namespace std;

vector<int> solution(vector<int> fees, vector<string> records) {
    vector<int> answer;
    map<string, vector<string>> m;
    for(int i=0; i<records.size(); i++){
        stringstream ss(records[i]);
        vector<string> temp;
        string buf;
        while(ss>>buf) temp.push_back(buf);
        m[temp[1]].push_back(temp[0]);
    }
    map<string, vector<string>>::iterator iter;
    for(iter=m.begin(); iter!=m.end(); iter++){
        vector<string> temp=iter->second;
        int sum=0;
        if(temp.size()%2!=0){
            temp.push_back("23:59");
        }
        for(int i=0; i<temp.size()-1; i+=2){
            int s=stoi(temp[i].substr(0,2))*60+stoi(temp[i].substr(3,2));
            int e=stoi(temp[i+1].substr(0,2))*60+stoi(temp[i+1].substr(3,2));
            sum+=e-s;
        }
        if(sum<=fees[0]) answer.push_back(fees[1]);
        else{
           int f=ceil((double)(sum-fees[0])/fees[2]);
           answer.push_back(fees[1]+f*fees[3]);
        }
    }  
    return answer;
}
