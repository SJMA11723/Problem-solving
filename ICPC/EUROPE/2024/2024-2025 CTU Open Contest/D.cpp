#include <bits/stdc++.h>

using namespace std;

typedef int64_t ll;
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
#define sz(x) (int)(x).size()

const int MOD = 1e9 +7;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n; cin >> n;
    set<pair<pii, int>> xsort, ysort;
    for(int i = 0; i < n; ++i){
        int x, y; cin >> x >> y;
        xsort.insert({{x, y}, i});
        ysort.insert({{y, x}, i});
    }

    int P = n / 4;
    for(int i = 1; i < P; ++i){
        pii p1, p2;
        int id1, id2;
        tie(p1, id1) = *xsort.begin();
        tie(p2, id2) = *xsort.rbegin();
        xsort.erase(xsort.begin());
        xsort.erase(*xsort.rbegin());
        ysort.erase({{p1.se, p1.fi}, id1});
        ysort.erase({{p2.se, p2.fi}, id2});

        tie(p1, id1) = *ysort.begin();
        tie(p2, id2) = *ysort.rbegin();
        ysort.erase(ysort.begin());
        ysort.erase(*ysort.rbegin());
        xsort.erase({{p1.se, p1.fi}, id1});
        xsort.erase({{p2.se, p2.fi}, id2});
    }

    pii p1, p2, p3;
    auto it = xsort.begin();
    p1 = it->fi;
    it++;
    p2 = it->fi;
    it++;
    p3 = it->fi;

    ll dx1 = p1.fi - p2.fi;
    ll dy1 = p1.se - p2.se;
    ll dx2 = p1.fi - p3.fi;
    ll dy2 = p1.se - p3.se;
    dx1 *= dx1;
    dy1 *= dy1;
    dx2 *= dx2;
    dy2 *= dy2;

    ll ans = sqrt((dx1 + dy1) * (dx2 + dy2));
    cout << ans << '\n';
}