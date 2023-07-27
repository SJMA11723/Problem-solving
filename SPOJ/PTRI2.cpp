/**
* Author: Jorge Raul Tzab Lopez
* Github: https://github.com/SJMA11723
*/

#include <bits/stdc++.h>
#define MAXN 100000000

using namespace std;

void criba(int n, vector<int> &primos){
    primos.clear();
    if(n < 2) return;

    vector<bool> no_primo(n + 1);
    no_primo[0] = no_primo[1] = true;

    for(long long i = 3; i * i <= n; i += 2){
        if(no_primo[i]) continue;
        for(long long j = i * i; j <= n; j += 2 * i)
            no_primo[j] = true;
    }

    primos.push_back(2);
    for(int i = 3; i <= n; i += 2){
        if(!no_primo[i])
            primos.push_back(i);
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    vector<int> primos;
    criba(MAXN, primos);

    pair<int, int> ans[primos.size()];
    int f = 1, c = 1;
    for(int i = 0; i < primos.size(); ++i){
        ans[i] = {f, c};
        if(c == f){
            f++;
            c = 0;
        }
        c++;
    }

    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        auto it = lower_bound(primos.begin(), primos.end(), n);
        int pos = it - primos.begin();
        if(it == primos.end() || *it != n) cout << "-1\n";
        else cout << ans[pos].first << ' ' << ans[pos].second << '\n';
    }
}
