#include <string>
#include <vector>

using namespace std;

bool visited[201];

void dfs(int s, int n, vector<vector<int>> computers){
    visited[s] = true;
    for(int i = 0; i < n; i++){
        if (s != i && computers[s][i] == 1 && !visited[i]){
            dfs(i, n, computers);
        }
    }
}

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    for(int i = 0 ; i < n; i++){
        if (!visited[i]){
            dfs(i, n, computers);
            answer++;
        }
    }
    return answer;
}