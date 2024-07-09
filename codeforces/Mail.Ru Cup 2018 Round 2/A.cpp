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
    int n, s; cin >> n >> s;
    s--;
    bool a[n], b[n];
    for(bool &x : a) cin >> x;
    for(bool &x : b) cin >> x;

    if(!a[0] && s){
        cout << "NO\n";
        return 0;
    }

    bool ok = false;
    for(int i = 0; i < n; ++i) ok = ok || (a[i] && (i == s || (s < i && b[s] && b[i])));
    cout << (ok ? "YES\n" : "NO\n");
}
