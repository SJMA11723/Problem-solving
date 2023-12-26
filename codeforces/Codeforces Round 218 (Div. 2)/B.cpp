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
    int a, b; cin >> a >> b;
    int ans = 0, g = gcd(a, b);
    a /= g;
    b /= g;
    if(b < a) swap(a, b);
    for(int i = 5; 1 < i; --i){
        if(i == 4) continue;

        while(b % i == 0){
            ans++;
            b /= i;
        }
        while(a % i == 0){
            ans++;
            a /= i;
        }
    }
    if(a > 1 || b > 1) cout << "-1\n";
    else cout << ans << '\n';
}
