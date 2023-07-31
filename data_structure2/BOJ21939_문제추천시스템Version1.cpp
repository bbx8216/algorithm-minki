// set 자료구조를 이용해 풀기.
#include <iostream>
#include <set>
#include <map>
#include <string>

using namespace std;

struct Problem{
	int level;
	int problem;
	Problem(int l, int p):level(l), problem(p){}
	bool operator<(const Problem prob) const{
		if (prob.level == this->level){
			return this->problem < prob.problem;
		}
		return this->level < prob.level;
	}
	bool operator>(const Problem prob) const{
		if (prob.level == this->level){
			return this->problem > prob.problem;
		}
		return this->level > prob.level;
	}
};

set <Problem> book;
map <int, int> assistant;


int main(){
	int N, P, L, M;
	cin >> N;
	for (int i =0 ; i < N ; i++){
		cin >> P >> L;
		book.insert(Problem(L, P));
		assistant[P]=L;
	}
	cin >> M;
	string str;
	for (int i = 0; i < M; i++){
		cin >> str;
		if(str == "recommend"){
			int x;
			cin >> x;
			if (x==1){
				cout << book.rbegin()->problem << "\n";
			}
			else if (x==-1){
				cout << book.begin()->problem << "\n";
			}
		}
		else if (str =="add"){
			int P, L;
			cin >> P >> L;
			book.insert(Problem(L, P));
			assistant[P]=L;
		}
		else if (str =="solved"){
			int P;
			cin >> P;
			book.erase(Problem(assistant[P], P));
		}
	}
	return 0;
}