/**
* Author: Jorge Raul Tzab Lopez
* Github: https://github.com/SJMA11723
*/

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<pii> vpii;
typedef vector<pll> vpll;

#define all(x) (x).begin(), (x).end()
#define fi first
#define se second
#define pb push_back
#define sz(x) (int)(x).size()
#define MAXN 1000000

const ll MOD = 1e9 + 7;
int phi[MAXN + 1];
ll dp[MAXN + 1];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    for(int i = 1; i <= MAXN; ++i) phi[i] = i;
    for(int i = 2; i <= MAXN; ++i){
        if(phi[i] == i) for(int j = i; j <= MAXN; j += i) phi[j] -= phi[j] / i;
    }
    for(int i = 1; i <= MAXN; ++i){
        for(int j = i; j <= MAXN; j += i) dp[j] += 1ll * i * phi[i];
    }

    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        cout << (dp[n] / 2 + 1) * n << '\n';
    }
}