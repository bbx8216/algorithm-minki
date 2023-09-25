#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<string> res;
bool visited[10001];

bool dfs(string s, vector<vector<string>> tickets, int cnt){

    if (cnt == tickets.size()) {
        return true;
    }
    for (int i =0; i < tickets.size(); i++){
        if (!visited[i] && s == tickets[i][0]){
            visited[i] = true;
            res.push_back(tickets[i][1]);
            bool resbool = dfs(tickets[i][1], tickets, cnt+1);
            if (resbool) return true;

            visited[i] = false;
        }
    }
    res.pop_back();
    return false;
}
vector<string> solution(vector<vector<string>> tickets) {
    vector<string> answer;
    sort(tickets.begin(), tickets.end());
    res.push_back("ICN");
    dfs("ICN", tickets, 0);
    answer = res;
    return answer;
}