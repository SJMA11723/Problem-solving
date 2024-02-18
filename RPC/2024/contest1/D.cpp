/**
* Author: Jorge Raul Tzab Lopez
* Github: https://github.com/SJMA11723
*/

#include <bits/stdc++.h>
#define MAXN 50'000

using namespace std;

char letter(int n){
    if(n == 0) return 'A';
    else if(n == 1) return 'T';
    else if(n == 2) return 'G';
    return 'C';
}

int num(char c){
    if(c == 'A') return 0;
    else if(c == 'T') return 1;
    else if(c == 'G') return 2;
    return 3;
}

struct segment_tree{
    struct node{
        int cub[4];
        node(){
            memset(cub, 0, sizeof(cub));
        }
        const node operator+(const node &b) const {
            node nuevo;
            for(int i = 0; i < 4; ++i)
                nuevo.cub[i] += cub[i] + b.cub[i];
            return nuevo;
        }
    } nodes[4 * MAXN + 1];

    segment_tree(int n, string &data){
        build(1, n, data);
    }

    void build(int left, int right, string &data, int pos = 1){
        if(left == right){
            nodes[pos].cub[ num( data[left] ) ]++;
            return;
        }

        int mid = (left + right) / 2;
        build(left, mid, data, pos * 2);
        build(mid + 1, right, data, pos * 2 + 1);

        nodes[pos] = nodes[pos * 2] + nodes[pos * 2 + 1];
    }

    node query(int l, int r, int left, int right, int pos = 1){
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
    string str; cin >> str;
    int n = str.size();
    str = '0' + str;
    segment_tree seg_tree(n, str);

    int m; cin >> m;
    while(m--){
        int l, r; cin >> l >> r;
        auto ans = seg_tree.query(l, r, 1, n);

        vector<pair<int, int>> arr;

        for(int i = 0; i < 4; ++i){
            arr.push_back({ans.cub[i], -i});
        }
        sort(arr.begin(), arr.end());

        for(int i = 3; 0 <= i; --i)
            cout << letter(-arr[i].second);
        cout << '\n';
    }
}
