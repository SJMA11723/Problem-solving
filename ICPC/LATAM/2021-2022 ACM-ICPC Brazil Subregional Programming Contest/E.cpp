#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n; cin >> n;
    int ans = 0;
    bool pending = false, dir = false;
    for(int i = 0; i < n; ++i){
        int t, d; cin >> t >> d;
        init:
        if(ans <= t){
            if(pending){
                ans += 10;
                dir = !dir;
                pending = false;
                goto init;
            } else {
                ans = t + 10;
                dir = d;
            }
        } else if(dir == d){
            ans = t + 10;
        } else {
            pending = true;
        }
    }
    if(pending) ans += 10;
    cout << ans << '\n';
}
