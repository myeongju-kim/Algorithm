#include <string>
#include <vector>
#include <map>
using namespace std;

vector<string> solution(vector<string> record) {
    vector<string> answer;
    map<string, string> m;
    for (int i = 0; i < record.size(); i++) {
        string act = record[i].substr(0, record[i].find(' '));
        string uid = record[i].substr(record[i].find(' ') + 1, record[i].find_last_of(' ')- record[i].find(' ')-1);
        string name = record[i].substr(record[i].find_last_of(' ') + 1, record[i].size());
        if (act != "Leave") m[uid] = name;
    }
    for (int i = 0; i < record.size(); i++) {
        string act = record[i].substr(0, record[i].find(' '));
        string uid = record[i].substr(record[i].find(' ') + 1, record[i].find_last_of(' ') - record[i].find(' ') - 1);
        if (act=="Enter") answer.push_back(m[uid]+"님이 들어왔습니다.");
        else if (act == "Leave") answer.push_back(m[uid]+"님이 나갔습니다.");
    } 
    return answer;
}