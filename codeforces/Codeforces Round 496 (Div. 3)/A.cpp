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
    vector<int> a(n);
    for(int &x : a) cin >> x;
    a.push_back(1);

    vector<int> ans;
    for(int i = 1; i <= n; ++i)
        if(a[i] == 1) ans.push_back(a[i - 1]);

    cout << ans.size() << '\n';
    for(int i = 0; i < ans.size(); ++i) cout << ans[i] << " \n"[i + 1 == ans.size()];
}
