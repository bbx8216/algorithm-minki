#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;
int main(){
	int N, M, ans=0;
	map<string, bool> bagofwords;
	cin >> N >> M;
	for(int i =0; i < N ; i++){
		string temp;
		cin >> temp;
		bagofwords.insert(make_pair(temp, true));
	}
	for (int i=0; i< M; i++){
		string temp;
		cin >> temp;
		if (bagofwords[temp]){
			ans++;
		}
	}
	cout << ans;
	return 0;
}