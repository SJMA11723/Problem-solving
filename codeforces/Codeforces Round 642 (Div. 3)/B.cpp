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
        int n, k; cin >> n >> k;
        int A[n], B[n];
        for(int i = 0; i < n; ++i) cin >> A[i];
        for(int i = 0; i < n; ++i) cin >> B[i];
        sort(A, A + n);
        sort(B, B + n, greater<int>());

        int ans = 0;
        for(int i = 0; i < n; ++i){
            if(A[i] < B[i] && k) swap(A[i], B[i]), k--;
            ans += A[i];
        }
        cout << ans << '\n';
    }
}
