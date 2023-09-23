#include <iostream>
#include <vector>

using namespace std;

int main(){
    int K, N, temp, max = 0;
    vector<int> stick;
    cin >> K >> N;
    for (int i =0; i< K ; i++){
        cin >> temp;
        stick.push_back(temp);
        if (max < temp){
            max = temp;
        }
    }
    long long left = 1;
    long long right = max;
    long long max_ans = 0;
    while(left <= right){
        long long mid = (left + right)/2;
        long long sum_cnt = 0;
        for(int i = 0; i < K; i++){
            int sum = stick[i] / mid;
            sum_cnt += sum;
        }
        if (sum_cnt >= N){
            left = mid + 1;
            if (max_ans < mid)
                max_ans = mid;
        }
        else if (sum_cnt < N)
            right = mid - 1;
    }
    cout << max_ans;
}