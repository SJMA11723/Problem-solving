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
    int n, r; cin >> n >> r;
    bool heater[n];
    for(bool &x : heater) cin >> x;

    bool ok =true;
    int ans = 0;
    bool covered[n] = {};
    for(int i = 0; i < n; ++i){
        if(covered[i]) continue;

        int idx = -1;
        for(int j = min(n - 1, i + r - 1); i <= j; --j){
            if(heater[j]){
                idx = j;
                break;
            }
        }

        if(idx == -1){
            for(int j = i; max(0, i - r + 1) <= j; --j){
                if(heater[j]){
                    idx = j;
                    break;
                }
            }


            if(idx == -1){
                ok = false;
                break;
            }
        }

        ans++;
        for(int j = max(0, idx - r + 1); j < min(n, idx + r); ++j) covered[j] = true;
    }

    cout << (ok ? ans : -1) << '\n';
}
