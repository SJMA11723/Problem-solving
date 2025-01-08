#include <bits/stdc++.h>
#define MAXVAL 10000

using namespace std;

int gp[MAXVAL + 1];

struct segment_tree{
    struct node{
        int num, val, lazy;
        node(): num(0), val(0),lazy(0){}
        node(int v, int x = 0, int lz = 0): val(v), num(x), lazy(lz){
            if(!x) return;

            val = 0;
            while(x > 1){
                int p = gp[x];
                while(x % p == 0){
                    x /= p;
                    val += p;
                }
            }
        }
        const node operator+(const node &b){
            return node(val + b.val);
        }
    };
    vector<node> nodes;
    segment_tree(int n, int data[]){
        nodes.resize(4 * n + 1);
        build(1, n, data);
    }

    void build(int left, int right, int data[], int pos = 1){
        if(left == right){
            nodes[pos] = node(0, data[left]);
            return;
        }

        int mid = (left + right) / 2;
        build(left, mid, data, pos * 2);
        build(mid + 1, right, data, pos * 2 + 1);
        nodes[pos] = nodes[pos * 2] + nodes[pos * 2 + 1];
    }

    void combine_lazy(int lz, int pos){nodes[pos].lazy = lz;}

    void apply_lazy(int pos, int tam){
        int sum_primes = 0;
        nodes[pos].num = nodes[pos].lazy;
        while(nodes[pos].lazy > 1){
            int p = gp[nodes[pos].lazy];
            while(nodes[pos].lazy % p == 0){
                sum_primes += p;
                nodes[pos].lazy /= p;
            }
        }
        nodes[pos].val = sum_primes * tam;
        nodes[pos].lazy = 0;
    }

    void push_lazy(int pos, int left, int right){
        if(!nodes[pos].lazy) return;

        int tam = right - left + 1;
        if(1 < tam){
            combine_lazy(nodes[pos].lazy, pos * 2);
            combine_lazy(nodes[pos].lazy, pos * 2 + 1);
        }
        apply_lazy(pos, tam);
    }

    void update(int x, int l, int r, int left, int right, int pos = 1){
        push_lazy(pos, left, right);
        if(r < left || right < l) return;
        if(l <= left && right <= r){
            combine_lazy(x, pos);
            push_lazy(pos, left, right);
            return;
        }
        int mid = (left + right) / 2;
        update(x, l, r, left, mid, pos * 2);
        update(x, l, r, mid + 1, right, pos * 2 + 1);
        nodes[pos] = nodes[pos * 2] + nodes[pos * 2 + 1];
    }

    void erase_prime(int idx, int left, int right, int pos = 1){
        push_lazy(pos, left, right);
        if(idx < left || right < idx) return;
        if(left == right){
            if(nodes[pos].num > 1){
                nodes[pos].val -= gp[nodes[pos].num];
                nodes[pos].num /= gp[nodes[pos].num];
            }
            return;
        }

        int mid = (left + right) / 2;
        erase_prime(idx, left, mid, pos * 2);
        erase_prime(idx, mid + 1, right, pos * 2 + 1);
        nodes[pos] = nodes[pos * 2] + nodes[pos * 2 + 1];
    }

    node query(int l, int r, int left, int right, int pos = 1){
        push_lazy(pos, left, right);
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

    bool no_prime[MAXVAL + 1] = {};
    no_prime[0] = no_prime[1] = true;
    gp[0] = gp[1] = 0;
    for(int i = 2; i <= MAXVAL; ++i){
        if(no_prime[i]) continue;
        gp[i] = i;
        for(int m = 2 * i; m <= MAXVAL; m += i){
            no_prime[m] = true;
            gp[m] = i;
        }
    }

    int n; cin >> n;
    int arr[n + 1];
    for(int i = 1; i <= n; ++i) cin >> arr[i];

    segment_tree seg_tree(n, arr);

    int q; cin >> q;
    while(q--){
        int t; cin >> t;
        if(t == 1){
            int idx; cin >> idx;
            seg_tree.erase_prime(idx, 1, n);
        } else if(t == 2){
            int l, r; cin >> l >> r;
            cout << seg_tree.query(l, r, 1, n).val << '\n';
        } else {
            int l, r, x; cin >> l >> r >> x;
            seg_tree.update(x, l, r, 1, n);
        }

        //for(int i = 1; i <= n; ++i) cout << seg_tree.query(i, i, 1, n).val << " \n"[i == n];
    }
}
