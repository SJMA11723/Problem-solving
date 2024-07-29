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
    int maxi = 0;
    stack<int> sizes;
    bool ok = true;
    for(int i = 0; i < n; ++i){
        int x; cin >> x;
        maxi = max(maxi, x);

        if(sizes.empty() || sizes.top() != x){
            if(sizes.size()) ok = ok && sizes.top() > x;
            sizes.push(x);
        } else sizes.pop();
    }

    cout << (ok && (sizes.empty() || (sizes.size() == 1 && sizes.top() == maxi)) ? "YES\n" : "NO\n");
}
