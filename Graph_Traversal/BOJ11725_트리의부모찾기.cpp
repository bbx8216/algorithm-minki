#include <iostream>
#include <vector>
#define MAX 100001

using namespace std;

vector<int> graph[MAX];
bool visited[MAX];
int parent[MAX];

void dfs(int root){
    visited[root] = true;
    for (int i =0; i < graph[root].size(); i++){
        int next = graph[root][i];
        if (!visited[next]){
            parent[next] = root;
            dfs(next);
        }
    }
}
int main(){
    int N, temp_r, temp_c;
    cin >> N;
    for (int i =1; i < N; i++){
        cin >> temp_r >> temp_c;
        graph[temp_r].push_back(temp_c);
        graph[temp_c].push_back(temp_r);
    }
    dfs(1);
    for (int i =2; i <= N; i++)
        cout << parent[i] << "\n";
    return 0;
}