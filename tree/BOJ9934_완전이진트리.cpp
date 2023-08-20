#include <iostream>
#include <cmath>
using namespace std;

int in_arr[1024];
int out_arr[1024];
bool visited[1024];
int K, out_idx=0;
int two_pow[11]={2,4,8,16,32,64,128,256,512,1024};

void reverse_inorder(int root_idx, int level){
	if (level == K)
		return;

	for(int i = pow(2,level); i< pow(2,level+1); i++){
		if (!visited[i]){
			out_arr[i]=in_arr[root_idx];
			visited[i]=true;
			break;
		}
	}

	reverse_inorder(root_idx-pow(2,K-2-level), level+1);
	reverse_inorder(root_idx+pow(2,K-2-level), level+1);
}

int main(){
	cin >> K;
	int size = pow(2,K) -1;

	for (int i=0 ; i < size ; i++){
		cin >> in_arr[i];
	}	
	reverse_inorder((int)pow(2,K-1)-1, 0);
	
	int j=0;
	for (int i =1; i < pow(2,K); i++){
		if(i==two_pow[j]){
			j++;
			cout <<"\n";
		}
		cout << out_arr[i]<< " ";
	}
	return 0;
}
// 1 6 4 3 5 2 7

// 4
// 8 1 9 6 10 4 11 3 12 5 13 2 14 7 15

// 1 ~ 2 (2^0 ~ 2^1)
// 2 ~ 4
// 4 ~ 8
