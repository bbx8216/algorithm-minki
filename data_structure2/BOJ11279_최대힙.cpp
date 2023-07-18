#include <iostream>
#include <queue>

using namespace std;
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	
	int N, temp;
	priority_queue<int> pq;
	cin >> N;
	for (int i =0; i<N; i++){
		cin >> temp;
		if (temp == 0){
			if (pq.empty())
				cout << 0 <<"\n";
			else{
				cout << pq.top() <<"\n";
				pq.pop();
			}
		}
		else{
			pq.push(temp);
		}
	}
	return 0;
}