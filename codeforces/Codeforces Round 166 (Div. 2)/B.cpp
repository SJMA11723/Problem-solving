/**
* Author: Jorge Raul Tzab Lopez
* Github: https://github.com/SJMA11723
*/

#include <bits/stdc++.h>

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
    criba(2e5, primos);

    int n, m; cin >> n >> m;
    int acc[n + 1][m + 1]; memset(acc, 0, sizeof(acc));
    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= m; ++j){
            int x; cin >> x;
            acc[i][j] = *lower_bound(primos.begin(), primos.end(), x) - x;
            acc[i][j] += acc[i - 1][j] + acc[i][j - 1] - acc[i - 1][j - 1];
        }
    }

    int ans = INT_MAX;
    for(int i = 1; i <= n; ++i) ans = min(ans, acc[i][m] - acc[i - 1][m]);
    for(int i = 1; i <= m; ++i) ans = min(ans, acc[n][i] - acc[n][i - 1]);
    cout << ans << '\n';
}
