#include <string>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

int solution(int cs, vector<string> c) {
    if(cs==0) return c.size()*5;
    for (int i = 0; i < c.size(); i++){
        for(int j=0; j<c[i].size(); j++)
            if(c[i][j]>='A' && c[i][j]<='Z') c[i][j]+=32;
    }
    vector<string> page;
    int time = 5;
    page.push_back(c[0]);
    vector<int> index;
    index.push_back(0);
    for (int i = 1; i < c.size(); i++) {
        if (find(page.begin(), page.end(), c[i]) != page.end()) {
            time++;
            int o_index = find(page.begin(), page.end(), c[i]) - page.begin();
            int n_index = find(index.begin(), index.end(), o_index) - index.begin();
            index.erase(index.begin()+n_index);
            index.push_back(o_index);
        }
        else {
            if (page.size() == cs) {
                page[index[0]] = c[i];
                index.push_back(index[0]);
                index.erase(index.begin());
            }
            else {
                page.push_back(c[i]);
                index.push_back(page.size() - 1);
            }
            time += 5;
        }
    }
    return time;
}
