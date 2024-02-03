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
        int a, b, c;
        cin >> a >> b;
        for(int i = 2; i < n; ++i) cin >> c;
        if(a + b > c) cout << "-1\n";
        else cout << "1 2 " << n << '\n';
    }
}
