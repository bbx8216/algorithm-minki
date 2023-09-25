#include <string>
#include <vector>
#include <queue>

using namespace std;
queue<string> cache;

bool isCityHere(string city, int max_size){
    string temp ="";
    for(int i =0; i < city.size(); i++){
        temp+= toupper(city[i]);
    }
    city = temp;
    bool result = false;
    queue<string> temp_q;
    string keep;
    int temp_size = cache.size();
    for(int i =0; i < temp_size ; i++){
        string cur = cache.front();
        if (cur != city){
            temp_q.push(cur);
        }
        else if (cur == city){
            keep = city;
            result = true;
        }
        cache.pop();
    }

    if (result){
        temp_q.push(keep);
        cache = temp_q;
        return true;
    }
    else{
        if (temp_size == max_size){
            temp_q.push(city);
            temp_q.pop();

        }
        else{
            temp_q.push(city);
        }
        cache = temp_q;
        return false;
    }
}

int solution(int cacheSize, vector<string> cities) {
    int answer = 0;
    int time = 0;
    for(int i =0; i < cities.size(); i++){
        bool decision = isCityHere(cities[i], cacheSize);
        // 캐시안에 시티가 들어있다면,
        if (decision){
            time++;
        }
        else{
            time += 5;
        }
    }


    answer = time;
    return answer;
}