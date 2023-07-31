// 시간초과
#include <iostream>
#include <set>
#include <map>
#include <string>

using namespace std;

struct Problem{
	int level;
	int problem;
	int group;
	Problem(int l, int p, int g):level(l), problem(p), group(g){}
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
map <int, pair<int, int> > assistant;

int main(){
	ios::sync_with_stdio(0);
    cin.tie(0);
	int N, P, L, G, M;
	cin >> N;
	for (int i =0 ; i < N ; i++){
		cin >> P >> L >> G;
		book.insert(Problem(L, P, G));
		assistant[P]=make_pair(L, G);
	}
	cin >> M;
	string str;
	for (int i = 0; i < M; i++){
		cin >> str;
		if(str == "recommend"){
			int G, x;
			cin >> G >> x;
			if (x==1){
				auto iter = book.end();
				for(int k=0; k< book.size(); k++){
					--iter;
					if (iter->group == G)
						break;
				}
				cout << iter->problem << "\n";
			}
			else if (x==-1){
				auto iter = book.begin();
				for(int k=0; k< book.size(); k++){
					if (iter->group == G)
						break;
					iter++;
				}
				cout << iter->problem << "\n";
			}
		}
		else if (str =="recommend2"){
			int x;
			cin >> x;
			if (x == 1){
				cout << book.rbegin()->problem << "\n";
			}
			else if (x== -1){
				cout << book.begin()->problem << "\n";
			}
		}
		else if (str =="recommend3"){
			int x, L;
			cin >> x >> L;
			if (x == 1){
				auto iter = book.begin();
				for(int k=0; k< book.size(); k++){
					if (iter->level >= L)
						break;
					iter++;
				}
				if (iter == book.end()){
					cout << -1 <<"\n";
				}
				else
					cout << iter->problem << "\n";

			}
			else if( x== -1){
				auto iter = book.end();
				for(int k=0; k< book.size(); k++){
					--iter;
					if (iter->level < L)
						break;
				}
				if (iter==book.begin() && iter->level >= L){
					cout << -1 <<"\n";
				}
				else
					cout << iter->problem << "\n";
			}
		}
		else if (str =="add"){
			int P, L, G;
			cin >> P >> L >> G;
			book.insert(Problem(L, P, G));
			assistant[P]=make_pair(L, G);
		}
		else if (str =="solved"){
			int P;
			cin >> P;
			book.erase(Problem(assistant[P].first, P, assistant[P].second));
		}
	}
	return 0;
}