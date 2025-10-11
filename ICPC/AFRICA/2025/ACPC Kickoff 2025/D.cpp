/**
* Author: Jorge Raul Tzab Lopez
* Github: https://github.com/SJMA11723
*/

#include <bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define pb push_back
#define fi first
#define se second

#define MAXLOGN 19
#define is_on(s, i) ((s) & (1 << (i)))

using namespace std;

const int MOD = 1e9 + 7;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        int pos[n], p[n];
        for(int i = 0; i < n; ++i){
            cin >> p[i];
            p[i]--;
            pos[ p[i] ] = i;
        }

        int nxt[MAXLOGN + 1][n], prv[MAXLOGN + 1][n];
        for(int k = 0; k <= MAXLOGN; ++k){
            prv[k][0] = -1;
            for(int i = 1; i < n; ++i){
                if(is_on(p[i - 1], k)) prv[k][i] = 1;
                else prv[k][i] = prv[k][i - 1] + 1;
            }

            nxt[k][n - 1] = -1;
            for(int i = n - 2; 0 <= i; --i){
                if(is_on(p[i + 1], k)) nxt[k][i] = 1;
                else nxt[k][i] = nxt[k][i + 1] + 1;
            }
        }

        set<int> pending;
        for(int i = 1; i <= n; ++i) pending.insert(i);

        int L, R = L = pos[0], acc_or = 0, ans = 0;
        for(int mex = 1; mex < n; ++mex){
            while(pos[mex - 1] <= L){
                acc_or |= p[L];
                pending.erase(p[L]);
                L--;
            }
            while(R <= pos[mex - 1]){
                acc_or |= p[R];
                pending.erase(p[R]);
                R++;
            }

            if(*pending.begin() != mex) continue;

            int a = 0, b = n - 1;
            if(pos[mex] < L) a = pos[mex];
            if(R < pos[mex]) b = pos[mex];

            ans += 1ll * acc_or * mex % MOD * (L - a) % MOD * (b - R) % MOD;
            if(ans >= MOD) ans -= MOD;

            for(int k = 0; k <= MAXLOGN; ++k){
                int x = L - prv[k][L], y = R + nxt[k][R];
                if(prv[k][L] == -1) x = -1;
                if(nxt[k][R] == -1) y = n;
                if(a <= x && y <= b){
                    ans += (1ll * (x - a + 1) * (b - y + 1) % MOD + 1ll * (L - x - 1) * (b - y + 1) % MOD + 1ll * (y - R - 1) * (x - a + 1) % MOD) % MOD * (1ll << k) % MOD * mex % MOD;
                    if(ans >= MOD) ans -= MOD;
                } else if(x < a && y <= b){
                    ans += 1ll * (L - a) * (b - y + 1) % MOD * (1ll << k) % MOD * mex % MOD;
                    if(ans >= MOD) ans -= MOD;
                } else if(a <= x && b < y){
                    ans += 1ll * (b - R) * (x - a + 1) % MOD * (1ll << k) % MOD * mex % MOD;
                    if(ans >= MOD) ans -= MOD;
                }
            }
        }
        cout << ans << '\n';
    }
}
