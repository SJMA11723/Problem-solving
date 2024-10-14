#include <bits/stdc++.h>
#define MAXL 100000

using namespace std;

int MOD;

int bin_exp(int a, int b){
    if(!b) return 1;
    int tmp = bin_exp(a, b / 2);
    if(b % 2) return 1ll * tmp * tmp % MOD * a % MOD;
    return 1ll * tmp * tmp % MOD;
}

int POWB[MAXL + 1], inv_POWB[MAXL + 1];

struct segment_tree{
    struct node{
        int val;
        node():val(0){}
        node(int x):val(x){}
        const node operator+(const node &b)const{
            return node((val + b.val) % MOD);
        }
    };
    vector<node> nodes;
    segment_tree(int n){
        nodes.resize(4 * n + 1);
    }

    void update(int x, int idx, int left, int right, int pos = 1){
        if(idx < left || right < idx) return;
        if(left == right){
            nodes[pos] = 1ll * x * POWB[idx - 1] % MOD;
            return;
        }
        int mid = left + (right - left) / 2;
        update(x, idx, left, mid, pos * 2);
        update(x, idx, mid + 1, right, pos * 2 + 1);
        nodes[pos] = nodes[pos * 2] + nodes[pos * 2 + 1];
    }

    node query(int l, int r, int left, int right, int pos = 1){
        if(r < left || right < l) return node();
        if(l <= left && right <= r) return nodes[pos];
        int mid = left + (right - left) / 2;
        return query(l, r, left, mid, pos * 2) + query(l, r, mid + 1, right, pos * 2 + 1);
    }
};

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int B, L, N;
    cin >> B >> MOD >> L >> N;
    while(B && MOD && L && N){
        POWB[0] = 1;
        for(int i = 1; i <= L; ++i) POWB[i] = 1ll * B * POWB[i - 1] % MOD;
        inv_POWB[L] = bin_exp(POWB[L], MOD - 2);
        for(int i = L; 0 < i; --i) inv_POWB[i - 1] = 1ll * B * inv_POWB[i] % MOD;
        reverse(POWB, POWB + L);
        //reverse(inv_POWB, inv_POWB + L + 1);

        segment_tree seg_tree(L);
        while(N--){
            char t; cin >> t;
            if(t == 'E'){
                int I, V; cin >> I >> V;
                seg_tree.update(V, I, 1, L);
            } else {
                int I, J; cin >> I >> J;
                cout << 1ll * seg_tree.query(I, J, 1, L).val * inv_POWB[L - J] % MOD << '\n';
            }
        }
        cout << "-\n";
        cin >> B >> MOD >> L >> N;
    }
}
