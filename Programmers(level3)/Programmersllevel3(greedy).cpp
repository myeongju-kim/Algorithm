#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int> A, vector<int> B) {
    int answer=0;
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
    while(!A.empty()){
        if(A.back()<B.back()){
            answer++;
            B.pop_back();
        }
        A.pop_back();
    }
    return answer;
}