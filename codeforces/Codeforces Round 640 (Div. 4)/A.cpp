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
        int n, pot = 1; cin >> n;
        vector<int> ans;
        while(n){
            if(n % 10) ans.push_back(n % 10 * pot);
            n /= 10;
            pot *= 10;
        }
        cout << ans.size() << '\n';
        for(int it : ans) cout << it << ' ';
        cout << '\n';
    }
}
