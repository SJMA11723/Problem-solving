/**
* Author: Jorge Raul Tzab Lopez
* Github: https://github.com/SJMA11723
*/

#include <bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define pb push_back
#define fi first
#define se second

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        string s; cin >> s;
        int cnt_mid = 0, cnt_others = 0;
        for(char c : s){
            if(c == '_') cnt_mid++;
            else cnt_others++;
        }
        cout << 1ll * cnt_mid * (cnt_others / 2) * (cnt_others - cnt_others / 2) << '\n';
    }
}
