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
        string ans;
        ans.resize(n);
        int no_div;
        for(int i = 2; i <= n + 1; ++i)
        if(n % i){
            no_div = i;
            break;
        }

        char c = 'a';
        for(int i = 0; i < no_div; ++i, ++c)
            for(int j = i; j < n; j += no_div) ans[j] = c;
        cout << ans << '\n';
    }
}
