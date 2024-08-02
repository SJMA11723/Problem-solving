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
    vector<int> even, odd;
    for(int i = 0; i < n; ++i){
        int x; cin >> x;
        if(x % 2) odd.push_back(x);
        else even.push_back(x);
    }

    sort(odd.begin(), odd.end());
    sort(even.begin(), even.end());

    bool e = false;

    if(odd.size() > even.size()) odd.pop_back();
    else even.pop_back(), e = true;

    while(even.size() && odd.size()){
        even.pop_back();
        odd.pop_back();
    }

    if(e && odd.size()) odd.pop_back();
    else if(!e && even.size()) even.pop_back();

    int ans = 0;
    for(int &x : even) ans += x;
    for(int &x : odd) ans += x;
    cout << ans << '\n';
}
