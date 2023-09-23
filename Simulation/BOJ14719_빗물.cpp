#include <iostream>
#include <vector>

using namespace std;

int main(){
    int H, W, temp;
    vector<int> block;
    cin >> H >> W;
    for (int i =0; i < W; i++){
        cin >> temp;
        block.push_back(temp);
    }
    vector<int> water(W);
    int left= block[0];
    for(int i =0; i < W; i++){
        if (left > block[i]){
            water[i] = left - block[i];
        }
        else{
            left = block[i];
            water[i] = 0;
        }
    }
    int right = block[W-1];
    for (int i  = W-1 ; i>= 0; i--){
        if (right > block[i]){
            water[i] = min(water[i], right-block[i]);
        }
        else{
            right = block[i];
            water[i] = 0;
        }
    }
    int answer = 0;
    for (int i =0; i < W; i++){
        answer += water[i];
    }
    cout << answer;
}