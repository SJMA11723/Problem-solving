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
    int arr[n];
    for(int &x : arr) cin >> x;

    bool ap[1001] = {};
    vector<int> ans;
    for(int i = n - 1; 0 <= i; --i){
        if(ap[arr[i]]) continue;
        ap[arr[i]] = true;
        ans.push_back(arr[i]);
    }
    reverse(ans.begin(), ans.end());

    cout << ans.size() << '\n';
    for(int i = 0; i < ans.size(); ++i) cout << ans[i] << " \n"[i + 1 == ans.size()];
}
