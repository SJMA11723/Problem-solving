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
        int a, b; cin >> a >> b;
        if(a > b) swap(a, b);

        if(make_pair(a, b) == make_pair(1, 2) || (a % 2 & b % 2)){
            cout << "No\n";
            continue;
        }

        if(a % 2 == 0 || (b % 2 == 0 && b / 2 != a)) cout << "Yes\n";
        else cout << "No\n";
    }
}
