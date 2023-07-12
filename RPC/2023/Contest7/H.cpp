/**
* Author: Jorge Raul Tzab Lopez
* Github: https://github.com/SJMA11723
*/

#include <bits/stdc++.h>

using namespace std;

int n, s, k, sat[201][201];
int cub[201], dp[201][201*1001];

int check(){
    int con = 0;
    for(int i = 1; i <= s; ++i) if(cub[i] < k) con++;
    return con;
}

int compute(int pos, int suma = 0){
    if(!pos){
        if(!check()) return suma;
        return 0;
    }

    int ans = 0;
    for(int i = 1; i <= s; ++i){
        cub[i]++;
        ans = max(ans, compute(pos - 1, suma + sat[pos][i]));
        cub[i]--;
    }
    return ans;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    //for(int i = 0; i < 201; ++i) for(int j = 0; j < 201*1001; ++j) dp[i][j] = -1;

    cin >> n >> s >> k;
    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= s; ++j){
            cin >> sat[i][j];
        }
    }
    cout << compute(n) << '\n';
}
