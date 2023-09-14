#include <iostream>
#include <vector>

using namespace std;

int dp[1500000];
int main(){
    int N, temp_t, temp_p;
    vector<pair<int , int> > v;
    cin >> N;
    int mmax=0;
    for (int i =0; i< N; i++){
        cin >> temp_t >> temp_p;
        v.push_back(make_pair(temp_t, temp_p));
        if (dp[i] != 0){
            if (mmax < dp[i])
                mmax = dp[i];
        }
        dp[i] = mmax;
        dp[i+v[i].first] = max(dp[i] + v[i].second, dp[i+v[i].first]);
    }
    mmax = 0;
    for (int i =0; i<= N; i++){
        if (mmax < dp[i])
            mmax=dp[i];
    }
    cout << mmax;
    return 0;
}
