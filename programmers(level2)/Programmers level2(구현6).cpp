#include <string>
#include <vector>
#include <iostream>
using namespace std;

vector<int> solution(int n, long long left, long long right) {
    vector<int> a;
    int s = 1;
    long long row=left/n;
    long long dump=left%n;
    for (long long i = row; i < n; i++) {
        for (long long j = 0; j < n; j++) {
            if (j <= i) a.push_back(i + 1);
            else a.push_back(j+1);
            if(a.size()>right-left+dump)break;

        }
        if(a.size()>right-left+dump)break;
    }
    vector<int> b(a.begin()+dump, a.end());
    return b;
}