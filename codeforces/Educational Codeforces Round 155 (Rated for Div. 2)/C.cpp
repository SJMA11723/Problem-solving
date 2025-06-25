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
#define pb push_back
#define sz(x) (int)(x).size()
#define MAXN 200000

const ll MOD = 998244353;
int fact[MAXN + 1];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    fact[0] = 1;
    for(int i = 1; i <= MAXN; ++i) fact[i] = 1ll * i * fact[i - 1] % MOD;

    int t; cin >> t;
    while(t--){
        string s; cin >> s;
        if(s.back() == '1') s += "0";
        else s += "1";
        int min_ops = 0, cnt_seq = 1, cnt = 0;
        char prv = s[0], change = 0;
        for(char c : s){
            if(c == prv) cnt++;
            else {
                min_ops += cnt - 1;
                cnt_seq = 1ll * cnt_seq * cnt % MOD;
                cnt = 1;
                change++;
            }
            prv = c;
        }
        cnt_seq = 1ll * cnt_seq * fact[min_ops] % MOD;
        cout << min_ops << ' ' << cnt_seq << '\n';
    }
}