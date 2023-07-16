#include <iostream>
#include <queue>

using namespace std;

int main(){
    int T, N, M, imp, cnt;
    cin >> T;
    for(int i =0 ; i < T; i++){
        cnt = 0;
        cin >> N >> M;
        queue<pair<int,int>> q;
        priority_queue<int> pq;
        for (int j=0; j < N; j++){
            cin >> imp;
            q.push({j,imp});
            pq.push(imp);
        }
        while(!q.empty()){
            int idx = q.front().first;
            int value = q.front().second;
            q.pop();
            if (pq.top() == value){
                pq.pop();
                cnt++;
                if(idx == M){
                    cout << cnt << endl;
                    break;
                }
            }
            else{
                q.push({idx,value});
            }
        }
    }

}