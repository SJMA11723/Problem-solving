/**
* Author: Jorge Raul Tzab Lopez
* Github: https://github.com/SJMA11723
*/

#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t; cin >> t;
    while(t--){
        int n, m; cin >> n >> m;
        bool ap[n] = {};
        for(int i = 0; i < m; ++i){
            int a, b, c; cin >> a >> b >> c;
            a--, b--, c--;
            ap[b] = true;
        }

        int root = min_element(ap, ap + n) - ap;

        for(int i = 0; i < n; ++i){
            if(i == root) continue;
            cout << root + 1 << ' ' << i + 1 << '\n';
        }
    }
}
