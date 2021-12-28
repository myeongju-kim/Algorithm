#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
struct belt {
	int num;
	int dur;
	int updown;
	bool robot;
};
int main() {
	int n, k;
	int count = 0;
	int total = 0;
	cin >> n >> k;
	vector<belt> a(n * 2);
	for (int i = 0; i < a.size(); i++) {
		int temp;
		cin >> temp;
		a[i].dur = temp;
		a[i].num = i + 1;
		a[i].robot = false;
		if (i == 0) a[i].updown = 1;
		else if (i == n - 1)a[i].updown = -1;
		else a[i].updown = 0;
	}
	while (1) {
		if (count >= k)break;
		count = 0;
		//1. 벨트가 각 칸 위에 있는 로봇과 함께 한 칸 회전
		belt btemp = a.back();
		btemp.updown = 1;
		a[0].updown = 0;
		a.insert(a.begin(),btemp);
		a.pop_back();
		a[n].updown = 0;
		a[n - 1].updown = -1;
		//2. 로봇이 한칸 이동 (1) 현재 내리는 위치? (2) 이동하려는 칸 내구도 ? (3) 로봇이 존재? 
		//(4) 다음 위치가 내리는 곳이면 내구도 깍고 내리기
		for (int i = a.size()-2; i >= 0; i--) {
			// 한칸 옮긴다음에 또옮기잖아
			if (a[i].robot == true) {
				if (a[i].updown == -1)
					a[i].robot = false; // 내리는 위치면 한칸 이동 필요없이 바로 내림
				else {
					int next=i+1;
					if (i + 1 >= 2 * n) {
						next = 0;
					}
					if (a[next].dur >=1) {
						if (a[next].robot == false) {
							a[next].dur--;
							a[i].robot = false;
							if (a[next].updown == -1) {
								a[next].robot = false;
						}
							else a[next].robot = true;
						}
					}
				}
			}
		}
		//3. 올리는 위치 칸 내구도 0 아니면 올림
		if (a[0].dur > 0) {
			a[0].robot = true;
			a[0].dur--;
		}
		//4 내구도 검사
		for (int i = 0; i < a.size(); i++) {
			if (a[i].dur <= 0)
				count++;
		}
		total++; // 1~4번 조건까지 한 바퀴 돌았음
	}
	cout << total << endl;


	return 0;
}