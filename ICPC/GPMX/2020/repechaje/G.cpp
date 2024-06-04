#include<bits/stdc++.h>

using namespace std;
int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int64_t L, G; cin >> L >> G;
    int64_t ans = 0;
    while(G--){
        int64_t p; cin >> p;
        int d; cin >> d;
        if(d) ans = max(ans, L - p);
        else  ans = max(ans, p);
    }

    cout << ans << '\n';

    return 0;
}
