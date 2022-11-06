#include <bits/stdc++.h>

const long long MOD = 1e6 + 7;

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    long long m, C, ant = C = 1;
    cin >> m;

    for(int i = 3; i <= m; ++i){
        C = (C + ant) % MOD;
        ant = (C - ant + MOD) % MOD;
    }

    cout << C << '\n';
    return 0;
}
