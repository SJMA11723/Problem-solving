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
        int a, b, n, s;
        cin >> a >> b >> n >> s;
        int cnt = min(a, s / n);
        s -= cnt * n;
        if(s <= b) cout << "YES\n";
        else cout << "NO\n";
    }
}
