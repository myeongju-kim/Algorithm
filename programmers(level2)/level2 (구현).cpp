#include <string>
#include <vector>

using namespace std;

int mat[101][101];
int tonado[101][101];
void ghlwjs(int x1, int y1, int x2, int y2){
    for (int i = x1; i <= x2; i++) {
        for (int j = y1; j <= y2; j++) {
            if (i > x1 && i<x2 && j>y1 && j < y2) continue;
            else if (i == x1) {
                if (j != y2) tonado[i][j + 1] = mat[i][j];
                else tonado[i + 1][j] = mat[i][j];
            }
            else if (i == x2) {
                if (j != y1) tonado[i][j - 1] = mat[i][j];
                else tonado[i - 1][j] = mat[i][j];
            }
            else {
                if (j == y1) tonado[i - 1][j] = mat[i][j];
                else if (j == y2) tonado[i + 1][j] = mat[i][j];
            }
        }
    }
}
vector<int> solution(int rows, int cols, vector<vector<int>> queries) {
    vector<int> answer;
    int sign = 1;
    for (int i = 1; i <= rows; i++)
        for (int j = 1; j <= cols; j++)
            mat[i][j] = sign++;
    for(int i=0; i<queries.size(); i++){
        int min=9999999;
        ghlwjs(queries[i][0], queries[i][1], queries[i][2], queries[i][3]);
        for (int ii = 1; ii <= rows; ii++) {
            for (int j = 1; j <= cols; j++){
                if (tonado[ii][j] != 0) {
                    if(min>tonado[ii][j]) min=tonado[ii][j];
                    mat[ii][j] = tonado[ii][j];
                    tonado[ii][j] = 0;
                }
            }
        }
        answer.push_back(min);
    }
    return answer;
}