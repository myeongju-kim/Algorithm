#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
using namespace std;


int main() {
    vector<vector<int>> board{ {0,0,0,0,0} ,{0,0,1,0,3},{0,2,5,0,1},{4,2,4,4,2},{3,5,1,3,1} };
    vector<int> moves{ 1,5,3,5,1,2,5,1,4,3 };
    int answer = 0;
    stack<int> st[31];
    for (int i = 0; i < board[0].size(); i++) {
        for (int j = board.size() - 1; j >= 0; j--)
            if (board[j][i] != 0) st[i + 1].push(board[j][i]);
    }
    stack<int> result;
    for (int i = 0; i < moves.size(); i++) {
        if (!st[moves[i]].empty()) {
            if (result.empty()) {
                result.push(st[moves[i]].top());
                st[moves[i]].pop();
                continue;
            }
            int t = result.top();
            if (t == st[moves[i]].top()) {
                answer += 2;
                result.pop();
            }
            else result.push(st[moves[i]].top());
            st[moves[i]].pop();
        }
    }

    cout << answer << "\n";
}
