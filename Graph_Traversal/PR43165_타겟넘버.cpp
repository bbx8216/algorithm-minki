#include <string>
#include <vector>
#include <iostream>

using namespace std;
int ans = 0;
void dfs(vector<int> numbers, int dim, int target, int num){
    if (dim == numbers.size()){
        if (num == target){
            ans++;

        }
        return;
    }

    dfs(numbers, dim+1, target, num+numbers[dim]);
    dfs(numbers, dim+1, target, num-numbers[dim]);
}

int solution(vector<int> numbers, int target) {
    int answer = 0;
    dfs(numbers, 0, target, 0);
    answer = ans;
    return answer;
}
