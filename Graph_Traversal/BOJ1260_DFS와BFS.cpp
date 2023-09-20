#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

vector<int> arr[1001];
bool visited[1001];
void dfs(int v){
    visited[v] = true;
    cout << v <<" ";
    if (arr[v].empty())
        return;
    for(int i =0; i < arr[v].size(); i++){
        int next= arr[v][i];
        if (!visited[next])
            dfs(next);
    }
}

void bfs(int v){
    queue<int> q;
    q.push(v);
    visited[v] = true;

    while(!q.empty()){
        int next = q.front();
        cout << next << " ";
        q.pop();
        for (int i = 0; i < arr[next].size(); i++){
            if (!visited[arr[next][i]]) {
                q.push(arr[next][i]);
                visited[arr[next][i]] = true;
            }
        }
    }

}

int main(){
    int N, M, V, temp_s, temp_e;
    cin >> N >> M >> V;
    for (int i = 0; i < M; i++){
        cin >> temp_s >> temp_e;
        arr[temp_s].push_back(temp_e);
        arr[temp_e].push_back(temp_s);
    }
    for (int i = 1; i <= N; i++){
        sort(arr[i].begin(), arr[i].end());
    }

    dfs(V);
    cout <<"\n";
    for(int i =0; i <= N; i++){
        visited[i] = false;
    }
    bfs(V);
    return 0;
}