#include <iostream>
#include <vector>

using namespace std;
int N, R;
vector<vector<pair<int, int> > > tree; // 처음엔 node, 두번짼 cost
vector <bool> visited;

int far, max_length = 0;

void findDiameter(int length, int cur){
	visited[cur] = true;

	if (tree[cur].size() == 1){
		if(length > max_length){
			far = cur;
			max_length = length;
		}
	}
	for(int i =0; i < tree[cur].size(); i++){
		if (!visited[tree[cur][i].first]){
			visited[tree[cur][i].first] = true;
			findDiameter(length + tree[cur][i].second, tree[cur][i].first);
			visited[tree[cur][i].first] = true;
		}
	}
}


int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> N;
	int a, b, d;
	tree.resize(N+1);
	visited.resize(N+1);
	for (int i =0; i < N-1; i++){
		cin >> a >> b>> d;
		tree[a].push_back(make_pair(b, d));
		tree[b].push_back(make_pair(a, d));
	}
	// 기둥 길이
	visited[1] = true;
	findDiameter(0, 1);
	for(int i= 1; i<= N; i++){
		visited[i] = false;
	}
	findDiameter(0, far);
	cout << max_length <<"\n";
	return 0;
}