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
    int q; cin >> q;
    while(q--){
        int n, k; cin >> n >> k;
        int maxi = 0, mini = INT_MAX;
        while(n--){
            int x; cin >> x;
            maxi = max(maxi, x - k);
            mini = min(mini, x + k);
        }
        if(maxi <= mini) cout << mini << '\n';
        else cout << "-1\n";
    }
}
