/**
* Author: Jorge Raul Tzab Lopez
* Github: https://github.com/SJMA11723
*/

#include <bits/stdc++.h>
#define MAXN 300000

using namespace std;

int n;
int arr[MAXN];
int dp[MAXN][3];
int p[4] = {0, 1, 2, -1};

bool anterior(int x, int h){
    for(int i = 0; i < h; ++i)
        if(x == p[i]) return true;
    return false;
}

int compute(int pos, int h){
    if(pos == n || h == 3) return 0;

    if(dp[pos][h]) return dp[pos][h];

    if(anterior(arr[pos], h)) dp[pos][h] = compute(pos + 1, h);
    else if(arr[pos] == p[h]) dp[pos][h] = 1 + compute(pos + 1, h);
    else if(arr[pos] == p[h + 1]) dp[pos][h] = max(compute(pos + 1, h), 1 + compute(pos + 1, h + 1));
    else dp[pos][h] = max(compute(pos + 1, h), compute(pos + 1, h + 1));

    return dp[pos][h];
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for(int i = 0; i < n; ++i) cin >> arr[i];
    int ans = 0;
    do{
        memset(dp, 0, sizeof(dp));
        int a;
        ans = max(ans, a = compute(0, 0));
        //for(int i = 0; i < 3; ++i) cout << p[i] << ' ';
        //cout << " | " << ans << ' ' << a << '\n';
    }while(next_permutation(p, p + 3));
    cout << ans << '\n';
}
