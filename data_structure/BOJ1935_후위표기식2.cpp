#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main(){
	int N, temp = 0, number[26];
	string str;
	stack<double> stack;
	cin >> N;
	cin >> str;
	for(int i = 0; i < N ; i++){
		cin >> temp;
		number[i] = temp;
	}
	for(int i = 0; i < str.length(); i++){
		if ('A' <= str[i] && str[i] <='Z'){
			stack.push(number[str[i]-'A']);
		}
		else{
			double A, B;
			if(str[i] == '+'){
				B = stack.top();
				stack.pop();
				A = stack.top();
				stack.pop();
				stack.push(A+B);
			}
			else if(str[i] == '-'){
				B = stack.top();
				stack.pop();
				A = stack.top();
				stack.pop();
				stack.push(A-B);
			}
			else if(str[i] == '*'){
				B = stack.top();
				stack.pop();
				A = stack.top();
				stack.pop();
				stack.push(A*B);
			}
			else if(str[i] == '/'){
				B = stack.top();
				stack.pop();
				A = stack.top();
				stack.pop();
				stack.push(A/B);
			}
		}
	}
	cout << fixed;
	cout.precision(2);
	cout << stack.top();
	return 0;
}