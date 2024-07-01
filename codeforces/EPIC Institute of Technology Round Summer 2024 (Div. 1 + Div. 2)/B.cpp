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
        int ant = 0;
        vector<int> add;
        for(int i = 0; i < n; ++i){
            int x; cin >> x;
            if(ant <= x) ant = x;
            else add.push_back(ant - x);
        }
        sort(add.begin(), add.end());

        int64_t ans = 0;

        if(add.size()){
            ans += 1ll*(add[0]) * (add.size() + 1);
            for(int i = 1; i < add.size(); ++i) ans += 1ll*(add[i] - add[i - 1]) * (add.size() - i + 1);
        }

        cout << ans << '\n';
    }
}
