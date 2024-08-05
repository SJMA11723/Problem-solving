/**
* Author: Jorge Raul Tzab Lopez
* Github: https://github.com/SJMA11723
*/

#include <bits/stdc++.h>

using namespace std;

void criba(int n, vector<int> &primos, vector<int> &lp){
    primos.clear();
    lp.clear();
    if(n < 2) return;

    lp.resize(n + 1);

    for(long long i = 2; i <= n; ++i){
        if(!lp[i]){
            lp[i] = i;
            primos.push_back(i);
        }

        for(int j = 0; i * (long long)primos[j] <= n; ++j){
            lp[i * primos[j]] = primos[j];
            if(primos[j] == lp[i])
                break;
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n; cin >> n;
    map<int, int> cub;
    for(int i = 0; i < 2 * n; ++i){
        int x; cin >> x;
        cub[x]++;
    }

    vector<int> primos, lp;
    criba(2750131, primos, lp);

    vector<int> ans;
    for(auto it = cub.rbegin(); it != cub.rend(); ++it){
        int x = it->first;
        int cnt = it->second;

        if(lp[x] == x){
            int idx = lower_bound(primos.begin(), primos.end(), x) - primos.begin() + 1;

            cub[idx] -= cnt;
            if(!cub[idx]) cub.erase(idx);

            it->second = 0;
            while(cnt--) ans.push_back(idx);
        } else {
            cub[x / lp[x]] -= cnt;
            if(!cub[x / lp[x]]) cub.erase(x / lp[x]);

            it->second = 0;
            while(cnt--) ans.push_back(x);
        }
    }

    for(int i = 0; i < n; ++i) cout << ans[i] << " \n"[i + 1 == n];
}
