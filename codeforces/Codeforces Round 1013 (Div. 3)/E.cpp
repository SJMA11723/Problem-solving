/**
* Author: Jorge Raul Tzab Lopez
* Github: https://github.com/SJMA11723
*/

#include <bits/stdc++.h>
#define MAXN 10000000

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int64_t ans[MAXN + 1] = {};
    for(int i = 2; i <= MAXN; ++i)
    if(!ans[i]) for(int j = i; j <= MAXN; j += i) ans[j]++;
    for(int i = 1; i <= MAXN; ++i) ans[i] += ans[i - 1];

    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        cout << ans[n] << '\n';
    }
}
