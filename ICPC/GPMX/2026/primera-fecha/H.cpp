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

const ll MOD = 1e9 + 7;

vvi manacher(const string &s){
    int n = sz(s);
    vvi p = {vi(n + 1), vi(n)};
    for(int z = 0; z < 2; ++z)
    for(int i = 0, l = 0, r = 0; i < n; ++i){
        int t = r - i + !z;
        if(i < r) p[z][i] = min(t, p[z][l + t]);
        int L = i - p[z][i], R = i + p[z][i] - !z;
        while(L >= 1 && R + 1 < n && s[L - 1] == s[R + 1])
            p[z][i]++, L--, R++;
        if(R > r) l = L, r = R;
    }
    return p;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t; cin >> t;
    while(t--){
        string A, B; cin >> A >> B;
        int n = sz(A);

        int cnt_palin_start[n + 1] = {};
        int cnt_palin_finish[n + 1] = {};
        vvi pA, pB;
        pA = manacher(A);
        pB = manacher(B);
        for(int i = 0; i < n; ++i){
            int minr = min(pA[0][i], pB[0][i]);
            cnt_palin_start[i - minr]++;
            cnt_palin_start[i]--;

            cnt_palin_finish[i]++;
            cnt_palin_finish[i + minr]--;

            minr = min(pA[1][i], pB[1][i]);
            cnt_palin_start[i - minr]++;
            cnt_palin_start[i + 1]--;

            cnt_palin_finish[i]++;
            cnt_palin_finish[i + minr + 1]--;
        }
        for(int i = 1; i < n; ++i){
            cnt_palin_start[i] += cnt_palin_start[i - 1];
            cnt_palin_finish[i] += cnt_palin_finish[i - 1];
        }

        ll ans = 0;
        int l = 0, r = n - 1;
        while(l < n && 0 <= r && A[l] == B[r] && A[r] == B[l]){
            ans++;
            if(l + 1 < n) ans += cnt_palin_start[l + 1];
            if(r > 0) ans += cnt_palin_finish[r - 1];
            l++;
            r--;
        }

        cout << ans << '\n';
    }
}
