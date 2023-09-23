#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(string x, string y) {
    return x+y > y+x;
}

string solution(vector<int> numbers) {
    string answer = "";

    vector<string> snumbers;
    for (int i=0; i<numbers.size(); i++) {
        snumbers.push_back(to_string(numbers[i]));
    }

    sort(snumbers.begin(), snumbers.end(), compare);

    for (int i=0; i<numbers.size(); i++) {
        answer += snumbers[i];
    }

    if (answer[0] == '0') {
        answer = '0';
    }

    return answer;
}