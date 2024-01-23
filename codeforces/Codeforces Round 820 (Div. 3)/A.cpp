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
        if(a < c + abs(c - b)) cout << "1\n";
        else if(a > c + abs(c - b)) cout << "2\n";
        else cout << "3\n";
    }
}
