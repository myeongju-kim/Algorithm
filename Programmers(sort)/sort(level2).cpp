#include <string>
#include <vector>
#include <algorithm>
using namespace std;
bool conpare(string a, string b) {
	if (a[0] > b[0])return true;
	else if (a[0] < b[0]) return false;
	else {
		if (a.size() == b.size()) return a > b;
		else {
			string temp = a + b;
			string temp2 = b + a;
			if (temp > temp2) return true;
			else return false;
		}
	}
}
string solution(vector<int> numbers) {
    string answer = "";
    int zero_cnt=0;
    vector<string> ans;
    for(int i=0; i<numbers.size(); i++)
        ans.push_back(to_string(numbers[i]));
    sort(ans.begin(),ans.end(), conpare);
    for(int i=0; i<ans.size(); i++){
        answer+=ans[i];
        if(ans[i]=="0")zero_cnt++;
    }
    if(zero_cnt==ans.size())return "0";
    else return answer;
}