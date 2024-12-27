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
        int cnt_odd = 0;
        for(int i = 0; i < n; ++i){
            int x; cin >> x;
            if(x % 2) cnt_odd++;
        }
        if(cnt_odd % 2 == 0 && cnt_odd && cnt_odd < n) cnt_odd--;
        if(cnt_odd % 2) cout << "YES\n";
        else cout << "NO\n";
    }
}
