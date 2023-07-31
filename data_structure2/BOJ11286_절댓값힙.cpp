#include <iostream>
#include <queue>

using namespace std;

struct Data{
	int abs;
	int num;
	Data(int abs, int num) : abs(abs), num(num){}
	bool operator<(const Data d) const{
		if (d.abs == this->abs){ 
			return this->num > d.num;
		}
		return this->abs > d.abs;
	}
};

int main(){
	int N, temp, out_cnt=0;

	//priority_queue<자료형, 구현체, 비교연산자> pq;
	priority_queue<Data> pq;

	cin >> N;
	for (int i =0; i < N; i++){
		cin >> temp;
		if (temp == 0){
			if (pq.empty()){
				cout << 0 << "\n";
			}
			else{
				cout << pq.top().num <<"\n";
				pq.pop();
			}
		}
		else{
			if (temp <0)
				pq.push(Data((-1)*temp, temp));
			else
				pq.push(Data(temp, temp));
		}
	}
	return 0;
}