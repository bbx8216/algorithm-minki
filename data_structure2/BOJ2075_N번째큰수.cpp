#include <iostream>
#include <queue>

using namespace std;
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	
	int N, temp;
	priority_queue<int, vector<int>, greater<int> > pq;
	cin >> N;
	for (int i =0; i < N; i++){
		for(int j= 0; j < N ; j++){
			cin >> temp;
			if (pq.size() <= N){
				pq.push(temp);
			}
			else if (pq.top() < temp){
				pq.pop();
				pq.push(temp);
			}
		}
	}
	pq.pop();
	cout << pq.top();

	return 0;
}