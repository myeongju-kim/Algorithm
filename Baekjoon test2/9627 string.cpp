#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <set>
#include <cmath>
#include <queue>
using namespace std;
vector<string> str1{ "one","two","three","four","five","six","seven","eight","nine","ten" };
vector<string> str2{ "eleven","twelve","thirteen","fourteen","fifteen","sixteen","seventeen","eighteen","nineteen" };
vector<string> str3{ "twenty","thirty","forty","fifty","sixty","seventy","eighty","ninety" };
//100자리는 str1+hundred
int main() {
	vector<string> vec;
	int n; cin >> n;
	int sum = 0;
	int index = 0;
	for (int i = 0; i < n; i++) {
		string temp; cin >> temp;
		vec.push_back(temp);
		if (temp != "$")sum += temp.size();
		else index = i;
	}
	int temp = sum;
	int tsum = sum;
	while (1) {
		sum = tsum;
		if (temp==0) {
			temp++;
			continue;
		}
		if (temp <= 10) {
			sum += str1[temp-1].size();
		}
		else if (temp <= 19) {
			sum += str2[temp - 11].size();
		}
		else if (temp <= 99) {
			int a = temp % 10;
			int b = temp / 10;
			if (a == 0) sum += str3[b - 2].size();
			else sum += str3[b - 2].size() + str1[a - 1].size();
		}
		else {
			int a = temp / 100;
			sum += str1[a - 1].size() + 7;
			int b = (temp % 100) / 10;
			if (b == 0) {
				int c = (temp % 100) % 10;
				if(c!=0) sum +=  str1[c - 1].size();
			}
			else if (b == 1) {
				int c = (temp % 100) % 10;
				if (c == 0) sum += 3;
				else sum += str2[c - 1].size();
			}
			else{
				int c = (temp % 100) % 10;
				if (c == 0) sum += str3[b - 2].size();
				else sum += str3[b - 2].size() + str1[c - 1].size();
			}
		}
		if (temp == sum) break;
		temp++;
	}
	string ok;
	if (temp <= 10) ok = str1[temp - 1];
	else if (temp <= 19) {
		ok += str2[temp - 11];
	}
	else if (temp <= 99) {
		int a = temp % 10;
		int b = temp / 10;
		if (a == 0) ok += str3[b - 2];
		else ok+= str3[b - 2] + str1[a - 1];
	}
	else {
		int a = temp / 100;
		ok += str1[a - 1] + "hundred";
		int b = (temp % 100) / 10;
		if (b == 0) {
			int c = (temp % 100) % 10;
			if (c != 0) ok += str1[c - 1];
		}
		else if (b == 1) {
			int c = (temp % 100) % 10;
			if (c == 0) ok += "ten";
			else ok += str2[c - 1];
		}
		else if (b != 0) {
			int c = (temp % 100) % 10;
			if (c == 0) ok += str3[b - 2];
			else ok += str3[b - 2] + str1[c - 1];
		}
	}
	vec[index] = ok;
	for (int i = 0; i < vec.size(); i++)
		cout << vec[i] << " ";
}
