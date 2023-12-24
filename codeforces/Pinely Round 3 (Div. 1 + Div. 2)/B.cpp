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
        uint64_t arr[n];
        for(int i = 0; i < n; ++i) cin >> arr[i];

        uint64_t ans = 1;
        unordered_set<uint64_t> rem;
        while(rem.size() != 2){
            rem.clear();
            ans *= 2;
            for(int i = 0; i < n; ++i) rem.insert(arr[i] % ans);
        }
        cout << ans << '\n';
    }
}
