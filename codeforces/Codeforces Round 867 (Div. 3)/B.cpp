/**
* Author: Jorge Raul Tzab Lopez
* Github: https://github.com/SJMA11723
*/

#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        int64_t maxi1 = LLONG_MIN, maxi2 = LLONG_MIN;
        int64_t mini1 = LLONG_MAX, mini2 = LLONG_MAX;
        for(int i = 0; i < n; ++i){
            int64_t x; cin >> x;
            if(x >= maxi1){
                maxi2 = maxi1;
                maxi1 = x;
            } else if(x > maxi2) maxi2 = x;

            if(x <= mini1){
                mini2 = mini1;
                mini1 = x;
            } else if(x < mini2) mini2 = x;
        }

        cout << max(maxi1 * maxi2, mini1 * mini2) << '\n';
    }
}
