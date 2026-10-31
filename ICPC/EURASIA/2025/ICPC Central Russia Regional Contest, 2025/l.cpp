#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<vi> vvi;
typedef vector<vll> vvll;

#define fi first
#define se second
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
#define rep(i, a, b) for(int i = (a); i < (b); ++i)

const int MOD = 1e9 + 7;

#define MAXN 1000000000000000000

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll n; cin >> n;
    if(n == 1) cout << "YES\n2 3\n";
    else if(n < MAXN) cout << "YES\n" << (n ^ 1) << " 1\n";
    else cout << "YES\n" << (n ^ (n & (-n))) << ' ' << (n & (-n)) << '\n';
}