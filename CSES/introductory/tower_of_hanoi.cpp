/**
* Author: Jorge Raul Tzab Lopez
* Github: https://github.com/SJMA11723
*/

#include <bits/stdc++.h>

using namespace std;

void solve(int n, int from = 1, int aux = 2, int to = 3){
    if(!n) return;
    solve(n - 1, from, to, aux);
    cout << from << ' ' << to << '\n';
    solve(n - 1, aux, from, to);
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n; cin >> n;
    cout << (1 << n) - 1 << '\n';
    solve(n);
}
