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

#define MAXVAL 1000000

const int MOD = 1e9 + 7;

int bin_exp(int a, int b){
    if(!b) return 1;
    int tmp = bin_exp(a, b / 2);
    if(b & 1) return 1ll * tmp * tmp % MOD * a % MOD;
    return 1ll * tmp * tmp % MOD;
}

int inv(int x){
    return bin_exp(x, MOD - 2);
}

int phi[MAXVAL + 1];
int lp[MAXVAL + 1];
int last[MAXVAL + 1];

struct segment_tree{
    struct node{
        int val;
        node():val(1){}
        node(int x):val(x){}
        const node operator+(const node &b)const{
            return node(1ll * val * b.val % MOD);
        }
    };
    vector<node> nodes;
    segment_tree(int n, int data[]){
        nodes.resize(4 * n + 1);
        build(0, n - 1, data);
    }

    void build(int l, int r, int data[], int pos = 1){
        if(l == r){
            nodes[pos] = node(data[l]);
            return;
        }
        int mid = (l + r) / 2;
        build(l, mid, data, pos * 2);
        build(mid + 1, r, data, pos * 2 + 1);
        nodes[pos] = nodes[pos * 2] + nodes[pos * 2 + 1];
    }

    void update(int x, int idx, int l, int r, int pos = 1){
        if(idx < l || r < idx) return;
        if(l == r){
            nodes[pos].val = 1ll * nodes[pos].val * x % MOD;
            return;
        }

        int mid = (l + r) / 2;
        update(x, idx, l, mid, pos * 2);
        update(x, idx, mid + 1, r, pos * 2 + 1);
        nodes[pos] = nodes[pos * 2] + nodes[pos * 2 + 1];
    }

    node query(int a, int b, int l, int r, int pos = 1){
        if(b < l || r < a) return node();
        if(a <= l && r <= b) return nodes[pos];
        int mid = (l + r) / 2;
        return query(a, b, l, mid, pos * 2) + query(a, b, mid + 1, r, pos * 2 + 1);
    }
};

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    iota(phi, phi + MAXVAL + 1, 0);
    for(int i = 2; i <= MAXVAL; ++i) if(phi[i] == i)
    for(int j = i; j <= MAXVAL; j += i) phi[j] -= phi[j] / i, lp[j] = i;

    int n; cin >> n;
    int arr[n];
    for(int &x : arr) cin >> x;

    int q; cin >> q;
    vector<pii> queries;
    vpii ends;
    for(int i = 0; i < q; ++i){
        int l, r; cin >> l >> r;
        l--, r--;
        queries.pb({l, r});
        ends.pb({r, i});
    }
    sort(all(ends));
    memset(last, -1, sizeof(last));
    int ans[q], last_added = -1;
    segment_tree ST(n, arr);
    for(auto [r, i] : ends){
        while(last_added < r){
            last_added++;
            while(arr[last_added] > 1){
                int p = lp[arr[last_added]];
                while(arr[last_added] % p == 0) arr[last_added] /= p;
                ST.update(1ll * (p - 1) * inv(p) % MOD, last_added, 0, n - 1);
                if(last[p] != -1) ST.update(1ll * p * inv(p - 1) % MOD, last[p], 0, n - 1);
                last[p] = last_added;
            }
        }
        ans[i] = ST.query(queries[i].fi, queries[i].se, 0, n - 1).val;
    }

    for(int x : ans) cout << x << '\n';
}
