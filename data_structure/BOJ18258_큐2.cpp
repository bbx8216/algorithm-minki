#include <iostream>
#include <queue>
#include <string>
using namespace std;

int main(){
    int N;
    queue<int> queue;
	cin.tie(NULL);
	cin.sync_with_stdio(false);
    cin >> N;
    for (int i = 0; i < N; i++) {
        string cmd;
        cin >> cmd;
        if (cmd == "push"){
			int num;
			cin >> num;
            queue.push(num);
        }
        else if (cmd =="pop"){
            if (queue.empty())
                cout << -1 << "\n";
            else{
                cout << queue.front()<< "\n";
                queue.pop();
            }
        }
        else if (cmd == "size"){
            cout << queue.size()<< "\n";
        }
        else if (cmd == "empty"){
            int res = queue.empty() ? 1 : 0;
            cout << res<< "\n";
        }
        else if (cmd == "front"){
			if (queue.empty())
				cout << -1 <<"\n";
			else
	            cout << queue.front()<< "\n";
        }
		else if (cmd == "back"){
			if (queue.empty())
				cout << -1 <<"\n";
			else
	            cout << queue.back()<< "\n";
        }
    }
    return 0;
}