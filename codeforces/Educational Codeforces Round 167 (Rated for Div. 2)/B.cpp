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
        string a, b; cin >> a >> b;
        int ans = a.size() + b.size();

        int maxi = 0;
        for(int i = 0; i < b.size(); ++i){
            int idx = i, cnt = 0;
            for(int j = 0; j < a.size() && idx < b.size(); ++j){
                if(a[j] == b[idx]){
                    idx++;
                    cnt++;
                }
            }
            maxi = max(maxi, cnt);
        }
        ans -= maxi;

        cout << ans << '\n';
    }
}
