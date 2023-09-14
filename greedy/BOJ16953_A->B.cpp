#include <iostream>

using namespace std;
int main(){
    int a, b, result=0;
    cin >> a >> b;
    bool success = false;
    while(b >= a){
        if (b == a){
            success = true;
            break;
        }
        if (b % 10 == 1){
            result++;
            b /= 10;
        }
        else if (b % 2 == 0) {
            result++;
            b /= 2;
        }
        else{
            break;
        }
    }
    if (success){
        cout << result + 1;
        return 0;
    }
    cout << -1;
    return 0;
}
