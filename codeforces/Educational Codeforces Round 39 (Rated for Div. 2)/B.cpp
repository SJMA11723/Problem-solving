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
    long long n, m;
    cin >> n >> m;
    long long a, b;
    while(n && m){
        a = n;
        b = m;
        if(n >= 2 * m) a = n %= 2 * m;
        else if(m >= 2 * n) b = m %= 2 * n;
        else break;
    }
    cout << a << ' ' << b << '\n';
}
