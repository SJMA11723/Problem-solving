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

#define MAXN 500000

const ll MOD = 1e8 + 7;
int fibo[MAXN + 1];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    fibo[1] = 1;
    for(int i = 2; i <= MAXN; ++i) fibo[i] = (fibo[i - 1] + fibo[i - 2]) % MOD;
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        cout << fibo[n] << '\n';
    }
}