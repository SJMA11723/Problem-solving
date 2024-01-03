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
        int n; cin >> n;
        int A[n], B[n];
        for(int i = 0; i < n; ++i) cin >> A[i];
        for(int i = 0; i < n; ++i) cin >> B[i];
        sort(A, A + n);
        sort(B, B + n, greater<int>());

        bool ok = true;
        int sum = A[0] + B[0];
        for(int i = 0; i < n; ++i) ok = ok && (sum == A[i] + B[i]);
        if(ok){
            for(int i = 0; i < n; ++i) cout << A[i] << ' '; cout << '\n';
            for(int i = 0; i < n; ++i) cout << B[i] << ' '; cout << '\n';
        } else cout << "-1\n";
    }
}
