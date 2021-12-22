#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


struct Key {
	int data;
	int num;
};
void Swap(Key& a, Key& b) {
	Key temp = a;
	a = b;
	b = temp;
}

void Sort(vector<Key>& v) {
	Key key;
	int j, i;
	for (i = 1; i < v.size(); i++) {
		key.data = v[i].data;
		key.num = v[i].num;
		for (j = i - 1; j >= 0 && v[j].data > key.data; j--)
			v[j + 1] = v[j];
		v[j + 1] = key;
	}
}
int main() {
	int n;
	vector<Key> vec;
	cin >> n;
	for (int i = 0; i < n; i++) {
		Key k;
		cin >> k.data;
		k.num = i + 1;
		vec.push_back(k);
	}
	Sort(vec);
	int i = 0;
	while (i < n) {
		int count = 0;
		for (int j = i-1; j >= 0; j--) {
			if (vec[j].num > vec[i].num) {
				count++;
			}
		}
		if (count != vec[i].data) {
			Swap(vec[i], vec[i - 1]);
			i--;
		}
		else
			i++;
	}
	for (int i = 0; i < vec.size(); i++)
		cout << vec[i].num << " ";

	return 0;
}