/**
* Author: Jorge Raul Tzab Lopez
* Github: https://github.com/SJMA11723
*/

#include <bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define pb push_back
#define fi first
#define se second

#define MAXA 10000ll

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t; cin >> t;
    while(t--){
        int64_t x; cin >> x;
        bool ok = false;
        for(int64_t a = 1; a < min(x, MAXA + 1); ++a){
            int64_t b = cbrt(x - a * a * a);
            if(b > 0 && a * a * a + b * b * b == x) ok = true;
            b--;
            if(b > 0 && a * a * a + b * b * b == x) ok = true;
            b += 2;
            if(b > 0 && a * a * a + b * b * b == x) ok = true;
        }
        cout << (ok ? "YES\n" : "NO\n");
    }
}
