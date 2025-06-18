#/**
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

#define MAXN 100000

const ll MOD = 1e9 + 7;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int pow2[MAXN + 1];
    pow2[0] = 1;
    for(int i = 1; i <= MAXN; ++i) pow2[i] = 2 * pow2[i - 1], pow2[i] > MOD ? pow2[i] -= MOD : pow2[i];

    int t; cin >> t;
    for(int i = 0; i < t; ++i){
        int x; cin >> x;
    }

    for(int i = 0; i < t; ++i){
        int x; cin >> x;
        cout << pow2[x] << '\n';
    }
}