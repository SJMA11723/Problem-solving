#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int pl, hl, ps, hs, e, g, h;
    cin >> pl >> hl >> ps >> hs >> e >> g >> h;

    int ans = INT_MAX, l, s;
    for(int i = 0; i <= 1000; ++i){
        for(int j = 0; j <= 1000; ++j){
            if(hl * i + hs * j < h) continue;
            int cost = pl * i + ps * j;
            if(cost < g) cost += e;
            
            if(cost < ans){
                ans = cost;
                l = i;
                s = j;
            } else if(cost == ans && i < l){
                l = i;
                s = j;
            }
        }
    }
    cout << ans << ' ' << l << ' ' << s << '\n';
}