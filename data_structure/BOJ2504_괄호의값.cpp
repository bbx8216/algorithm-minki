// 더럽게 품
#include <iostream>
#include <string>
#include <stack>

using namespace std;

class Data{
public:
	int num;
	char brace;
public:
	Data(int num){
		this->num = num;
		this->brace = '.';
	}
	Data(char brace){
		this->brace = brace;
		this->num = -1;
	}
	bool isNum(){
		if (this->brace == '.')
			return true;
		else
			return false;
	}
};

int calculate(string str){
	stack<char> stack_check;
	for (int i = 0; i < str.length(); i++){
		if (str[i] == '(')
			stack_check.push('(');
		else if (str[i] == ')'){
			if(stack_check.empty())
				return 0;
			else{
				if (stack_check.top() == '(')
				stack_check.pop();
			else
				return 0;
			}
		}
		else if (str[i] == '[')
			stack_check.push('[');
		else if (str[i] == ']'){
			if(stack_check.empty())
				return 0;
			else{
				if (stack_check.top() == '[')
				stack_check.pop();
			else
				return 0;
			}
			
		}
	}

	stack<Data> stack;
	for (int i = 0; i < str.length(); i++){
		int temp = 0;
		if (str[i] == '('){
			stack.push(Data('('));
		}
		else if (str[i] == ')'){
			if (stack.empty())
				return 0;
			if(stack.top().brace == '('){
				stack.pop();
				stack.push(Data(2));
			}
			else if (stack.top().isNum()){
				while(stack.top().isNum()){
					temp += stack.top().num;
					stack.pop();
				}
				temp = temp * 2;
				stack.pop();
				stack.push(Data(temp));
			}
			else return 0;
		}
		else if (str[i] == '['){
			stack.push(Data('['));
		}
		else if (str[i] == ']'){
			if (stack.empty())
				return 0;
			if(stack.top().brace == '['){
				stack.pop();
				stack.push(Data(3));
			}
			else if (stack.top().isNum()){
				while(stack.top().isNum() ){
					temp += stack.top().num;
					stack.pop();
				}
				temp = temp * 3;

				stack.pop();
				stack.push(Data(temp));
			}
			else return 0;
		}
	}
	int ans = 0;
	while(!stack.empty()){
		if (stack.top().isNum()){
			ans += stack.top().num;
			stack.pop();
		}
		else return 0;
	}
	return ans;
}
int main(){
	string str;
	int ans;
	cin >> str;
	// 올바르지 못한 괄호열 판단하기
	cout << calculate(str);
	return 0;
}