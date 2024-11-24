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
        int arr[n];
        for(int &x : arr) cin >> x;
        set<int> pending;
        for(int i = 0; i < n; ++i) pending.insert(i + 1);

        bool ok = true;
        int ans[n];
        for(int i = n - 1; 0 <= i; --i){
            auto nxt = pending.upper_bound(arr[i]);
            if(nxt == pending.begin()){
                ok = false;
                break;
            }

            nxt--;
            ans[*nxt - 1] = i + 1;
            pending.erase(nxt);
        }

        if(ok) for(int i = 0; i < n; ++i) cout << ans[i] << " \n"[i + 1 == n];
        else cout << "-1\n";
    }
}
