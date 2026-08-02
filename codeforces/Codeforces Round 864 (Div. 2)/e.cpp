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

#define MAXN 5000000

int phi[MAXN + 1];

const int MOD = 1e9 + 7;

struct segment_tree{
    struct node{
        int opsto1, lca;
        node():lca(0), opsto1(0){}
        node(int x){
            lca = x;
            opsto1 = 0;
            while(x > 1){
                x = phi[x];
                opsto1++;
            }
        }
        const node operator+(const node &b)const{
            node res;
            res.opsto1 = opsto1 + b.opsto1;
            if(lca && b.lca){
                int u = lca, v = b.lca;
                while(u != v){
                    if(u < v) v = phi[v];
                    else u = phi[u];
                }
                res.lca = u;
            } else res.lca = max(lca, b.lca);
            return res;
        }
    };
    vector<node> nodes;
    segment_tree(int n, int data[]){
        nodes.resize(4 * n + 1);
        build(1, n, data);
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

    void update(int x, int a, int b, int l, int r, int pos = 1){
        if(b < l || r < a) return;
        if(nodes[pos].opsto1 == 0) return;
        if(l == r){
            if(nodes[pos].lca > 1){
                nodes[pos].lca = phi[nodes[pos].lca];
                nodes[pos].opsto1--;
            }
            return;
        }

        int mid = (l + r) / 2;
        update(x, a, b, l, mid, pos * 2);
        update(x, a, b, mid + 1, r, pos * 2 + 1);
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
    iota(phi, phi + MAXN + 1, 0);
    for(int i = 2; i <= MAXN; ++i) if(phi[i] == i)
    for(int j = i; j <= MAXN; j += i) phi[j] -= phi[j] / i;

    int n, m; cin >> n >> m;
    int arr[n + 1];
    for(int i = 1; i <= n; ++i) cin >> arr[i];
    segment_tree ST(n, arr);
    while(m--){
        int t, l, r; cin >> t >> l >> r;
        if(t == 1) ST.update(1, l, r, 1, n);
        else {
            auto q = ST.query(l, r, 1, n);
            int ans = q.opsto1;
            int lca = q.lca;
            while(lca > 1){
                lca = phi[lca];
                ans -= r - l + 1;
            }
            cout << ans << '\n';
        }
    }
}
