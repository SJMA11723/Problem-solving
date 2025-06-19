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

struct dsu{
    vi P, RA;

    dsu(int n){
        P.resize(n);
        RA.resize(n, 1);
        iota(all(P), 0);
    }

    int root(int x){
        return x == P[x] ? x : P[x] = root(P[x]);
    }

    void join(int x, int y){
        x = root(x);
        y = root(y);
        if(x == y) return;
        if(RA[x] > RA[y]) swap(x, y);
        RA[y] += RA[x];
        P[x] = y;
    }
};

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t; cin >> t;
    while(t--){
        string a, b, c;
        cin >> a >> b >> c;

        if(a.size() != b.size()){
            cout << "NO\n";
            continue;
        }

        if(a.size() != c.size()){
            cout << "YES\n";
            continue;
        }

        int n = a.size();
        dsu mset(26);
        for(int i = 0; i < n; ++i) mset.join(a[i] - 'a', b[i] - 'a');
        bool ok = false;
        for(int i = 0; i < n; ++i)
            if(mset.root(a[i] - 'a') != mset.root(c[i] - 'a')) ok = true;
        cout << (ok ? "YES\n" : "NO\n");
    }
}