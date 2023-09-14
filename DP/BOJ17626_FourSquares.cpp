#include <iostream>
#include <algorithm>
#include <limits.h>

using namespace std;
int main(){
    int dp[50001];
    dp[0] = 0;
    dp[1] = 1;
    int n;
    cin >> n;
    for (int i = 2; i <= n; i++){
        int minNum = INT_MAX;
        //cout << "====i : " << i <<"===="<<"\n";
        for (int j = 1; j <= i / j; j++){
            int j_square = j*j;
            //cout <<"j square: " <<j_square <<"\n";
            if (j_square == i){
                minNum = 1;
            }
            else{
                minNum = min(dp[j_square] + dp[i-j_square], minNum);
            }
        }
        dp[i] = minNum;
    }
    cout << dp[n];
    return 0;
}