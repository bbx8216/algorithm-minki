#include <iostream>
#include <stack>
using namespace std;

int main(){
    int N;
    stack<int> stack;

    cin >> N;
    for (int i = 0; i < N; i++) {
        int num;
        string cmd;
        cin >> cmd>> num;
        if (cmd == "push"){
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
            cout << stack.top()<< "\n";
        }
    }
    return 0;
}