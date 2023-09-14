#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int N, start, end;
    vector <pair<int, int> > v;
    cin >> N;
    for (int i =0; i< N; i++){
        cin >> start >> end;
        v.push_back(make_pair(end, start));
    }


    return 0;
}