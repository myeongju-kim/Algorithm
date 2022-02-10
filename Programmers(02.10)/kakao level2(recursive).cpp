#include <string>
#include <vector>
#include <stack>
using namespace std;
int check(string u) {
    stack<char> st;
    for (int i = 0; i < u.size(); i++) {
        if(u[i]=='(') st.push(u[i]);
        else {
            if (st.empty()) return 0;
            if (st.top() == '(')
                st.pop();
        }
    }
    if (st.empty()) return 1;
    else return 0;
}
string jegu(string w) {
    int c_c=0;
    int j_c=0;
    if (check(w)) return w;
    string u, v;
    string temp = "";
    if (w == "")return "";
    for (int i = 0; i < w.size(); i++) {
        if (w[i] == '(')
            c_c++;
        else j_c++;

        if (c_c == j_c) {
            u = w.substr(0, i+1);
            v = w.substr(i + 1, w.size() - 1);
            break;
        }
    }
    if (check(u)) return u + jegu(v);
    temp += "(" + jegu(v) + ")";
    u.erase(u.begin());
    u.erase(--u.end());
    if (u.empty()) return temp;
    else{
        for (int i = 0; i < u.size(); i++) {
            if (u[i] == ')')u[i] = '(';
            else u[i] = ')';
        }
        return temp + u;
    }

}
string solution(string p) {
    string answer = jegu(p);
    return answer;
}