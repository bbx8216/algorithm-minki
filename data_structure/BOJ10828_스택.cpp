#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main(){
    int N;
    stack<int> stack;

    cin >> N;
    for (int i = 0; i < N; i++) {
        string cmd;
        cin >> cmd;
        if (cmd == "push"){
			int num;
			cin >> num;
            stack.push(num);
        }
        else if (cmd =="pop"){
            if (stack.empty())
                cout << -1 << "\n";
            else{
                cout << stack.top()<< "\n";
                stack.pop();
            }
        }
        else if (cmd == "size"){
            cout << stack.size()<< "\n";
        }
        else if (cmd == "empty"){
            int res = stack.empty() ? 1 : 0;
            cout << res<< "\n";
        }
        else if (cmd == "top"){
			if (stack.empty())
				cout << -1 <<"\n";
			else
	            cout << stack.top()<< "\n";
        }
    }
    return 0;
}