#include <string>
#include <set>
#include <iostream>

using namespace std;

// str -> multiset으로 바꾸기
multiset<string> make_set(string str){
    multiset<string> ms;

    for(int i =0; i <str.size(); i++){
        str[i] = toupper(str[i]);
    }
    for(int i =0; i< str.size() - 1; i++){
        string temp = "";
        if ('A'<= str[i] && str[i]<= 'Z' && 'A'<= str[i+1] && str[i+1]<= 'Z'){
            temp += str[i];
            temp += str[i+1];
            ms.insert(temp);
        }
    }
    return ms;
}

int solution(string str1, string str2) {
    int answer = 0;
    multiset<string> s1 = make_set(str1);
    multiset<string> s2 = make_set(str2);

    double inter_cnt = 0;

    for(auto i : s1){
        if (s2.find(i) != s2.end()){
            inter_cnt++;
            auto it = s2.find(i);
            s2.erase(it);
        }
    }
    double union_cnt = s1.size() + s2.size();

    if(union_cnt == 0) return 65536;
    else{
        cout << inter_cnt <<", "<<union_cnt <<"\n";
        answer = (inter_cnt/union_cnt) * 65536;
    }

    return answer;
}