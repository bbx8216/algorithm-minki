#include<iostream>
#include<vector>
using namespace std;

int main(){
    int n, temp, dp[100000];
    vector<int> v;
    cin >> n;
    for(int i=0; i < n; i++){
        cin >> temp;
        v.push_back(temp);
    }
    dp[0] = v[0];
    int temp_max=dp[0];
    for (int i = 1; i < n ; i++){
        dp[i] = max(dp[i-1] + v[i], v[i]);
        if (temp_max<dp[i])
            temp_max = dp[i];
    }
    cout << temp_max;
    return 0;
}