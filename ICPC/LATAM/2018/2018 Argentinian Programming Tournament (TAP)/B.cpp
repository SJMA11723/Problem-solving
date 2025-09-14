#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int64_t d, m, d1, n, d2;
    cin >> d >> m >> d1 >> n >> d2;
    int ans = 0;
    while(d > 0){
        int64_t tmp = d;
        if(m){
            d -= d1 - d;
            m--;
            ans++;
        } else if(n){
            d -= d2 - d;
            n--;
            ans++;
        } else break;

        if(tmp <= d) break;
    }
    if(d > 0) cout << "-1\n";
    else cout << ans << '\n';
}
