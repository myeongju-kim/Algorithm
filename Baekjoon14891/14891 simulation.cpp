#include <iostream>
#include <vector>
using namespace std;

string spin(int sign, string cur) {
	if (sign==1) {
		char temp = cur.back();
		cur.pop_back();
		cur.insert(cur.begin(), temp);
	}
	else if (sign==-1) {
		char temp = cur.front();
		cur.erase(cur.begin());
		cur.push_back(temp);
	}
	return cur;

}
int main() {
	vector <string> v;
	for (int i = 0; i < 4; i++) {
		string temp;
		cin >> temp;
		v.push_back(temp);
	}
	int k;
	cin >> k;

	for (int i = 0; i < k; i++) {
		int a, b; cin >> a >> b;
		int index = a - 1;
		if (index == 0) {
			if (v[index][2] != v[1][6]) {
				if (v[1][2] != v[2][6]) {
					if (v[2][2] != v[3][6])
						v[3] = spin(b * -1, v[3]);
					v[2] = spin(b, v[2]);
				}
				v[1] = spin(b * -1, v[1]);
			}
			v[index] = spin(b, v[index]);
		}
		else if(index==1){
			if (v[0][2] != v[index][6]) 
				v[0] = spin(b*-1, v[0]);
			if (v[index][2] != v[2][6]) {
				if (v[2][2] != v[3][6])
					v[3] = spin(b, v[3]);
				v[2] = spin(b*-1, v[2]);
			}
			v[index] = spin(b, v[index]);
		}
		else if (index == 2) {
			if (v[index][2] != v[3][6]) {
				v[3] = spin(b * -1, v[3]);
			}
			if (v[1][2] != v[index][6]) {
				if (v[0][2] != v[1][6])
					v[0] = spin(b, v[0]);
				v[1] = spin(b * -1, v[1]);
			}

			v[index] = spin(b, v[index]);
		}
		else {
			if (v[2][2] != v[index][6]) {
				if (v[1][2] != v[2][6]) {
					if (v[0][2] != v[1][6])
						v[0] = spin(b * -1, v[0]);
					v[1] = spin(b, v[1]);
				}

				v[2] = spin(b * -1, v[2]);
			}
			v[index] = spin(b, v[index]);
		}	
	}
	int score = 0;
	if (v[0][0] == '1') score++;
	if (v[1][0] == '1') score += 2;
	if (v[2][0] == '1') score += 4;
	if (v[3][0] == '1') score += 8;
	cout << score;
}