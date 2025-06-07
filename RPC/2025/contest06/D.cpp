/**
* Author: Jorge Raul Tzab Lopez
* Github: https://github.com/SJMA11723
*/

#include <bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define pb push_back
#define fi first
#define se second

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int ans = 0;
    for(int i = 0; i < 5; ++i){
        int a, b; cin >> a >> b;
        ans += a * b;
    }
    ans /= 5;
    int a, b; cin >> a >> b;
    cout << ans * a / b << '\n';
}
