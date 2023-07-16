//왜 틀리는지 이유를 모르겠음.
#include <iostream>
#include <string>
#include <stack>
#include <vector>
#include <set> // 중복 문자열 제거 위함

using namespace std;

vector<pair<int, char> > vec; // 연산자는 -1, 괄호는 사전 순, 숫자는 -2으로 표기
int sel[11] = {0, };
vector<string> ans;
set<string> set_str;

// 괄호는 많으면 10개

void add_ans(){
	string str;
	for(int i =0; i< vec.size(); i++){
		if (vec[i].first >= 0){
			if (!sel[vec[i].first]){
				// select 가 1이면 출력하지 않고, 0이면 출력한다.
				str += vec[i].second;
			}
		}
		else{
				str+= vec[i].second;
		}
	}
	if (set_str.find(str) == set_str.end()){
		set_str.insert(str);
		ans.push_back(str);
	}
}

void selecting(int num_end){
	for (int i = 0; i < (1 << num_end); i++){
		for(int j = 0; j < num_end; j++){
			if (i & (1 << j)){
				sel[j] =1;
			}
		}
		add_ans();
		for (int j = 0; j < 10; j++){
			sel[j] = 0;
		} //init
	}
}
int main(){
	string str;
	stack<pair<int, char> > br;
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> str;
	int number = 0;
	int prior = 10;
	for(int i =0; i < str.length(); i++){
		if (str[i] == '('){
			br.push(make_pair(prior,'('));
			vec.push_back(make_pair(prior, '('));
			number++;
			prior--;
		}
		else if (str[i] == ')'){
			if (br.top().second == '('){
				vec.push_back(make_pair(br.top().first, ')'));
				br.pop();
			}
		}
		else if ('0' <= str[i] && str[i] <= '9'){
			vec.push_back(make_pair(-2, str[i]));
		}
		else {
			vec.push_back(make_pair(-1, str[i]));
		}
	}
	for (int i =0; i < vec.size(); i++){
		if (vec[i].first >= 0){
			vec[i].first -= (prior + 1);
		}
	}
	set_str.insert(str);
	selecting(number);
	for (int i = 0; i< ans.size(); i++){
		cout << ans[i] <<endl;
	}
}