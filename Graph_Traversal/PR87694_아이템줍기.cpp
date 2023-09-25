#include <string>
#include <vector>
#include <iostream>
#include <queue>

using namespace std;
int map[101][101];
bool visited[101][101];
queue<pair<int, pair<int, int> > > q;
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

int solution(vector<vector<int>> rectangle, int characterX, int characterY, int itemX, int itemY) {
    int answer = 0;
    // 1) 이동가능한 곳 표시
    for (int i = 0; i < rectangle.size(); i++){
        int x1 = rectangle[i][0]*2;
        int y1 = rectangle[i][1]*2;
        int x2 = rectangle[i][2]*2;
        int y2 = rectangle[i][3]*2;

        for(int j = y1 ; j <= y2; j++){
            map[x1][j] = 1;
            map[x2][j] = 1;
        }
        for(int j = x1 ; j <= x2; j++){
            map[j][y1] = 1;
            map[j][y2] = 1;
        }
        for(int j = x1 + 1; j < x2 ; j++){
            for(int k = y1 + 1; k < y2; k++){
                map[j][k] = 0;
            }
        }
    }
    // 순차에 상관없이 다시 뒤에서부터 앞으로 오면서 겹치는 부분 지우기.
    for (int i = rectangle.size() -1 ; i >= 0 ; i--){
        int x1 = rectangle[i][0]*2;
        int y1 = rectangle[i][1]*2;
        int x2 = rectangle[i][2]*2;
        int y2 = rectangle[i][3]*2;

        for(int j = x1 + 1; j < x2 ; j++){
            for(int k = y1 + 1; k < y2; k++){
                map[j][k] = 0;
            }
        }
    }

    for(int i =0 ; i < 101; i++){
        for (int j = 0; j < 101 ;j++){
            if (map[i][j]==1){
                cout << "("<< i << ", "<< j<<")"<<"\n";
            }
        }
    }

    q.push(make_pair(0, make_pair(characterX*2, characterY*2)));
    while(!q.empty()){
        int cnt = q.front().first;
        int curX = q.front().second.first;
        int curY = q.front().second.second;

        if (curX == itemX*2 && curY == itemY*2){
            answer = cnt/2;
            break;
        }
        q.pop();

        for(int i = 0; i < 4; i++){
            int nX = curX + dx[i];
            int nY = curY + dy[i];
            if (0 <= nX && nX < 101 && 0 <= nY && nY < 101){
                if (map[nX][nY] && !visited[nX][nY]){
                    q.push(make_pair(cnt+1, make_pair(nX, nY)));
                    cout << cnt +1 << ": " <<nX <<", "<< nY <<"\n";
                    visited[nX][nY] = true;
                }
            }
        }
    }
    cout << "fin";
    return answer;
}