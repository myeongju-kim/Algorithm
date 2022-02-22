#include <string>
using namespace std;

int visited[11][11][4];
int solution(string dirs) {
    int answer = 0;
    int x = 5, y = 5;
       for (int i = 0; i < dirs.size(); i++) {
        int temp_x = x, temp_y = y;
        int index = 0;
        int index2 = 0;
        if (dirs[i] == 'L') {
            index = 2; 
            index2 = 3;
            temp_y -= 1;
        }
        else if (dirs[i] == 'R') {
            index = 3;
            index2 = 2;
            temp_y += 1;
        }
        else if (dirs[i] == 'U') {
            index = 0;
            index2 = 1;
            temp_x -= 1;
        }
        else if (dirs[i] == 'D') {
            index = 1;
            index2 = 0;
            temp_x += 1;
        }
        if (temp_x < 0 || temp_x>10 || temp_y < 0 || temp_y>10) continue;
        if (!visited[temp_x][temp_y][index]) {
            visited[temp_x][temp_y][index] = true;
            visited[x][y][index2] = true;
            answer++;
        }
        x = temp_x;
        y = temp_y;
    }
    return answer;
}