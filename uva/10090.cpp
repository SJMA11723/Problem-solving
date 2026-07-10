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
    ll x1, y1;
    int g = gcd_ext(b, a % b, x1, y1);
    x = y1;
    y = x1 - y1 * (a / b);
    return g;
}

bool encuentra_solucion(int a, int b, int c, ll &x, ll &y, ll &g){
    g = gcd_ext(abs(a), abs(b), x, y);
    if(c % g) return false;
    x *= c / g;
    y *= c / g;
    if(a < 0) x = -x;
    if(b < 0) y = -y;
    return true;
}

void cambia_solucion(ll &x, ll &y, int a, int b, ll cnt, ll g = 1){
    x += cnt * b / g;
    y -= cnt * a / g;
}

ll mfloor(ll a, ll b){
    if(b < 0) a = -a, b = -b;
    return a < 0 ? (a - b + 1) / b : a / b;
}

ll mceil(ll a, ll b){
    if(b < 0) a = -a, b = -b;
    return a < 0 ? a / b : (a + b - 1) / b;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    while(cin >> n){
        if(n == 0) break;
        ll c1, n1; cin >> c1 >> n1;
        ll c2, n2; cin >> c2 >> n2;
        // n1x + n2y = n
        // min{c1x + c2y}
        ll x, y, g;
        if(!encuentra_solucion(n1, n2, n, x, y, g)){
            cout << "failed\n";
            continue;
        }

        n1 /= g;
        n2 /= g;
        n /= g;
        ll mink = mceil(-x, n2);
        ll maxk = mfloor(y, n1);
        if(mink > maxk){
            cout << "failed\n";
            continue;
        }

        if(0 < c1 * n2 - c2 * n1) cambia_solucion(x, y, n1, n2, mink);
        else cambia_solucion(x, y, n1, n2, maxk);
        cout << x << ' ' << y << '\n';
    }
}
