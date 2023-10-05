#include <bits/stdc++.h>

using namespace std;

long long mat[1001][1001];
int n, m, p;

long long suma(int pi, int pj, int d){
    long long ans = 0;
    for(int i = pi - d, con = 0; i <= pi; ++i, con++){
        ans += mat[i][pj + con] - mat[i][pj - con - 1];
    }

    for(int i = pi + d, con = 0; pi < i; --i, con++){
        ans += mat[i][pj + con] - mat[i][pj - con - 1];
    }

    return ans;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= m; ++j){
            cin >> mat[i][j];
            mat[i][j] += mat[i][j - 1];
        }
    }

    cin >> p;
    while(p--){
        int i, j, d;
        cin >> i >> j >> d;
        i++; j++;
        cout << suma(i, j, d) << '\n';
    }
}
