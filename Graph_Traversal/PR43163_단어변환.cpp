#include <string>
#include <vector>
#include <queue>

using namespace std;

bool check(string a, string b){
    int cnt = 0;
    for (int i = 0; i < a.size(); i++){
        if (a[i] != b[i])
            cnt++;
    }
    if (cnt == 1)
        return true;
    else
        return false;
}

int solution(string begin, string target, vector<string> words) {
    int answer = 0;
    bool cont = false;
    // 타겟이 없는 경우
    for (int i =0; i < words.size(); i++){
        if (target == words[i])
            cont = true;
    }
    if (!cont)
        return answer;

    queue<pair<int, string> > q;
    q.push(make_pair(answer,begin));
    while(!q.empty()){
        int cnt = q.front().first;
        string cur = q.front().second;
        q.pop();
        if (cur == target){
            answer = cnt;
            break;
        }
        for(int i =0; i < words.size(); i++){
            if (check(cur, words[i])){
                q.push(make_pair(cnt+1, words[i]));
            }
        }
    }

    return answer;
}