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
        int a, b, l; cin >> a >> b >> l;
        set<int> ans;
        for(int i = 1; i <= l; i *= a)
            for(int j = 1; i * j <= l; j *= b)
                if(l % (i * j) == 0) ans.insert(l / (i * j));

        cout << ans.size() << '\n';
    }
}
