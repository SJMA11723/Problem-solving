#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<pii> vpii;
typedef vector<pll> vpll;

#define fi first
#define se second
#define all(x) ((x).begin(), (x).end())
#define pb(x) push_back(x)

const int MOD = 1e9 + 7;

int main(){
    ios_base::sync_with_stdio();
    cin.tie();
    cout.tie();
    int n; cin >> n;
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    cout << (c - a) * (n + 1) + d - b << '\n';
}