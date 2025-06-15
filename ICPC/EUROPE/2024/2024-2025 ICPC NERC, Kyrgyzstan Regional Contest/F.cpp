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
#define all(x) (x).begin(), (x).end()
#define pb push_back

const int MOD = 1e9 + 7;

int main(){
    ios_base::sync_with_stdio();
    cin.tie();
    cout.tie();
    ll n; cin >> n;
    ll S, F; cin >> S >> F;
    map<ll, ll> events;
    ll H[n + 1] = {};
    ll prv = 0, active = 0;
    for(int i = 0; i < n; ++i){
        int a, b; cin >> a >> b;
        if(a < S) active++;
        else if(a <= F) events[a]++;
        
        if(b < S) active--;
        else if(b <= F) events[b]--;
    }
    if(events.count(F) == 0) events[F] = 0;

    for(auto &e : events){
        H[active] += max(0ll, min(e.fi, F) - max(S, prv));
        active += e.se;
        prv = e.fi;
    }

    ll sum = H[0];
    for(int i = 1; i <= n; ++i) cout << sum << " \n"[i == n], sum += H[i];
}