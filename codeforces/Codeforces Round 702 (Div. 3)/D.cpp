/**
* Author: Jorge Raul Tzab Lopez
* Github: https://github.com/SJMA11723
*/

#include <bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define pb push_back
#define fi first
#define se second

using namespace std;

void build(int l, int r, int p[], int d[], int cur_d = 0){
    if(l == r) return;
    int root = max_element(p + l, p + r) - p;
    d[root] = cur_d;
    build(l, root, p, d, cur_d + 1);
    build(root + 1, r, p, d, cur_d + 1);
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        int p[n];
        for(int &x : p) cin >> x;
        int d[n];
        build(0, n, p, d);
        for(int i = 0; i < n; ++i) cout << d[i] << " \n"[i + 1 == n];
    }
}
