#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, H; cin >> n >> H;
    int64_t ans = 0;
    bool ok = true;
    for(int i = 0; i < n; ++i){
        int a, b, c;
        cin >> a >> b >> c; /// l w h

        int mini = INT_MAX;
        if(c <= H) mini = min(mini, min({a, b}));
        if(a <= H) mini = min(mini, min({b, c}));
        if(b <= H) mini = min(mini, min({a, c}));
        if(mini == INT_MAX) ok = false;
        ans += mini;
    }
    if(ok) cout << ans << '\n';
    else cout << "impossible\n";
}
