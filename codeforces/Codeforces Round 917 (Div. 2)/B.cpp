/**
* Author: Jorge Raul Tzab Lopez
* Github: https://github.com/SJMA11723
*/

#include <bits/stdc++.h>
#define MAXN 100001

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        string str; cin >> str;
        set<char> distinct;
        long long ans = 0;
        for(int i = 0; i < n; ++i){
            ans += distinct.size();
            distinct.insert(str[i]);
        }
        ans += distinct.size();
        cout << ans << '\n';
    }
}
