/**
* Author: Jorge Raul Tzab Lopez
* Github: https://github.com/SJMA11723
*/

#include <bits/stdc++.h>

using namespace std;

bool beautiful(int x, int k){
    int sum = 0;
    while(x){
        sum += x % 10;
        x /= 10;
    }
    return sum % k == 0;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t; cin >> t;
    while(t--){
        int x, k; cin >> x >> k;
        while(!beautiful(x, k)) x++;
        cout << x << '\n';
    }
}
