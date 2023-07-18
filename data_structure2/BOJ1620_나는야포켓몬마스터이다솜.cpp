#include <iostream>
#include <string>
#include <map>
#include <cstdlib>

using namespace std;
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	int N, M;
	map<string, int> dict_str;
	map<int, string> dict_num;
	cin >> N >> M;
	for(int i =1; i<= N; i++){
		string name;
		cin >> name;
		dict_str.insert(make_pair(name, i));
		dict_num.insert(make_pair(i, name));
	}
	for (int i = 0; i < M; i++){
		string input;
		cin >> input;
		if ('0' <= input[0] && input[0] <='9'){
			int num;
			num = stoi(input);
			cout << dict_num[num] << "\n";
		}
		else{
			cout << dict_str[input] <<"\n";
		}
	}
	return 0;
}