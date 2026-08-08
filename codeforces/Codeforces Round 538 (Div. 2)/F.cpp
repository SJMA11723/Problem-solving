/**
* Author: Jorge Raul Tzab Lopez
* Github: https://github.com/SJMA11723
*/

#include <bits/stdc++.h>
#define MAXN 400001
#define is_on(S, i) ((S) & (1ll << (i)))
using namespace std;

const int MOD = 1e9 + 7;

const int primes[62] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 
                  61, 67, 71, 73, 79, 83, 89, 97, 101, 103, 107, 109, 113, 127, 
                  131, 137, 139, 149, 151, 157, 163, 167, 173, 179, 181, 191, 
                  193, 197, 199, 211, 223, 227, 229, 233, 239, 241, 251, 257, 
                  263, 269, 271, 277, 281, 283, 293};

int idx(int p){
    return lower_bound(primes, primes + 62, p) - primes;
}

int bin_exp(int a, int b){
    if(!b) return 1;
    int tmp = bin_exp(a, b / 2);
    if(b % 2) return 1ll * tmp * tmp % MOD * a % MOD;
    return 1ll * tmp * tmp % MOD;
}

int inv(int x){
    return bin_exp(x, MOD - 2);
}

struct segment_tree{
    struct node{
        int val;
        int64_t active_primes, lazy_primes;
        int lazy_prod;
        node():val(1){
            active_primes = 0;
            lazy_primes = 0;
            lazy_prod = 1;
        }
        node(int x):val(x){
            active_primes = 0;
            lazy_primes = 0;
            lazy_prod = 1;
            for(int i = 2; i * i <= x && x > 1; ++i){
                if(x % i) continue;
                while(x % i == 0) x /= i;
                active_primes |= 1ll << idx(i);
            }
            if(x > 1) active_primes |= 1ll << idx(x);
        }
        const node operator+(const node &b)const{
            node res;
            res.val = 1ll * val * b.val % MOD;
            res.active_primes = active_primes | b.active_primes;
            return res;
        }
    };
    vector<node> nodes;
    segment_tree(int n, int data[]){
        nodes.resize(4 * n + 1);
        build(1, n, data);
    }

    void build(int left, int right, int data[], int pos = 1){
        if(left == right){
            nodes[pos] = node(data[left]);
            return;
        }
        int mid = (left + right) / 2;
        build(left, mid, data, pos * 2);
        build(mid + 1, right, data, pos * 2 + 1);
        nodes[pos] = nodes[pos * 2] + nodes[pos * 2 + 1];
    }

    void combineLazy(int x, int pos){
        nodes[pos].lazy_prod = 1ll * nodes[pos].lazy_prod * x % MOD;
        for(int i = 2; i * i <= x && x > 1; ++i){
            if(x % i) continue;
            while(x % i == 0) x /= i;
            nodes[pos].lazy_primes |= 1ll << idx(i);
        }
        if(x > 1) nodes[pos].lazy_primes |= 1ll << idx(x);
    }

    void combineLazy(int64_t lz_primes, int lz_prod, int pos){
        nodes[pos].lazy_primes |= lz_primes;
        nodes[pos].lazy_prod = 1ll * nodes[pos].lazy_prod * lz_prod % MOD;
    }

    void applyLazy(int pos, int len){
        nodes[pos].active_primes |= nodes[pos].lazy_primes;
        nodes[pos].val = 1ll * nodes[pos].val * bin_exp(nodes[pos].lazy_prod, len) % MOD;
        nodes[pos].lazy_prod = 1;
        nodes[pos].lazy_primes = 0;
    }

    void pushLazy(int pos, int left, int right){
        int len = abs(right - left + 1);
        if(1 < len){
            combineLazy(nodes[pos].lazy_primes, nodes[pos].lazy_prod, pos * 2);
            combineLazy(nodes[pos].lazy_primes, nodes[pos].lazy_prod, pos * 2 + 1);
        }
        applyLazy(pos, len);
    }

    void update(int x, int l, int r, int left, int right, int pos = 1){
        pushLazy(pos, left, right);
        if(r < left || right < l) return;
        if(l <= left && right <= r){
            combineLazy(x, pos);
            pushLazy(pos, left, right);
            return;
        }

        int mid = (left + right) / 2;
        update(x, l, r, left, mid, pos * 2);
        update(x, l, r, mid + 1, right, pos * 2 + 1);
        nodes[pos] = nodes[pos * 2] + nodes[pos * 2 + 1];
    }

    node query(int l, int r, int left, int right, int pos = 1){
        pushLazy(pos, left, right);
        if(r < left || right < l) return node();
        if(l <= left && right <= r) return nodes[pos];
        int mid = (left + right) / 2;
        return query(l, r, left, mid, pos * 2) + query(l, r, mid + 1, right, pos * 2 + 1);
    }
};

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, q; cin >> n >> q;
    int arr[n + 1];
    for(int i = 1; i <= n; ++i) cin >> arr[i];
    segment_tree ST(n, arr);
    while(q--){
        string op; cin >> op;
        if(op == "MULTIPLY"){
            int l, r, x; cin >> l >> r >> x;
            ST.update(x, l, r, 1, n);
        } else {
            int l, r; cin >> l >> r;
            auto node = ST.query(l, r, 1, n);
            int ans = node.val;
            for(int i = 0; i < 62; ++i) if(is_on(node.active_primes, i))
                ans = 1ll * ans * (primes[i] - 1) % MOD * inv(primes[i]) % MOD;
            cout << ans << '\n';
        }
    }
}
