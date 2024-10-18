#include<bits/stdc++.h>

using namespace std;


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int q; cin >> q;
    while(q--){
        int64_t n; cin >> n;
        int64_t ans = sqrt(n);
        while(ans * ans <= n) ans++;
        if(ans % 2 == 0) ans++;
        int64_t cosa = ans / 2 - (n % (ans - 1));
        cout << 4ll * ((ans / 2) * (ans / 2) + cosa * cosa) << '\n';
    }
}
