#include <string>
#include <vector>
#include <algorithm>
#include <ctype.h>

using namespace std;

typedef struct{
    string head = "";
    int number;
    string tail = "";
    int idx; // 원래 입력 순서
} filename;

filename parsing(string file, int idx){
    filename temp;
    string snum ="";
    int num_cnt = 0;
    bool isHead = true;
    bool isTail = false;
    for(int i =0; i < file.size(); i++){
        if ((isalpha(file[i])|| file[i]==' ' || file[i] == '-' || file[i]=='.')&& isHead){
            temp.head += tolower(file[i]);
        }
        else if ('0'<= file[i] && file[i] <= '9' && num_cnt<5 && !isTail){
            snum += file[i];
            isHead = false;
            num_cnt++;
        }
        else{
            temp.tail += file[i];
            isTail = true;
        }
    }
    temp.number = stoi(snum);
    temp.idx = idx;
    return temp;
}

bool cmp(filename a, filename b){
    if (a.head < b.head)
        return true;
    else if (a.head > b.head)
        return false;
    else if (a.head == b.head){
        if (a.number < b.number)
            return true;
        else if (a.number > b.number) return false;
        else if (a.number == b.number){
            if (a.idx < b.idx) return true;
            else return false;
        }
    }

}


vector<string> solution(vector<string> files) {
    vector<string> answer;
    vector<filename> filelist;
    for(int i =0 ; i < files.size(); i++){
        filename ftemp = parsing(files[i], i);
        filelist.push_back(ftemp);
    }
    sort(filelist.begin(), filelist.end(), cmp);
    for(int i = 0; i < filelist.size(); i++){
        string temp = files[filelist[i].idx];
        answer.push_back(temp);
    }
    return answer;
}