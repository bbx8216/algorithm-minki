#include <iostream>
#include <stack>
#include <string>

using namespace std;
void brace_check(string str){
	stack<char> stack;
	for(int i = 0; i < str.length(); i++){
		if (str[i] == '('){
			stack.push('(');
		}
		else if (str[i] == ')'){
			if (stack.empty()){
				cout << "NO" << "\n";
				return;
			}
			else
				stack.pop();
		}
	}
	if (stack.empty()){
		cout << "YES" <<"\n";
	}
	else{
		cout << "NO" << "\n";
	}
	return;
}

int main(){
	int T;
	cin >> T;
	for (int i = 0; i < T; i++){
		string str;
		cin >> str;
		brace_check(str);
	}
	return 0;
}