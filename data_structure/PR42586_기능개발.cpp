#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    vector<int> task;
    for (int i =0; i < progresses.size(); i++){
        int temp = (100 - progresses[i]) / speeds[i];
        if ((100 - progresses[i]) % speeds[i] != 0){
            temp += 1;
        }
        task.push_back(temp);
    }
    answer.push_back(1);
    int temp = task[0];
    for(int i = 1; i < task.size(); i++){
        if (temp > task[i] || temp == task[i]){
            answer.back() += 1;
        }
        else{
            temp = task[i];
            answer.push_back(1);
        }
    }
    return answer;
}