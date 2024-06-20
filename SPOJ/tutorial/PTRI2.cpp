/**
* Author: Jorge Raul Tzab Lopez
* Github: https://github.com/SJMA11723
*/

#include <bits/stdc++.h>
#define MAXN 100'000'000

using namespace std;

int idx = 0;
int f = 1, c = 1;
pair<int, int> ans[MAXN + 1];

void criba(int n){
    if(n < 2) return;

    vector<char> no_primo(n + 1);
    no_primo[0] = no_primo[1] = true;

    for(long long i = 3; i * i <= n; i += 2){
        if(no_primo[i]) continue;
        for(long long j = i * i; j <= n; j += 2 * i)
            no_primo[j] = true;
    }

    ans[2] = {f, c};
    if(c == f){
        f++;
        c = 0;
    }
    c++;
    for(int i = 3; i <= n; i += 2){
        if(!no_primo[i]){
            ans[i] = {f, c};
            if(c == f){
                f++;
                c = 0;
            }
            c++;
        }
    }
    //cout << idx << ' ' << primos[idx - 1] << '\n';
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    criba(MAXN);

    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        if(!ans[n].first) cout << "-1\n";
        else cout << ans[n].first << ' ' << ans[n].second << '\n';
    }
}
