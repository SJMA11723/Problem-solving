/**
* Author: Jorge Raul Tzab Lopez
* Github: https://github.com/SJMA11723
*/

#include <bits/stdc++.h>
#define MAXN 50
#define MAXT 501

using namespace std;

double dp[MAXN][MAXT][MAXT];
bool processed[MAXN][MAXT][MAXT];
int arr[MAXN], sum, n, a, b, c;

double compute(int i, int T1, int T2){
    if(i >= n) return max({(double)T1 / a, (double)T2 / b, (double)(sum - T1 - T2) / c});
    if(processed[i][T1][T2]) return dp[i][T1][T2];
    processed[i][T1][T2] = true;
    return dp[i][T1][T2] = min({compute(i + 1, T1, T2),
                               compute(i + 1, T1 + arr[i], T2),
                               compute(i + 1, T1, T2 + arr[i])});
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> a >> b >> c;
    for(int i = 0; i < n; ++i){
        cin >> arr[i];
        sum += arr[i];
    }
    cout << ceil(compute(0, 0, 0)) << '\n';
}
