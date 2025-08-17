/**
* Author: Mäthgic Crüe
* Github: https://github.com/SJMA11723
*/

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<pii> vpii;
typedef vector<pll> vpll;

#define all(x) (x).begin(), (x).end()
#define fi first
#define se second
#define pb push_back
#define sz(x) (int)(x).size()

const ll MOD = 1e9 + 7;

void dfs(int u, vi tree[], vi &ans, int cnt[], bool &ok, int p = -1){
    ans.pb(u + 1);
    for(int v : tree[u]){
        if(v == p) continue;
        if(!ok) break;

        if(!cnt[v]){
            ok = false;
            break;
        }
        cnt[v]--;
        dfs(v, tree, ans, cnt, ok, u);

        ans.pb(u + 1);
        cnt[u]--;
        while(cnt[v] > 0){
            ans.pb(v + 1);
            ans.pb(u + 1);
            cnt[v]--;
            cnt[u]--;
        }
        if(cnt[u] < 0 || cnt[v] < 0){
            ok = false;
            break;
        }
    }
    if(!u && cnt[u]) ok = false;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n; cin >> n;
    int cnt[n];
    for(int &x : cnt) cin >> x;
    vi tree[n];
    for(int i = 1; i < n; ++i){
        int a, b; cin >> a >> b;
        a--, b--;
        tree[a].pb(b);
        tree[b].pb(a);
    }

    bool ok = true;
    vi ans;
    dfs(0, tree, ans, cnt, ok);

    if(ok) for(int i = 0; i < sz(ans); ++i) cout << ans[i] << " \n"[i + 1 == sz(ans)];
    else cout << "0\n";
}