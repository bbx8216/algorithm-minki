#include<iostream>
#include <vector>
#include <map>
using namespace std;

int main(){
	
	while(true){
		int n, k, cur_level = 0;
		cin >> n >> k;
		if (n == 0 && k == 0)
			break;
		
		vector<int> tree;
		vector<int> level;
		map<int, int> tree_level;
		
		tree.resize(n+1);
		level.resize(n+1);
		int parent_pass=0;
		int child=0;
		int flag = 0, node_child = 0;
		for (int i =0; i < n; i++){
			int node;
			cin >> node;
			tree[i]=node;
			if (i == 0)
				level[cur_level]++;
			if(i > 0){
				if(node - tree[i-1] >= 2){
					if (flag == 1){
						node_child = child;
						flag = 0;
					}
					child =0;
					parent_pass++;
					if(parent_pass == 1){
						cur_level++;
						//parent_pass = 0;
					}
					if (parent_pass == level[cur_level-1])
						parent_pass=0;
				}
				level[cur_level]++;
				if (node-tree[i-1] == 1){
					child++;
				}
				if (node == k)
					flag = 1;
				
				
				// else if (node - tree[i-1] == 1){
				// 	level[cur_level]++;
				// }
			}
			//cout << node << " "<<cur_level <<" " << parent_pass << " "<< level[cur_level] << "\n";
			tree_level.insert(pair<int, int>(node, cur_level));
		}
		cout << level[tree_level[k]] - node_child -1 << "\n";
	}
	return 0;
}