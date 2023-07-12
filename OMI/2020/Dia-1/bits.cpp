/**
* Author: Jorge Raul Tzab Lopez
* Github: https://github.com/SJMA11723
*/

#include <bits/stdc++.h>
#define MAXN 5001

using namespace std;

typedef long long ll;

const int MOD = 1e9 + 7;

int binom[MAXN][MAXN];

int main(){
    int N, A, B;
    scanf("%d %d %d", &N, &A, &B);

    for(int i = 0; i <= N; ++i){
        binom[i][0] = binom[i][i] = 1;
        for(int j = 1; j <= i; ++j)
            binom[i][j] = (binom[i - 1][j - 1] + binom[i - 1][j]) % MOD;
    }

    int ans = 0;

    if(A > B) swap(A, B);

    if(A == B) ans = (ll)binom[N][A] * (ll)(binom[N][A] - 1) % MOD;
    else {
        for(int i = 1; i <= N; ++i)
            for(int j = 0; j < i && j < A; ++j)
                ans = (ans + (ll)binom[i - 1][j] * (ll)binom[N - i][A - j - 1] % MOD * (ll)binom[N - i][B - j]) % MOD;
    }

    printf("%d\n", ans);
}
