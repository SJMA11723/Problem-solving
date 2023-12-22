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
        int B[n], A[n]; A[0] = 1;
        for(int i = 0; i < n; ++i) cin >> B[i];
        for(int i = 0; i + 1 < n; ++i) A[i + 1] = B[i] ? !A[i] : A[i];
        if((A[n - 1] + A[0]) % 2 == B[n - 1]){
            cout << "YES\n";
            continue;
        }

        A[0] = 0;
        for(int i = 0; i + 1 < n; ++i) A[i + 1] = B[i] ? !A[i] : A[i];
        if((A[n - 1] + A[0]) % 2 == B[n - 1]) cout << "YES\n";
        else cout << "NO\n";
    }
}
