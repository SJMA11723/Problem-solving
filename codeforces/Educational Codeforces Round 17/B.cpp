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
    int a, b, c; cin >> a >> b >> c;
    int m; cin >> m;
    pair<int, string> arr[m];
    for(pair<int, string> &p : arr) cin >> p.first >> p.second;
    sort(arr, arr + m);
    int ans = 0;
    int64_t sum = 0;
    for(auto [cost, s] : arr){
        if(s == "USB"){
            if(a) a--;
            else if(c) c--;
            else continue;
            ans++;
            sum += cost;
        } else {
            if(b) b--;
            else if(c) c--;
            else continue;
            ans++;
            sum += cost;
        }
    }
    cout << ans << ' ' << sum << '\n';
}
