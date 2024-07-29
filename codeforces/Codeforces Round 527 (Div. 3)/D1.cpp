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
    int cnt = 0, prv = -1;
    stack<bool> sizes;
    for(int i = 0; i < n; ++i){
        int x; cin >> x;
        x %= 2;

        if(sizes.empty() || sizes.top() != x) sizes.push(x);
        else sizes.pop();
    }

    cout << (sizes.size() <= 1 ? "YES\n" : "NO\n");
}
