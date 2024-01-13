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
        vector<int> type_3;
        int l = 0, r = INT_MAX;
        for(int i = 0; i < n; ++i){
            int a, x; cin >> a >> x;
            if(a == 1) l = max(l, x);
            else if(a == 2) r = min(r, x);
            else type_3.push_back(x);
        }

        int ans = r - l + 1;
        for(int x : type_3) if(l <= x && x <= r) ans--;
        cout << max(ans, 0) << '\n';
    }
}
