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
    int n, k; cin >> n >> k;
    set<pair<int, int>> used;
    vector<pair<int, int>> ans;
    int b = 1, g = 1;
    while(ans.size() < n){
        while(g <= k && (b == g || used.count({b, g}))){
            g++;
            if(g == k + 1){
                b++;
                g = 1;
            }
        }
        if(b > k) break;

        used.insert({b, g});
        used.insert({g, b});
        ans.push_back({b, g});
        ans.push_back({g, b});
    }
    if(ans.size() > n) ans.pop_back();

    if(ans.size() == n){
        cout << "YES\n";
        for(auto [b, g] : ans) cout << b << ' ' << g << '\n';
    } else cout << "NO\n";
}
