#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int q; cin >> q;
    while(q--){
        int k; cin >> k;
        int64_t ans = 0;
        while(k--){
            int x; cin >> x; x--;
            ans |= 1ll << x;
        }
        cout << ans << '\n';
    }
}
