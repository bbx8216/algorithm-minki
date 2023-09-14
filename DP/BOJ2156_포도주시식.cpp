#include <iostream>
#include <vector>

using namespace std;

int max(int a, int b, int c){
    if (a < b){
        if (b < c) return c;
        else return b;
    }
    else {
        if (a < c) return c;
        else return a;
    }
};


int main(){
    int n, temp, dp[10000]; // 0: 안넣음, 1: 이거 포함 연속 1회, 2: 이거 포함 연속 2회
    vector<int> wine;
    cin >> n;
    for (int i =0; i < n; i++){
        cin >> temp;
        wine.push_back(temp);
    }
    dp[0] = wine[0];
    dp[1] = wine[0] + wine[1];
    dp[2] = max(wine[0]+wine[1], wine[0]+wine[2], wine[1]+wine[2]);

    for(int i = 3; i < n; i++){
        dp[i] = max(dp[i-1], dp[i-2] + wine[i], dp[i-3]+wine[i-1]+wine[i]);
    }
    cout << dp[n-1];
    return 0;
}