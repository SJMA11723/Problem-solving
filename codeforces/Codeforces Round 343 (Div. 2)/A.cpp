/**
* Author: Jorge Raul Tzab Lopez
* Github: https://github.com/SJMA11723
*/

#include <bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define pb push_back
#define ff first
#define ss second

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n; cin >> n;
    int ans = 0;
    int cnt_col[n] = {};
    for(int i = 0; i < n; ++i){
        int cnt = 0;
        for(int j = 0; j < n; ++j){
            char c; cin >> c;
            if(c == 'C') ans += cnt_col[j]++ + cnt++;
        }
    }
    cout << ans << '\n';
}
