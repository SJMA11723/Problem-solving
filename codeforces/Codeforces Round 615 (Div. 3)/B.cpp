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
        pair<int, int> arr[n];
        for(pair<int, int> &p : arr) cin >> p.second >> p.first;
        sort(arr, arr + n);
        int x = 0, y = 0;
        string ans;
        for(auto [yy, xx] : arr){
            if(xx < x){
                ans = "NO";
                break;
            }

            while(x < xx){
                ans += 'R';
                x++;
            }

            while(y < yy){
                ans += 'U';
                y++;
            }
        }

        if(ans == "NO") cout << "NO\n";
        else cout << "YES\n" << ans << '\n';
    }
}
