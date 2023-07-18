/**
* Author: Jorge Raul Tzab Lopez
* Github: https://github.com/SJMA11723
*/

#include <bits/stdc++.h>
#define MAXN 9999999

using namespace std;

void criba(int n, vector<bool> &no_primo){
    if(n < 2) return;
    no_primo[0] = no_primo[1] = true;

    for(long long i = 3; i * i <= n; i += 2){
        if(no_primo[i]) continue;
        for(long long j = i * i; j <= n; j += 2 * i)
            no_primo[j] = true;
    }

    for(int i = 4; i <= n; i += 2) no_primo[i] = true;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    vector<bool> no_primo(MAXN + 1);
    vector<int> ans(MAXN + 1);
    criba(MAXN, no_primo);

    for(int i = 0; i * i <= MAXN; ++i){
        for(int j = 0; j * j * j * j + i * i <= MAXN; ++j){
            int num = j * j * j * j + i * i;
            if(!no_primo[num]) ans[num] = 1;
        }
    }

    for(int i = 1; i <= MAXN; ++i) ans[i] += ans[i - 1];

    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        cout << ans[n] << '\n';
    }
}
