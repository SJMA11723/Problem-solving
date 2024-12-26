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
    int n; cin >> n;
    int64_t d[n][n], sum = 0;
    for(int i = 0; i < n; ++i)
    for(int j = 0; j < n; ++j)
    cin >> d[i][j];
    for(int i = 0; i < n; ++i)
    for(int j = i + 1; j < n; ++j)
    sum += d[i][j];

    int k; cin >> k;
    while(k--){
        int a, b, c; cin >> a >> b >> c;
        a--, b--;

        for(int i = 0; i < n; ++i)
        for(int j = i; j < n; ++j){
            if(d[i][j] > d[i][a] + d[b][j] + c){
                sum += d[i][a] + d[b][j] + c - d[i][j];
                d[i][j] = d[j][i] = d[i][a] + d[b][j] + c;
            }

            if(d[i][j] > d[i][b] + d[a][j] + c){
                sum += d[i][b] + d[a][j] + c - d[i][j];
                d[i][j] = d[j][i] = d[i][b] + d[a][j] + c;
            }
        }
        cout << sum << " \n"[!k];
    }
}
