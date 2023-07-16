#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

struct brace {
	int x;
	int idx;
	int left;
};

bool compare (const brace& x, const brace& y){
	return x.x < y.x;
}

int main(){
	int N, x, r;
	vector<brace> data;

	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> N;

	for (int i =0; i< N; i++){
		cin >> x >> r;
		brace temp1 = { x-r, i, 1 };
		brace temp2 = { x + r, i, 0 };

		data.push_back(temp1);
		data.push_back(temp2);
	}
	sort(data.begin(), data.end(), compare);

	for (int i = 1; i< data.size(); i++){
		if (data[i-1].x == data[i].x){
			cout << "NO";
			return 0;
		}
	}
	stack<int> stack;

	for (int i = 0; i < data.size(); i++){
		if (data[i].left){
			stack.push(data[i].idx);
		}
		else{
			if (stack.top() == data[i].idx){
				stack.pop();
			}
			else{
				cout << "NO";
				return 0;
			}
		}
	}
	cout << "YES";
	return 0;
}