/**
* Author: Mathgic
* Github: https://github.com/SJMA11723
*/

#include <bits/stdc++.h>

using namespace std;

bool dp[5001][5001];
bool processed[5001][5001];

bool ganaTurno(int n, int turno){
    if(n == 0) return false;

    if(!processed[n][turno]){
        processed[n][turno] = true;
        bool gana = false;
        for(int i = min(n, turno); 0 < i && !gana; --i){
            gana = gana || !ganaTurno(n - i, turno + 1);
        }
        dp[n][turno] = gana;
    }

    return dp[n][turno];
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n; cin >> n;
    if(ganaTurno(n, 1)) cout << "Jane\n";
    else cout << "John\n";
}
