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
        int a, b, c;
        cin >> a >> b >> c;
        if(b + c / 2 >= a + c - c / 2) cout << "Second\n";
        else cout << "First\n";
    }
}