#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
using namespace std;

string solution(string s) {
    string answer = "";
    vector<int> temp;
    stringstream ss(s);
    string buf;
    while(ss>>buf) temp.push_back(stoi(buf));
    answer+=to_string(*min_element(temp.begin(),temp.end()))+" ";
    answer+=to_string(*max_element(temp.begin(),temp.end()));
    return answer;
}