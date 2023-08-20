#include <iostream>
#include <vector>

using namespace std;
#define MAX 100001

vector<int> graph[MAX];
bool visited[MAX];
int parent[MAX];
int N;

void dfs(int root){
	visited[root]=true;
	for(int i =0; i< graph[root].size(); i++){
		int next= graph[root][i];
		if (!visited[next]){
			parent[next]=root;
			dfs(next);
		}
	}
}

int main(){
	cin >> N;

	for(int i =0; i < N-1; i++){
		int temp_r, temp_c;
		cin >> temp_r >> temp_c;
		graph[temp_r].push_back(temp_c);
		graph[temp_c].push_back(temp_r);
	}
	dfs(1);
	for (int i =2; i <= N; i++){
		cout << parent[i] << "\n";
	}
	return 0;
}