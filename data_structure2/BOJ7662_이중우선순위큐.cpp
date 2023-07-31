#include <iostream>
#include <queue>
#include <map>

using namespace std;

priority_queue<int, vector<int>, less<int> > max_pq;
priority_queue<int, vector<int>, greater<int> > min_pq;
map<int, int> assistant;

void clear(){
	while(!min_pq.empty() && assistant[min_pq.top()]==0){
		min_pq.pop();
	}
	while(!max_pq.empty() && assistant[max_pq.top()]==0){
		max_pq.pop();
	}
}

void init(){
	while(!min_pq.empty())
		min_pq.pop();
	while(!max_pq.empty())
		max_pq.pop();
	assistant.clear();
}
int main(){
	int T, op_num, num;
	char ch;
	cin >> T;
	for (int i =0; i< T; i++){
		init();

		cin >> op_num;
		for (int j = 0; j < op_num; j++){
			cin >> ch >> num;
			if (ch == 'D'){
				if(num == 1){
					if (!max_pq.empty()){
						int max = max_pq.top();
						max_pq.pop();
						assistant[max]--;
					}
				}
				else if (num == -1){
					if (!min_pq.empty()){
						int min = min_pq.top();
						min_pq.pop();
						assistant[min]--;
					}
				}
			}
			else if (ch == 'I'){
				max_pq.push(num);
				min_pq.push(num);
				assistant[num]++;
			}
			clear();
		}
		clear();
		if (min_pq.empty() || max_pq.empty())
			cout << "EMPTY" <<"\n";
		else
			cout << max_pq.top() << " " << min_pq.top() <<"\n";
		init();
	}
	return 0;
}