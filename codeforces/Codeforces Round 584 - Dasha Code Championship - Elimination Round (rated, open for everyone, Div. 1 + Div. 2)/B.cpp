/**
* Author: Jorge Raul Tzab Lopez
* Github: https://github.com/SJMA11723
*/

#include <bits/stdc++.h>
#define MAXN 125

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n; cin >> n;
    string str; cin >> str;
    int cub[MAXN + 1] = {};
    for(int i = 0; i < n; ++i){
        int a, b; cin >> a >> b;
        bool on = str[i] - '0';
        for(int t = 0; t < b; ++t) cub[t] += on;
        for(int t = b; t <= MAXN; ++t){
            if(t % a == b % a) on = !on;
            cub[t] += on;
        }
    }

    int ans = 0;
    for(int i = 0; i <= MAXN; ++i) ans = max(ans, cub[i]);
    cout << ans << '\n';
}
