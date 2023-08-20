#include<iostream>
#include <vector>

using namespace std;

int N;
int node[26][2];

void preorder(int root){
	if (root == '.'-'A')
		return ;
	cout << (char)(root+'A');
	preorder(node[root][0]);
	preorder(node[root][1]);

}

void inorder(int root){
	if (root == '.'-'A')
		return ;
	inorder(node[root][0]);
	cout << (char)(root+'A');
	inorder(node[root][1]);
}

void postorder(int root){
	if (root == '.'-'A')
		return ;
	postorder(node[root][0]);
	postorder(node[root][1]);
	cout << (char)(root+'A');
}

int main(){
	cin >> N;
	for (int i =0; i< N ;i++){
		char root, left, right;
		cin >> root >> left >>right;
		node[root-'A'][0]= left - 'A';
		node[root-'A'][1]= right - 'A';
	}
	preorder(0);
	cout <<"\n";
	inorder(0);
	cout <<"\n";
	postorder(0);
	cout <<"\n";
	return 0;
}