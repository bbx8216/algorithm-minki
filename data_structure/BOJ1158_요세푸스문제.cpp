// queue로 풀기

#include <iostream>
#include <queue>

using namespace std;
int main(){
	int N, K;
	queue<int> queue;
	cin >> N >> K;
	for (int i = 1 ; i <= N ; i++){
		queue.push(i);
	}
	cout << "<";
	while(!queue.empty()){
		for (int i = 0; i < K - 1; i++){
			queue.push(queue.front());
			queue.pop();
		}
		if (queue.size() == 1){
			cout << queue.front();
			queue.pop();
		}
		else{
			cout << queue.front() << ", ";
			queue.pop();
		}
	}
	cout << ">";
	return 0;
}