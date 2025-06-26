// Source: https://usaco.guide/general/io

#include <bits/stdc++.h>
#include <cstddef>
#include <ios>
using namespace std;


pair<int, int> restore(int sz, int msk, string s){
    string tmp = "";

    bool nonz = false;
    int nmask = 0;
    for(int i = 0; i < sz; i++){
        if(msk & (1 << i)) {
            tmp.push_back(s[i]);
            if(s[i] != '0' && !nonz) {
                nonz = true;
                nmask^=(1 << i);
            }
            else if(nonz){
                nmask^=(1 << i);
            }
        }
    }

    return {stoi(tmp), nmask};

}

bool prime(long long n){
    if( n == 0 || n == 1) return false;

    int i = 2;
    while(i*i <= n){
        if(n%i == 0) return false;
        i++;
    }

    return true;


}
int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(0);
	string s;

    cin>>s;

    int sz = s.length();

    int maxmsk = 1<<(sz);
    int dp[maxmsk];

    dp[0] = 0;

    for(int msk = 1 ; msk < maxmsk; msk++){

        auto [num,nmask] = restore(sz, msk, s);

        if(nmask != msk) {
            dp[msk] = dp[nmask];
            continue;
        }
        
        if(!prime(num)) {
            dp[msk] = 0;
            continue;
        }
        int maxi = 0;
        for(int i = 0; i < sz; i++){
            if(msk & (1 << i)) {
                maxi = max(maxi, dp[msk^(1 << i)]);
            }
        }
        dp[msk] = 1 + maxi;
    }

    cout<<dp[maxmsk-1]<<"\n";
}
