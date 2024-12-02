/**
* Author: Jorge Raul Tzab Lopez
* Github: https://github.com/SJMA11723
*/

#include <bits/stdc++.h>

using namespace std;

int dfs(int u, int L[], int R[], string &s){
    if(u == -1) return 1e9;
    if(L[u] == R[u]) return 0;

    int l = dfs(L[u], L, R, s);
    int r = dfs(R[u], L, R, s);

    if(s[u] == 'U') return 1 + min(l, r);
    if(s[u] == 'L') return min(l, r + 1);
    return min(l + 1, r);
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        string s; cin >> s;
        int L[n], R[n];
        for(int i = 0; i < n; ++i){
            cin >> L[i] >> R[i];
            L[i]--, R[i]--;
        }
        cout << dfs(0, L, R, s) << '\n';
    }
}
