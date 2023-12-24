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
        bool zero = false, neg = false;
        for(int i = 0; i < n; ++i){
            int x; cin >> x;
            if(x < 0) neg = !neg;
            else if(x == 0) zero = true;
        }
        if(zero || neg) cout << "0\n";
        else cout << "1\n1 0\n";
    }
}
