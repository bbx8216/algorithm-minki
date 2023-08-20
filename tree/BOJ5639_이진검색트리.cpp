#include <iostream>

using namespace std;

int tree[10000];

void post_rev(int start, int end){
	if (start >= end ){
		return ;
	}
	if (start == end - 1){
		cout << tree[start] << "\n";
		return ;
	}
	int separator;
	for(separator = start +1; separator< end; separator++){
		if (tree[separator] > tree[start]){
			break;
		}
	}
	post_rev(start+1, separator);
	post_rev(separator, end);
	cout << tree[start] <<"\n";
}

int main(){
	int key_temp, cnt=0;
	while(cin >> key_temp){
		tree[cnt++]=key_temp;
	}
	post_rev(0, cnt);
	return 0;
}