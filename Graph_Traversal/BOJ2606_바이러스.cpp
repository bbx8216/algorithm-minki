#include <iostream>
#include <vector>

using namespace std;
vector<int> arr[101];
bool visited[101];
int ans = 0;
void dfs(int s){
    visited[s] = true;
    ans++;
    if (arr[s].size() == 0){
        return ;
    }
    for (int i = 0; i < arr[s].size(); i++){
        int next = arr[s][i];
        if (!visited[next]){
            dfs(next);
        }
    }
}
int main(){
    int n, pair, temp_a, temp_b;
    cin >> n;
    cin >> pair;
    for (int i =0; i < pair; i++){
        cin >> temp_a >> temp_b;
        arr[temp_a].push_back(temp_b);
        arr[temp_b].push_back(temp_a);
    }
    dfs(1);
    cout << ans - 1;
    return 0;
}