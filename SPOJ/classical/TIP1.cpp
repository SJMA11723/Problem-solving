/**
* Author: Jorge Raul Tzab Lopez
* Github: https://github.com/SJMA11723
*/

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<vi> vvi;
typedef vector<vll> vvll;
typedef vector<pii> vpii;
typedef vector<pll> vpll;

#define all(x) (x).begin(), (x).end()
#define fi first
#define se second
#define pb push_back
#define sz(x) (int)(x).size()

#define MAXN 10000000

const int MOD = 1e9 + 7;

int phi[MAXN + 1];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    for(int i = 0; i <= MAXN; ++i) phi[i] = i;
    for(int i = 2; i <= MAXN; ++i) if(phi[i] == i)
    for(int j = i; j <= MAXN; j += i) phi[j] -= phi[j] / i;

    vi perm;
    for(int i = 2; i <= MAXN; ++i){
        int cub[10] = {};
        int tmp = i;
        while(tmp){
            cub[tmp % 10]++;
            tmp /= 10;
        }
        tmp = phi[i];
        while(tmp){
            cub[tmp % 10]--;
            tmp /= 10;
        }

        if(*max_element(cub, cub + 10) == 0 && *min_element(cub, cub + 10) == 0)
            perm.pb(i);
    }
    
    int t; cin >> t;
    vpii queries(t);
    for(int i = 0; i < t; ++i){
        int m; cin >> m;
        queries[i] = {m, i};
    }
    sort(all(queries));

    int cur_ans = 21, nxt_p = 1;
    for(int i = 0; i < t; ++i){
        while(nxt_p < sz(perm) && perm[nxt_p] < queries[i].fi){
            if(1ll * cur_ans * phi[perm[nxt_p]] > 1ll * perm[nxt_p] * phi[cur_ans]) cur_ans = perm[nxt_p];
            else if(1ll * cur_ans * phi[perm[nxt_p]] == 1ll * perm[nxt_p] * phi[cur_ans]) cur_ans = perm[nxt_p];
            nxt_p++;
        }
        queries[i].fi = cur_ans < queries[i].fi ? cur_ans : -1;
    }
    sort(all(queries), [](pii a, pii b){return a.se < b.se;});

    for(auto [n, i] : queries)
    if(n != -1) cout << n << '\n';
    else cout << "No solution.\n";
}
