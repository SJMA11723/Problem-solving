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
        bool o = false, e = false;
        while(n--){
            int x; cin >> x;
            if(x & 1) o = true;
            else e = true;
        }
        cout << ((o & e) ? "NO\n" : "YES\n");
    }
}
