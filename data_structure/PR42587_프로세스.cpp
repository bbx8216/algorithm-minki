#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int solution(vector<int> priorities, int location) {
    int answer = 0;
    int cnt = 1;
    vector<int> sort_priorities;
    queue<pair<int, int> > q;

    for(int i =0; i< priorities.size(); i++){
        sort_priorities.push_back(priorities[i]);
        q.push(make_pair(i, priorities[i]));
    }
    sort(sort_priorities.begin(), sort_priorities.end());

    while(!q.empty()){
        if (q.front().second == sort_priorities.back()){
            if (q.front().first == location){
                answer = cnt;
                q.pop();
                sort_priorities.erase(sort_priorities.end() - 1);
                break;
            }
            else{
                sort_priorities.erase(sort_priorities.end() - 1);
                q.pop();
            }
            cnt++;
        }
        else{
            int temp_l = q.front().first;
            int temp_p = q.front().second;
            q.pop();
            q.push(make_pair(temp_l, temp_p));
        }
    }

    return answer;
}