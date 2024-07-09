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
    int p[n];
    for(int i = 1; i < n; ++i) cin >> p[i], p[i]--;

    stack<int> ans;
    int cur = n - 1;
    while(cur){
        ans.push(cur + 1);
        cur = p[cur];
    }
    cout << "1";
    while(ans.size()){
        cout << ' ' << ans.top();
        ans.pop();
    }
    cout << '\n';
}
