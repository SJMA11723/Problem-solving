/**
* Author: Jorge Raul Tzab Lopez
* Github: https://github.com/SJMA11723
*/

#include <bits/stdc++.h>

using namespace std;

void criba(int n, int acc[]){
    if(n < 2) return;

    vector<bool> no_primo(n + 1);
    no_primo[0] = no_primo[1] = true;

    for(long long i = 3; i * i <= n; i += 2){
        if(no_primo[i]) continue;
        for(long long j = i * i; j <= n; j += 2 * i)
            no_primo[j] = true;
    }

    acc[2] = 1;
    for(int i = 3; i <= n; i += 2){
        if(!no_primo[i])
            acc[i] = 1;
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int acc[1000001] = {};
    criba(1000000, acc);

    for(int i = 3; i <= 1000000; ++i) acc[i] += acc[i - 1];

    int t; cin >> t;
    while(t--){
        int i, j;
        cin >> i >> j;
        cout << acc[j] - acc[i - 1] << '\n';
    }
}
