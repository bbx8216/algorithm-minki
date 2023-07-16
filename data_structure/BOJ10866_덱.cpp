#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main(){
    int N;
    vector<int> deque;

    cin >> N;
    for (int i = 0; i < N; i++) {
        string cmd;
        cin >> cmd;
        if (cmd == "push_front"){
			int num;
			cin >> num;
            deque.insert(deque.begin(), num);
        }
		else if (cmd == "push_back"){
			int num;
			cin >> num;
			deque.push_back(num);
		}
        else if (cmd =="pop_front"){
            if (deque.empty())
                cout << -1 << "\n";
            else{
                cout << deque.front()<< "\n";
                deque.erase(deque.begin());
            }
        }
		else if (cmd == "pop_back"){
			if (deque.empty())
                cout << -1 << "\n";
			else{
				cout << deque.back() << "\n";
				deque.erase(deque.end() - 1);
			}
		}
        else if (cmd == "size"){
            cout << deque.size()<< "\n";
        }
        else if (cmd == "empty"){
            int res = deque.empty() ? 1 : 0;
            cout << res<< "\n";
        }
        else if (cmd == "front"){
			if (deque.empty())
				cout << -1 <<"\n";
			else
	            cout << deque.front()<< "\n";
        }
		else if (cmd == "back"){
			if (deque.empty())
				cout << -1 <<"\n";
			else
	            cout << deque.back()<< "\n";
        }
    }
    return 0;
}