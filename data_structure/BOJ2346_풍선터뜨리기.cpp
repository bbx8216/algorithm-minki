#include <iostream>
#include <vector>

using namespace std;
int main(){
	int N;
	int temp;
	cin >> N;
	vector<pair<int, int> > deq;
	for (int i =0; i < N; i++){
		cin >> temp;
		deq.push_back(make_pair(i+1, temp));
	}
	//1번 터뜨리기
	int num;
	while(!deq.empty()){
		num = deq.front().second;
		cout << deq.front().first << " ";
		deq.erase(deq.begin());
		if (num > 0){
			for(int i =0; i < num - 1; i++){
				deq.push_back(deq.front());
				deq.erase(deq.begin());
			}
		}
		else{
			for(int i =0; i < (-1)* num; i++){
				deq.insert(deq.begin(), deq.back());
				deq.pop_back();
			}
		}
	}
}