#include <iostream>
#include <vector>

using namespace std;

vector<bool> visited;
vector<int> tree; // tree[자식] = parent
int main(){
	int T;
	cin >> T;
	for (int k =0; k< T; k++){
		int N;
		cin >> N;
		tree.resize(N+1);
		visited.resize(N+1);
		for (int i = 0; i < N-1; i++){
			int a, b;
			cin >> a >> b;
			tree[b] = a;
		}
		int n1, n2;
		cin >> n1 >> n2;
		//visited[n1] = true;
		while(n1 != tree[n1]){
			visited[n1] = true;
			n1= tree[n1];
		}
		while(1){
			if (visited[n2]){
				cout << n2 << "\n"; 
				break;
			}
			n2 = tree[n2];
		}

		for (int i = 1; i <= N; i++){
			visited[i] = false;
			tree[i] = 0;
		}
	}
	return 0;
}