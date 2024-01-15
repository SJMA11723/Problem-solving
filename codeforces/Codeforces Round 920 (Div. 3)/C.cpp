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
        int64_t n, f, a, b; cin >> n >> f >> a >> b;
        int64_t ant = 0;
        for(int i = 0; i < n; ++i){
            int64_t x; cin >> x;
            f -= min(b, (x - ant) * a);
            ant = x;
        }
        cout << (f > 0 ? "YES\n" : "NO\n");
    }
}
