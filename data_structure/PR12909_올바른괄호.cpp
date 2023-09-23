#include<string>
#include <iostream>
#include<stack>

using namespace std;

bool solution(string s)
{
    bool answer = true;
    bool error = false;
    stack<char> st;
    for(int i = 0; i < s.length(); i++){
        if (s[i] == '(')
            st.push('(');
        else if (s[i] ==')'){
            if (st.empty()){
                error = true;
                break;
            }
            else{
                st.pop();
            }
        }
    }
    if (st.empty() && !error){
        answer = true;
    }
    else{
        answer = false;
    }

    return answer;
}