/**
* Author: Jorge Raul Tzab Lopez
* Github: https://github.com/SJMA11723
*/

#include <bits/stdc++.h>

using namespace std;

long long *dp;
vector< pair<long long, long long> > bolsas;

long long solve(long long kg){
    dp[0] = 0;
    for(long long c = 1; c <= kg; ++c){
        dp[c] = LLONG_MAX;
        for(auto [w, p] : bolsas)
            dp[c] = min(dp[c], (long long)p + dp[max(0ll, c - w)]);
    }
    return dp[kg];
}

int main(){
    int B, n;
    scanf("%d %d", &B, &n);
    long long w, p;
    while(B--){
        scanf("%lld %lld", &w, &p);
        if(w) bolsas.push_back({w, p});
    }

    long double sumA = 0;
    long long kg = 0;
    long double a, b, c, semi_p;
    for(int i = 0; i < n; ++i){
        scanf("%Lf %Lf %Lf", &a, &b, &c);
        semi_p = (a + b + c) / 2;
        sumA += sqrt(semi_p * (semi_p - a) * (semi_p - b) * (semi_p - c));
    }

    if(n) kg = ceil(sumA / 30);

    dp = new long long[kg + 1];

    if(kg > 0 && bolsas.empty()) printf("-1\n");
    else printf("%lld\n", solve(kg));

    delete[] dp;
}
