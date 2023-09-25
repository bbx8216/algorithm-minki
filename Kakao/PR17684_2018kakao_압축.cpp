#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

vector<int> solution(string msg) {
    vector<int> answer;
    vector<string> dict;

    // 초기화
    dict.push_back("0");
    for (int i =0; i< 26; i++){
        char ch = 'A'+i;
        string s = "";
        s+= ch;
        dict.push_back(s);
    }

    // msg 인덱스를 키우면서 가장 긴 문자열 딕셔너리에서 찾기.
    bool findIt;
    int idx = 0;
    int keep = 0;
    while( idx < msg.size()){
        string w = "";
        w += msg[idx];
        findIt = true;
        while(findIt){
            auto it = find(dict.begin(), dict.end(), w);
            if (it == dict.end()){
                // 못 찾은 것 -> 끝난 인덱스 체크, 그 전 길이까지 찾은 단어의 색인 번호 넣기-> 종료하기
                answer.push_back(keep);
                dict.push_back(w);
                findIt = false;
            }
            else if (it != dict.end()){
                // 찾은 것
                keep = it - dict.begin();
                idx++;
                w += msg[idx];
            }
        }
    }


    for(int i =0; i < dict.size() ; i++){
        cout << dict[i] <<", ";
    }
    return answer;
}