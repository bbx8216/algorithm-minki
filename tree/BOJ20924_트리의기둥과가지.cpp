#include <iostream>
#include <vector>

using namespace std;
int N, R;
vector<vector<pair<int, int> > > tree; // 처음엔 node, 두번짼 cost
vector <bool> visited;

int giga_node, max_branch = 0;

void findBranch(int length, int cur){
	// 리프 노드일 때
	if (tree[cur].size() == 1){
		if(length > max_branch)
			max_branch = length;
		return;
	}
	for(int i =0; i < tree[cur].size(); i++){
		if (!visited[tree[cur][i].first]){
			visited[tree[cur][i].first] = true;
			findBranch(length + tree[cur][i].second, tree[cur][i].first);
		}
	}
}


int findPole(int length, int root){

	if(tree[root].size() >= 3 || (root == R && tree[root].size() == 2)){
		giga_node = root;
		return length;
	}
	for(int i= 0; i < tree[root].size(); i++){
		if (!visited[tree[root][i].first]){
			visited[tree[root][i].first] = true;
			length = findPole(length+ tree[root][i].second, tree[root][i].first);
		}
	}
	return length;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> N >> R;
	int a, b, d;
	tree.resize(N+1);
	visited.resize(N+1);
	for (int i =0; i < N-1; i++){
		cin >> a >> b>> d;
		tree[a].push_back(make_pair(b, d));
		tree[b].push_back(make_pair(a, d));
	}
	// 기둥 길이
	visited[R] = true;
	int pole = findPole(0, R);
	findBranch(0, giga_node);
	cout << pole << " " << max_branch;
	return 0;
}