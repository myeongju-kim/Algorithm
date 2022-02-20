#include <string>
#include <vector>
#include <cmath>
using namespace std;

string solution(vector<int> n, string hand) {
    string answer = "";
    int l_x=4;
    int l_y=1;
    int r_x=4;
    int r_y=3;
    for(int i=0; i<n.size(); i++){
        if(n[i]==0) n[i]=11;
        if(n[i]==1 || n[i]==4 || n[i]==7){
            answer.push_back('L');
            if(n[i]==1) l_x=1;
            else l_x=n[i]/2;
            l_y=1;
        }
        else if(n[i]==3 || n[i]==6 || n[i]==9){
            answer.push_back('R');
            r_x=n[i]/3;
            r_y=3;
        }
        else{
            int a,b,cur;
            if(n[i]==2){
                a=abs(1-l_x)+abs(2-l_y);
                b=abs(1-r_x)+abs(2-r_y);
                cur=1;
            }
            else if(n[i]==5){
                a=abs(2-l_x)+abs(2-l_y);
                b=abs(2-r_x)+abs(2-r_y);
                cur=2;
            }
            else if(n[i]==8){
                a=abs(3-l_x)+abs(2-l_y);
                b=abs(3-r_x)+abs(2-r_y);
                cur=3;
            }
            else{
                a=abs(4-l_x)+abs(2-l_y);
                b=abs(4-r_x)+abs(2-r_y);
                cur=4;
            }
            if(a==b){
                if(hand[0]=='l'){
                    answer.push_back('L');
                    l_x=cur; l_y=2;
                }
                else{
                    answer.push_back('R');
                    r_x=cur; r_y=2;
                }
            }
            else if(a<b){
                answer.push_back('L');
                l_x=cur; l_y=2;
            }
          else{
                answer.push_back('R');
                r_x=cur; r_y=2;
          }   
        }
    }
    return answer;
}
