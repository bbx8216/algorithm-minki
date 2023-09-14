#include <iostream>

using namespace std;

int main(){
    int dp[101][10];
    dp[1][0] = 1;
    int n;
    long long int ans=0;
    cin >> n;

    // 배열 채우기
    dp[1][0] = 0;
    for (int i =1; i<10; i++){
        dp[1][i] = 1;
    }
    for(int i = 2; i<= n; i++){
        for (int j = 0; j < 10; j++){
            if (j == 0){
                dp[i][j] = dp[i-1][j+1];
                //cout << "---"<<dp[i-1][j+1]<<"----\n";
            }
            else if (j == 9){
                dp[i][j] = dp[i-1][j-1];
            }
            else{
                dp[i][j] = (dp[i-1][j-1] + dp[i-1][j+1]) % 1000000000;
            }
        }
    }

    // 정답 구하기
    for (int i = 0;i <10; i++){
        //cout <<"dp[" <<n<<"]["<<i<<"]"<< dp[n][i] <<"\n";
        ans += dp[n][i];
    }
    cout << ans % 1000000000 ;
}

