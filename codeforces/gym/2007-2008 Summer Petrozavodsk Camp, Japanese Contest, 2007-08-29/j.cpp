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

int gcd_ext(int a, int b, ll &x, ll &y){
    if(!b){x = 1; y = 0; return a;}
    ll x1, y1; int g = gcd_ext(b, a % b, x1, y1);
    x = y1;
    y = x1 - y1 * (a / b);
    return g;
}

bool encuentra_solucion(int a, int b, int c, ll &x, ll &y, int &g){
    g = gcd_ext(abs(a), abs(b), x, y);
    if(c % g) return false;
    x *= c / g;
    y *= c / g;
    if(a < 0) x = -x;
    if(b < 0) y = -y;
    return true;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m, a, k;
    while(cin >> n >> m >> a >> k){
        if(n == m && m == a && a == k && k == 0) break;

        ll x, y;
        int g;
        if(!encuentra_solucion(m, -a, k - n, x, y, g)){
            cout << "Impossible\n";
            continue;
        }

        //cout << g << '\n';
        //cout << x << ' ' << y << '\n';

        ll cnt = (-x) / (-a / g);
        x += cnt * (-a / g);
        y -= cnt * (m / g);
        if(x < 0){
            x += -(-a / g);
            y -= -m / g;
        }

        //cout << cnt << '\n';
        //cout << x << ' ' << y << '\n';
        cnt = -(1 - y) / (m / g);
        x += cnt * (-a / g);
        y -= cnt * (m / g);
        if(y < 1){
            x += -(-a / g);
            y -= -m / g;
        }
        //cout << x << ' ' << y << '\n';
        cout << n + m * x << '\n';
    }
}