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
    int n; cin >> n;
    bool prv, prv2; cin >> prv2 >> prv;
    int ans = 0;
    for(int i = 2; i < n; ++i){
        bool nxt; cin >> nxt;
        if(prv2 == nxt && nxt && !prv){
            ans++;
            nxt = 0;
        }
        prv2 = prv;
        prv = nxt;
    }
    cout << ans << '\n';
}
