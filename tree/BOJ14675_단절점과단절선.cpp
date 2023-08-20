#include <iostream>
#include <vector>

using namespace std;
vector<vector<int> > tree;

int main(){
	int N, a, b;
	ios::sync_with_stdio(false); 
	cin.tie(NULL); cout.tie(NULL);

	cin >> N;
	tree.resize(N+1);
	for (int i = 1; i < N; i++){
		cin >> a >> b;
		tree[a].push_back(b);
		tree[b].push_back(a);
	}
	int q, t, k;
	cin >> q;
	for (int i =0 ; i < q; i++){
		cin >> t >> k;
		if (t == 1){
			if (tree[k].size() == 1){
				cout << "no"<<"\n";
			}
			else
				cout << "yes" << "\n";
		}
		else if (t==2){
			cout << "yes" << "\n";
		}
	}
	return 0;
}