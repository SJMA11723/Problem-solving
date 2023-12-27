/**
* Author: Jorge Raul Tzab Lopez
* Github: https://github.com/SJMA11723
*/

#include <bits/stdc++.h>

using namespace std;

char vence(char c){
    if(c == 'P') return 'S';
    if(c == 'R') return 'P';
    return 'R';
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        string A; cin >> A;
        int points = 0;
        string ans;
        for(int i = 0; i < min(n, n - n / 2 - 1 + points); ++i) ans += 'P', points += 'P' == vence(A[i]);
        for(int i = n - n / 2 - 1 + points; i < n; ++i) ans += vence(A[i]);
        cout << ans << '\n';
    }
}
