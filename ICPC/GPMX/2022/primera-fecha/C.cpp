#/**
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
typedef vector<pii> vpii;
typedef vector<pll> vpll;

#define all(x) (x).begin(), (x).end()
#define fi first
#define se second
#define pb push_back
#define sz(x) (int)(x).size()
#define MAXK 500000

const ll MOD = 1e9 + 7;

struct segment_tree{
    struct node{
        ll val, lazy;
        node(): val(0), lazy(0){}
    };
    vector<node> nodes;
    segment_tree(int n){
        nodes.resize(2 * n + 1);
    }

    void combine_lz(ll lz, int pos){
        nodes[pos].lazy += lz;
    }

    void apply_lz(int pos, int tam){
        nodes[pos].val += nodes[pos].lazy * tam;
        nodes[pos].lazy = 0;
    }

    void push_lz(int pos, int left, int right){
        int len = right - left + 1;
        int mid = (left + right) / 2;
        if(1 < len){
            combine_lz(nodes[pos].lazy, pos + 1);
            combine_lz(nodes[pos].lazy, pos + 2 * (mid - left + 1));
        }
        apply_lz(pos, len);
    }

    void update(int x, int l, int r, int left, int right, int pos = 1){
        push_lz(pos, left, right);
        if(r < left || right < l) return;
        if(l <= left && right <= r){
            combine_lz(x, pos);
            push_lz(pos, left, right);
            return;
        }
        int mid = (left + right) / 2;
        update(x, l, r, left, mid, pos + 1);
        update(x, l, r, mid + 1, right, pos + 2 * (mid - left + 1));
        nodes[pos].val = nodes[pos + 1].val + nodes[pos + 2 * (mid - left + 1)].val;
    }

    int query(ll &x, int left, int right, int pos = 1){
        push_lz(pos, left, right);
        if(left == right) return left;
        int mid = (left + right) / 2;
        push_lz(pos + 1, left, mid);
        if(nodes[pos + 1].val >= x) return query(x, left, mid, pos + 1);
        x -= nodes[pos + 1].val;
        return query(x, mid + 1, right, pos + 2 * (mid - left + 1));
    }
};

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, q; cin >> n >> q;
    int arr[n];
    for(int &x : arr) cin >> x;

    segment_tree ST(n);
    int L[MAXK + 1], R[MAXK + 1], X[MAXK + 1];
    while(q--){
        int k; cin >> k;        
        ll N = 0;
        for(int i = 0; i < k; ++i){
            cin >> L[i] >> R[i] >> X[i];
            ST.update(X[i], L[i], R[i], 1, n);
            N += 1ll * X[i] * (R[i] - L[i] + 1);
        }
        
        ll x = (N >> 1) + 1;
        int pos_a = ST.query(x, 1, n);
        int a = arr[pos_a - 1], b = a;
        if(!(N & 1)){
            // cochinadas para restar un Qlog(n) de la complejidad
            // por otra parte, suma K
            int prv = 1;
            for(int i = 0; i < k; ++i){
                if(L[i] <= pos_a && pos_a <= R[i]){
                    if(L[i] <= pos_a - 1) prv = pos_a - 1;
                } else if(R[i] < pos_a) prv = max(prv, R[i]);
            }
            if(x == 1) b = arr[prv - 1];
        }

        int ans = a + b;
        if(ans & 1) cout << (ans / 2) << ".5\n";
        else cout << (ans / 2) << '\n';

        for(int i = 0; i < k; ++i)
            ST.update(-X[i], L[i], R[i], 1, n);
    }
}