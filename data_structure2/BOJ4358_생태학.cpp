#include <iostream>
#include <string>
#include <map>

using namespace std;

int main(){
	string tree;
	double total= 0;
	map<string, int> dogam;

	//freopen("test.txt", "r", stdin);

	while (getline(cin, tree))
        dogam[tree]++, total++;

	map <string, int>::iterator iter;
	cout << fixed;
	cout.precision(4);
	for(iter = dogam.begin(); iter != dogam.end(); iter++){
		cout << iter->first << " " << (iter->second / total)*100 << "\n";
	}
	return 0;
}