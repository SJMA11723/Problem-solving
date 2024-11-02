#include<bits/stdc++.h>

using namespace std;

struct segment_tree{
    struct node{
        int val, lazy;
        node(): val(0), lazy(0){}
        node(int x, int lz = 0): val(x), lazy(lz){}
        const node operator+(const node &b)const{
            return node(val + b.val);
        }
    };

    vector<node> nodes;

    segment_tree(int n){
        nodes.resize(4 * n + 1);
    }

    void combine_lazy(int lz, int pos){
        nodes[pos].lazy += lz;
    }

    void apply_lazy(int pos, int tam){
        nodes[pos].val += nodes[pos].lazy * tam;
        nodes[pos].lazy = 0;
    }

    void push_lazy(int pos, int left, int right){
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

        int mid = left + (right - left) / 2;
        update(x, l, r, left, mid, pos * 2);
        update(x, l, r, mid + 1, right, pos * 2 + 1);
        nodes[pos] = nodes[pos * 2] + nodes[pos * 2 + 1];
    }

    node query(int l, int r, int left, int right, int pos = 1){
        push_lazy(pos, left, right);
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
    int n; cin >> n;
    pair<int, int> arr[n];
    for(int i = 0; i < n; ++i){
        cin >> arr[i].first;
        arr[i].second = i + 1;
    }

    sort(arr, arr + n, greater<pair<int, int>>());

    segment_tree seg_tree(n);
    set<int> ap;
    for(auto [x, i] : arr){
        int r, l = r = i;
        auto it = ap.lower_bound(i);
        if(it == ap.end()) r = n;
        else r = i + (*it - i + 1) / 2 - 1;

        if(it == ap.begin()) l = 1;
        else {
            it--;
            l = i - (i - *it + 1) / 2 + 1;
        }

        //cout << i << ' ' << x << '\n';
        //cout << l << ' ' << r << '\n';

        seg_tree.update(1, l, r, 1, n);
        seg_tree.update(-1, i, i, 1, n);

        //for(int j = 1; j <= n; ++j) cout << seg_tree.query(j, j, 1, n).val << " \n"[j == n];

        ap.insert(i);
    }


    for(int i = 1; i <= n; ++i) cout << seg_tree.query(i, i, 1, n).val << " \n"[i == n];
}



