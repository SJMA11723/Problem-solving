/**
* Author: Jorge Raul Tzab Lopez
* Github: https://github.com/SJMA11723
*/

#include <bits/stdc++.h>

using namespace std;

int sum(int n){
    int res = 0;
    while(n){
        res += n % 10;
        n /= 10;
    }
    return res;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int a; cin >> a;
    int n = a;
    while(sum(n) % 4) n++;
    cout << n << '\n';
}

