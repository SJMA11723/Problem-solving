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
    int n; cin >> n;
    int ans[n], mini = 1, maxi = 1;
    ans[0] = 1;
    set<int> all; all.insert(1);
    for(int i = 0; i < n - 1; ++i){
        int q; cin >> q;
        ans[i + 1] = ans[i] + q;
        mini = min(mini, ans[i + 1]);
        maxi = max(maxi, ans[i + 1]);
        all.insert(ans[i + 1]);
    }
    if(all.size() < n || maxi > n || (mini < 1 && maxi + abs(mini) + 1 > n)){
        cout << "-1\n";
        return 0;
    }

    if(mini < 1) for(int &x : ans) x += abs(mini) + 1;
    for(int i = 0; i < n; ++i) cout << ans[i] << " \n"[i + 1 == n];
}
