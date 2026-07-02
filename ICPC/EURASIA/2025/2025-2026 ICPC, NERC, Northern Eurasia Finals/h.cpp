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
typedef vector<vi> vvi;
typedef vector<vll> vvll;
typedef vector<pii> vpii;
typedef vector<pll> vpll;

#define all(x) (x).begin(), (x).end()
#define fi first
#define se second
#define pb push_back
#define sz(x) (int)(x).size()

const int MOD = 1e9 + 7;

void collect_divs(int x, vi &divs){
    for(int i = 1; i * i < x; ++i){
        if(x % i) continue;
        divs.pb(i);
        if(i * i != x) divs.pb(x / i);
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int w, h, d; cin >> w >> h >> d;
    int n; cin >> n;
    vi d1, d2, d3;
    collect_divs(w, d1);
    collect_divs(h, d2);
    collect_divs(d, d3);
    
    for(int a : d1)
    for(int b : d2)
    for(int c : d3)
    if(1ll * a * b == n / c && n % c == 0){
        cout << a - 1 << ' ' << b - 1 << ' ' << c - 1 << '\n';
        return 0;
    }
    cout << "-1\n";
}