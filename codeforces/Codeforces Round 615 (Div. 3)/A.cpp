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
        int a, b, c, n;
        cin >> a >> b >> c >> n;
        if((a + b + c + n) % 3){
            cout << "NO\n";
            continue;
        }

        int target = (a + b + c + n) / 3;
        if(target < a || target < b || target < c){
            cout << "NO\n";
            continue;
        }

        cout << "YES\n";
    }
}
