#include <iostream>
#include <vector>

using namespace std;

vector<vector<int> > tree;
int N, temp, rm, ans=0;

void remove_node(int root){
	if (root == rm)
		return;
	if (tree[root].size() == 0){
		ans++;
		return;
	}
	if (tree[root].size()==1 && tree[root][0] == rm){
		ans++;
		return;
	}
	for(int i =0; i< tree[root].size();i++){
		remove_node(tree[root][i]);
	}

}
int main(){
	int root;
	cin >> N;
	tree.resize(N+1);
	for (int i =0; i < N; i++){
		cin >> temp;
		if (temp == -1)
			root = i;
		else
			tree[temp].push_back(i);
	}
	cin >> rm;
	remove_node(root);
	cout << ans;
	return 0;
}