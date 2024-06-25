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
        int n, k; cin >> n >> k;
        int S[k];
        for(int i = 0; i < k; ++i) cin >> S[i];

        bool ok = true;
        int sig = INT_MAX;
        for(int i = k - 1; 0 < i; --i){
            if(S[i] - S[i - 1] > sig){
                ok = false;
                break;
            }
            sig = S[i] - S[i - 1];
        }

        if(k == n){
            if(ok && S[0] <= sig) cout << "Yes\n";
            else cout << "No\n";
            continue;
        }

        if(ok && 1ll*S[0] - 1ll*(n - k) * sig <= sig) cout << "Yes\n";
        else cout << "No\n";
    }
}
