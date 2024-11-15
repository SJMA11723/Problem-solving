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
    int n, k, q; cin >> n >> k >> q;
    int mat[n][k];
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < k; ++j){
            cin >> mat[i][j];
            if(i) mat[i][j] |= mat[i - 1][j];
        }
    }

    while(q--){
        map<int, int> mini, maxi;
        int m; cin >> m;
        while(m--){
            int r, c;
            char o;
            cin >> r >> o >> c;
            r--;
            if(o == '<'){
                if(maxi.count(r)) maxi[r] = min(maxi[r], c);
                else maxi[r] = c;
            } else {
                if(mini.count(r)) mini[r] = max(mini[r], c);
                else mini[r] = c;
            }
        }

        int l = 0, r = n;

        for(auto &it : mini){
            int col = it.first;
            int val = it.second;



            int ll = 0, rr = n;
            while(ll < rr){
                int mid = ll + (rr - ll) / 2;
                if(mat[mid][col] <= val) ll = mid + 1;
                else rr = mid;
            }

            l = max(l, ll);
        }

        for(auto &it : maxi){
            int col = it.first;
            int val = it.second;

            int ll = 0, rr = n;
            while(ll < rr){
                int mid = ll + (rr - ll) / 2;
                if(mat[mid][col] < val) ll = mid + 1;
                else rr = mid;
            }

            r = min(r, rr - 1);
        }

        if(r < l || l == n) cout << "-1\n";
        else cout << l + 1 << '\n';
    }
}
