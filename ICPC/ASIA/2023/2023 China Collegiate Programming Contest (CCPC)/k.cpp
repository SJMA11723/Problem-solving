#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<vi> vvi;
typedef vector<vll> vvll;
#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
#define pb push_back
#define rep(i, a, b) for(int i = (a); i < (b); ++i)
#define repr(i, a, b) for(int i = (b) - 1; a <= i; --i)
const int MOD = 1e9 + 7;

#define is_on(S, i) ((S) & (1 << (i)))

map<vi, int> perm_to_int;
map<int, vi> int_to_perm;

vi comp(vi &A, vi &B){
    vi C(sz(A));
    for(int i = 0; i < sz(C); ++i) C[i] = A[B[i]];
    return C;
}

set<vi> brute(int n, vvi &A){
    int m = sz(A);
    int lim = 1 << m;
    set<vi> all;
    for(int mask = 1; mask < lim; ++mask){
        vi cur; cur.resize(n); iota(all(cur), 0);
        rep(i, 0, m) if(is_on(mask, i)) cur = comp(cur, A[i]);
        all.insert(cur);
    }
    return all;
}


vector<int> invert(vi& p){
    int n = p.size();
    vi ans(n, 0);
    for(int i = 0; i < n; i++){
        ans[p[i]] = i;
    }
    return ans;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m; cin >> n >> m;
    vvi A(m, vi(n));
    rep(i, 0, m) for(int &pi : A[i]){
        cin >> pi;
        pi--;
    }

    if(m <= 13) cout << sz(brute(n, A)) << '\n';
    else if(m <= 25){
        vvi A1, A2;
        for(int i = 0; i < m / 2; ++i) A1.pb(A[i]);
        for(int i = m / 2; i < m; ++i) A2.pb(A[i]);
        set<vi> L, R;
        L = brute(n, A1);
        R = brute(n, A2);

        set<vi> all;
        for(vi p : L) all.insert(p);
        for(vi p : R) all.insert(p);

        for(vi p1 : L) for(vi p2 : R) all.insert(comp(p1, p2));
        cout << sz(all) << '\n';
    } else {
        // DP Rogelio
        vi perm; perm.resize(n); iota(all(perm), 0);
        do{
            int val = sz(perm_to_int);
            perm_to_int[perm] = val;
            int_to_perm[val] = perm;
        }while(next_permutation(all(perm)));

        // perm_to_int[P] = int
        int k = sz(perm_to_int);
        vector<vector<bool>> dp(k, vector<bool>(m, 0));

        dp[perm_to_int[A[0]]][0] = true;

        for(int i = 1; i < m; i++){
            
            for(int Pxv = 0; Pxv < k; Pxv++ ){
                auto& Px = int_to_perm[Pxv];

                auto Ainv = invert(A[i]);
                int thang = perm_to_int[comp(Px, Ainv)];
                dp[Pxv][i] = dp[Pxv][i-1] || dp[thang][i-1];
            }
            dp[perm_to_int[A[i]]][i] = true;
        }
        long long ans = 0;
        for(int Pxv = 0; Pxv < k; Pxv++){
            if(dp[Pxv][m-1]) ans++;
        }
        cout<<ans<<"\n";
    }
}