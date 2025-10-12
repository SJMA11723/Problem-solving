/**
* Author: Mäthgic Crüe
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

const ll MOD = 1e9 + 7;

void divisores(ll n){
    for(ll i = 1; i <= n; ++i){
        if(n % i) continue;
        cout << i << ' ';
    }
    cout << '\n';
}

struct pos{
    ll a, b;
    int d;
};

mt19937_64 generator(chrono::steady_clock::now().time_since_epoch().count());
uniform_int_distribution<ll> A(1, 5000);
uniform_int_distribution<ll> B(1, 1e18);

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t; cin >> t;
    while(t--){
        ll a; cin >> a;
        ll b; cin >> b;
        //ll a = A(generator);
        //ll b = B(generator);

        set<pll> vis;
        queue<pos> q;
        q.push({a, b, 0});
        vis.insert({a, b});
        while(sz(q)){
            pos cur = q.front();
            q.pop();

            ll g = gcd(cur.a, cur.b);
            a = cur.a - g;
            b = cur.b;

            if(a == 0){
                cout << cur.d + 2 << '\n';
                break;
            } else if(!vis.count({a, b})){
                q.push({a, b, cur.d + 1});
                vis.insert({a, b});
            }

            a = cur.a;
            b = cur.b - g;
            if(b < a) swap(a, b);

            if(!vis.count({a, b})){
                q.push({a, b, cur.d + 1});
                vis.insert({a, b});
            }
        }
    }
}