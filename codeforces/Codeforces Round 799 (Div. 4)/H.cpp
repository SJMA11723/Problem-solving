/**
* Author: Jorge Raul Tzab Lopez
* Github: https://github.com/SJMA11723
*/

#include <bits/stdc++.h>
#define MAXN 200000

using namespace std;

struct segment_tree{
    struct node{
        int sum, max_subarray, max_prefix, max_suffix;
        int l, r, l_s, r_s, l_p, r_p;
        node(): sum(0), max_subarray(0), max_prefix(0), max_suffix(0){}/// inicializa con el neutro
        node(int x, int pos):l(pos), r(l), l_p(l), r_p(l), l_s(l), r_s(l), sum(x), max_subarray(x), max_prefix(x), max_suffix(x){}
        const node operator+(const node &b)const{
            node res;

            res.sum = sum + b.sum;
            res.max_prefix = max(max_prefix, sum + b.max_prefix);
            res.max_suffix = max(b.max_suffix, max_suffix + b.sum);
            res.max_subarray = max({max_subarray, b.max_subarray, max_suffix + b.max_prefix});

            return res;
        }
    }nodes[4 * MAXN + 1];
    segment_tree(int n){
        build(1, n);
    }

    void build(int left, int right, int pos = 1){
        if(left == right){
            nodes[pos] = node(-1, left);
            return;
        }
        int mid = (left + right) / 2;
        build(left, mid, pos * 2);
        build(mid + 1, right, pos * 2 + 1);
        nodes[pos] = nodes[pos * 2] + nodes[pos * 2 + 1];
    }

    void update(int x, int idx, int left, int right, int pos = 1){
        if(idx < left || right < idx) return;
        if(left == right){
            nodes[pos] = node(x, left);
            return;
        }
        int mid = (left + right) / 2;
        update(x, idx, left, mid, pos * 2);
        update(x, idx, mid + 1, right, pos * 2 + 1);
        nodes[pos] = nodes[pos * 2] + nodes[pos * 2 + 1];
    }

    node query(int l, int r, int left, int right, int pos = 1){
        if(r < left || right < l) return node(); /// Devuelve el neutro
        if(l <= left && right <= r) return nodes[pos];
        int mid = (left + right) / 2;
        return query(l, r, left, mid, pos * 2) + query(l, r, mid + 1, right, pos * 2 + 1);
    }
};

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        int arr[n + 1];
        map<int, vector<int>> indices;
        for(int i = 1; i <= n; ++i){
            cin >> arr[i];
            indices[arr[i]].push_back(i);
        }

        segment_tree tree(n);
        int a, max_subarray = INT_MIN, l, r;
        for(auto &it : indices){
            for(int i : it.second) tree.update(1, i, 1, n);

            auto res = tree.query(1, n, 1, n);
            if(res.max_subarray > max_subarray){
                max_subarray = res.max_subarray;
                a = it.first;
            }

            for(int i : it.second) tree.update(-1, i, 1, n);
        }

        int sum_act = 0, last_l = 0;
        for(int i = 1; i <= n; ++i){
            int x = arr[i] == a ? 1 : -1;

            if(x >= sum_act + x) last_l = i;
            sum_act = max(x, sum_act + x);

            if(sum_act == max_subarray){
                l = last_l;
                r = i;
            }
        }

        cout << a << ' ' << l << ' ' << r << '\n';
    }
}
