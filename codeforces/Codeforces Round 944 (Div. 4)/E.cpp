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
        int64_t n, k, q; cin >> n >> k >> q;
        int64_t A[k], B[k];
        for(int i = 0; i < k; ++i) cin >> A[i];
        for(int i = 0; i < k; ++i) cin >> B[i];

        while(q--){
            int64_t d; cin >> d;
            int pos = upper_bound(A, A + k, d) - A;
            if(!pos){
                cout << B[0] * d / A[0] << ' ';
                continue;
            }

            if(pos == k){
                cout << B[k - 1] << ' ';
                continue;
            }

            cout << (B[pos] - B[pos - 1]) * (d - A[pos - 1]) / (A[pos] - A[pos - 1]) + B[pos - 1] << ' ';
        }
        cout << '\n';
    }
}
