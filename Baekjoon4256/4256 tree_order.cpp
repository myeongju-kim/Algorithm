#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;


struct Node {
	struct Node* L;
	struct Node* R;
	int data;
};
Node *find(vector<int> po, vector<int> t, int* visited, Node* head) {
	int hdata;
	Node* newnode = (Node*)malloc(sizeof(Node));
	newnode->L = newnode->R = NULL;
	for (int i = 0; i < po.size(); i++) {
		if (!visited[po[i]]) {
			hdata = po[i];
			visited[po[i]] = 1;
			break;
		}
	}
	newnode->data = hdata;
	head = newnode;
	int index = find(t.begin(), t.end(), hdata) - t.begin();
	vector<int> left(t.begin(), t.begin() + index);
	vector<int> right(t.begin() + index + 1, t.end());
	if(!left.empty())
		head->L = find(po, left, visited, head);
	if(!right.empty())
		head->R = find(po, right, visited, head);
	return head;
}
void postorder(Node* head) {
	if (head->L != NULL) postorder(head->L);
	if (head->R != NULL) postorder(head->R);
	cout << head->data << " ";
}
int main() {
	int t; cin >> t;
	for (int i = 0; i < t; i++) {
		int n; cin >> n;
		vector<int> po;
		vector<int> io;
		int visited[1001] = { 0, };
		for (int i = 0; i < n; i++) {
			int temp; cin >> temp;
			po.push_back(temp);
		}
		for (int i = 0; i < n; i++) {
			int temp; cin >> temp;
			io.push_back(temp);
		}
		Node* head = NULL;
		head = find(po, io, visited, head);
		postorder(head);
		cout << "\n";
	}
}
