/**
* Author: Jorge Raul Tzab Lopez
* Github: https://github.com/SJMA11723
*/

#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;

    while(t--){
        int n;
        cin >> n;
        int i = n;
        while(i--){
            if(n % 2 && i+1 == (n / 2 + 1)){
                cout << i << ' ' << i + 1 << ' ';
                i--;
            } else cout << i + 1 << ' ';
        }
        cout << '\n';
    }
}
