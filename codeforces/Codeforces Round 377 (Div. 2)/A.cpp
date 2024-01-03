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
    int k, r; cin >> k >> r;
    for(int i = 0; i < 10; ++i){
        if(k % 10 == (r + (10 - k % 10) * i) % 10 || k % 10 == (10 - k % 10) * i % 10){
            cout << i + 1 << '\n';
            break;
        }
    }
}
