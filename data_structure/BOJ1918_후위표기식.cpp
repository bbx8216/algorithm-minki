#include <iostream>
#include <string>
#include <stack>
using namespace std;

int prior(char op){
	if (op =='+' || op == '-') 
		return 1;
	if (op =='*' || op == '/') 
		return 2;
	return 0;
}
int main(){
	string str;
	cin >> str;
	stack<char> operator_stack;
	for(int i =0; i < str.length(); i++){
		// 피연산자는 그대로
		if ('A' <= str[i] && str[i] <= 'Z'){
			cout << str[i];
		}
		else{
			// ( 이면 연산자 push
			if (str[i] == '(' || operator_stack.empty()){
				operator_stack.push(str[i]);
				continue;
			}
			// ) 일때
			else if (str[i] == ')'){
				while(operator_stack.top() != '('){
					cout << operator_stack.top();
					operator_stack.pop();
				}
				operator_stack.pop();
				continue;
			}
			// operator 넣기
			if (prior(operator_stack.top()) < prior(str[i])){
				operator_stack.push(str[i]);
			}
			else{
				while(!operator_stack.empty() && prior(str[i]) <= prior(operator_stack.top())){
					cout << operator_stack.top();
					operator_stack.pop();
				}
				operator_stack.push(str[i]);
			}
		}
	}
	while(!operator_stack.empty()){
		cout << operator_stack.top();
		operator_stack.pop();
	}
	return 0;
}