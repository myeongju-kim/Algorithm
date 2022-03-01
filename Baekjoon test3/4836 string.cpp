#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>
#include <string>
using namespace std;

int main() {
	string temp;
	while (getline(cin, temp)) {
		stringstream ss(temp);
		string buf;
		vector<string> vec;
		while (ss >> buf) {
			vec.push_back(buf);
		}
		vector<int> error;
		if (vec[0] == "jiggle") error.push_back(4);
		if (find(vec.begin(), vec.end(), "dip") == vec.end()) error.push_back(5);
		for (int i = 0; i < vec.size(); i++) {
			if (vec[i] == "dip") {
				if (i == 0) {
					int sign = 0;
					for (int j = i + 1; j < vec.size(); j++)
						if (vec[j] == "twirl") sign = 1;
					if (sign == 0) {
						vec[i] = "DIP";
						error.push_back(1);
						continue;
					}
				}
				else if (vec[i - 1] != "jiggle") {
					if (i - 2 < 0) {
						vec[i] = "DIP";
						error.push_back(1);
						continue;
					}
					else if (vec[i - 2] != "jiggle") {
						int sign = 0;
						for (int j = i + 1; j < vec.size(); j++)
							if (vec[j] == "twirl") sign = 1;
						if (sign == 0) {
							vec[i] = "DIP";
							error.push_back(1);
							continue;
						}
					}
				}
			}
		}
		int len = vec.size() - 1;
		if (vec[len] != "clap" || vec[len - 1] != "stomp" || vec[len - 2] != "clap") {
			error.push_back(2);
		}
		if (find(vec.begin(), vec.end(), "twirl") != vec.end()) {
			if (find(vec.begin(), vec.end(), "hop") == vec.end()) {
				error.push_back(3);
			}
		}
		sort(error.begin(), error.end());
		if (error.empty()) {
			cout << "form ok: " << temp << "\n";
		}
		else {
			if (error.size() == 1) {
				cout << "form error " << error[0] << ": ";
				for (int i = 0; i < vec.size() - 1; i++)
					cout << vec[i] << " ";
				cout << vec.back() << "\n";
			}
			else {
				cout << "form errors ";
				for (int i = 0; i < error.size() - 1; i++) {
					if (i + 1 != error.size() - 1) {
						cout << error[i] << ", ";
					}
					else cout << error[i] << " and ";
				}
				cout << error.back() << ": ";
				for (int i = 0; i < vec.size() - 1; i++)
					cout << vec[i] << " ";
				cout << vec.back() << "\n";
			}
		}
	}
}