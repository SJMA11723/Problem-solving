/**
* Author: Jorge Raul Tzab Lopez
* Github: https://github.com/SJMA11723
*/

#include <bits/stdc++.h>

using namespace std;

void criba(int n, vector<bool> &no_primo){
    if(n < 2) return;

    no_primo[0] = no_primo[1] = true;

    for(long long i = 3; i * i <= n; i += 2){
        if(no_primo[i]) continue;
        for(long long j = i * i; j <= n; j += 2 * i)
            no_primo[j] = true;
    }
    for(int i = 4; i <= n; i += 2) no_primo[i] = true;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n; cin >> n;
    if(n < 3) cout << "1\n";
    else cout << "2\n";

    vector<bool> no_primo(n + 2);
    criba(n + 1, no_primo);

    for(int i = 2; i <= n + 1; ++i)
        cout << (no_primo[i] ? 2 : 1) << ' ';
}
