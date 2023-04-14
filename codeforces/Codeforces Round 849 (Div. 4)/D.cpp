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
        string str; cin >> str;
        set<char> mset;
        int cub[n] = {};
        for(int i = n - 1; 0 <= i; --i){
            mset.insert(str[i]);
            cub[i] = mset.size();
        }
        mset.clear();
        int ans = 0;
        for(int i = 0; i < n - 1; ++i){
            mset.insert(str[i]);
            ans = max(ans, (int)mset.size() + cub[i + 1]);
        }
        cout << ans << '\n';
    }
}
