#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t; cin >> t;
    while(t--){
        int l, r, a;
        cin >> l >> r >> a;
        int m = r % a + 1;
        int n1 = r / a + r % a;
        if(l <= r - m) cout << max(n1, (r - m) / a + (r - m) % a) << '\n';
        else cout << n1 << '\n';
    }
}
