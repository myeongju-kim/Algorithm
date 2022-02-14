#include <string>
#include <algorithm>
using namespace std;

int solution(string str1, string str2) {
    transform(str1.begin(), str1.end(), str1.begin(), ::tolower);
	transform(str2.begin(), str2.end(), str2.begin(), ::tolower);

	vector<string> v1;
	vector<string> v2;
    
	for (int i = 0; i < str1.size()-1; i++) {
		string temp;
		if (str1[i] >= 'a' && str1[i] <= 'z' && str1[i + 1] >= 'a' && str1[i + 1] <= 'z') {
			temp += str1[i];
			temp += str1[i + 1];
			v1.push_back(temp);
		}
	}
	for (int i = 0; i < str2.size() - 1; i++) {
		string temp;
		if (str2[i] >= 'a' && str2[i] <= 'z' && str2[i + 1] >= 'a' && str2[i + 1] <= 'z') {
			temp += str2[i];
			temp += str2[i + 1];
			v2.push_back(temp);
		}
	}
	sort(v1.begin(), v1.end());
	sort(v2.begin(), v2.end());
    
	vector<string> buf(v1.size() + v2.size());
	auto iter=set_intersection(v1.begin(), v1.end(), v2.begin(), v2.end(), buf.begin());
	buf.erase(iter, buf.end());
    
	vector<string> buf2(v1.size() + v2.size());
	auto iter2 = set_union(v1.begin(), v1.end(), v2.begin(), v2.end(), buf2.begin());
	buf2.erase(iter2, buf2.end());
    
	if (buf2.size() == 0) return 65536;
    
	double a = buf.size() / (double)buf2.size();
    return a*65536;
}