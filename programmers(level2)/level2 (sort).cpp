#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int> A, vector<int> B)
{
    int answer = 0;
    sort(A.begin(), A.end());
    sort(B.begin(),B.end(),greater<int>()); // sort(B.rbegin(), B.rend()); 와 같은 말
    for(int i=0; i<A.size(); i++)
        answer+=A[i]*B[i];

    return answer;
}