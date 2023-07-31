#include <iostream>
#include <set>
#include <vector>

using namespace std;
vector<int> arr;

void print_arr(int N){
	cout << N;
	for (int i =0; i< N; i++){
		if (i%10 ==0)
			cout << "\n";
		cout << arr[i] << " ";
	}
	cout << "\n";
}

int main(){
	int T;
	cin >> T;
	for (int i=0; i< T; i++){
		int M;
		cin  >> M;
		multiset <int> s;
		for(int j = 0; j < M; j++){
			int temp;
			cin >> temp;
			s.insert(temp);
			if(j%2==0){
				auto iter = s.begin();
				for(int k=0; k< (s.size()+1)/2 -1 ; k++){
					iter++;
				}
				arr.push_back(*iter);
			}
		}
		print_arr((M+1)/2);
		arr.clear();
	}
	return 0;
}