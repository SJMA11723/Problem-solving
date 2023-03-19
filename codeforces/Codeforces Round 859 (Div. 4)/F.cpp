/**
* Author: Jorge Raul Tzab Lopez
* Github: https://github.com/SJMA11723
*/

#include <bits/stdc++.h>

using namespace std;

void update(int &i, int &j, string &d, int n, int m){
    if(d[0] == 'U'){
        if(i == 1){
            i++;
            d[0] = 'D';
        } else i--;
    } else {
        if(i == n){
            i--;
            d[0] = 'U';
        } else i++;
    }

    if(d[1] == 'L'){
        if(j == 1){
            j++;
            d[1] = 'R';
        } else j--;
    } else {
        if(j == m){
            j--;
            d[1] = 'L';
        } else j++;
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t; cin >> t;
    while(t--){
        string d;
        int n, m, i, j, i2, j2;
        cin >> n >> m >> i >> j >> i2 >> j2 >> d;
        map<pair<string, pair<int, int>>, bool> visitado;
        int ans = 0, repetido = 0;
        while(i != i2 || j != j2){
            visitado[{d, {i, j}}] = true;
            string d_ant = d;
            update(i, j, d, n, m);
            if(d != d_ant) ans++;
            if(visitado[{d, {i, j}}]) break;
        }

        if(i == i2 && j == j2) cout << ans << '\n';
        else cout << "-1\n";
    }
}
