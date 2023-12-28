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
    int m; cin >> m;
    int A[m]; for(int i = 0; i < m; ++i) cin >> A[i];
    pair<int, int> B[m];
    for(int i = 0; i < m; ++i){
        cin >> B[i].first;
        B[i].second = i;
    }

    sort(A, A + m, greater<int>());
    sort(B, B + m);
    int ans[m];
    for(int i = 0; i < m; ++i) ans[B[i].second] = A[i];
    for(int i = 0; i < m; ++i) cout << ans[i] << ' ';
    cout << '\n';
}
