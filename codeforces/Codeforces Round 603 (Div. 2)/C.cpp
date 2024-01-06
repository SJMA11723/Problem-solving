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
        int last = 1;
        vector<int> ans;
        ans.push_back(n);
        while(last <= n){
            int l = last + 1, r = n + 1;
            while(l < r){
                int mid = (l + r) / 2;
                if(n / mid == n / last) l = mid + 1;
                else r = mid;
            }

            ans.push_back(n / l);
            last = l;
        }

        cout << ans.size() << '\n';
        for(int i = ans.size() - 1; 0 <= i; --i) cout << ans[i] << ' ';
        cout << '\n';
    }
}
