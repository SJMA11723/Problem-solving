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
typedef vector<pii> vpii;
typedef vector<pll> vpll;

#define all(x) (x).begin(), (x).end()
#define fi first
#define se second
#define pb push_back
#define sz(x) (int)(x).size()

const ll MOD = 1e9 + 7;

vi operator+(vi &A, vi &B){
    int n = sz(A), m = sz(B);
    reverse(all(A));
    reverse(all(B));
    vi res(max(n, m));
    for(int i = 0; i < max(n, m); ++i){
        if(i < min(n, m)) res[i] += A[i] + B[i];
        else if(i < n) res[i] += A[i];
        else res[i] += B[i];
        
        if(res[i] > 9){
            if(i + 1 >= max(n, m)) res.pb(0);
            res[i + 1] += res[i] / 10;
            res[i] -= 10;
        }
    }

    reverse(all(A));
    reverse(all(B));
    reverse(all(res));
    return res;
}

vi operator+(vi &A, int B){
    vi vecB;
    while(B){
        vecB.pb(B % 10);
        B /= 10;
    }
    reverse(all(vecB));
    return A + vecB;
}

vi operator+(int A, vi &B){return B + A;}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        ll arr[n] = {}, pref_pond[n] = {};
        for(ll &x : arr){
            char c; cin >> c;
            x = c - '0';
        }

        pref_pond[0] = arr[0] * n;
        for(int i = 1; i < n; ++i){
            pref_pond[i] = pref_pond[i - 1] + arr[i] * (n - i);
            arr[i] += arr[i - 1];
        }

        vll ans(n);
        ans[0] += pref_pond[n - 1];
        for(int i = 0; i < n; ++i){
            ans[i] += 9 * (pref_pond[n - 1 - i] - i * arr[n - 1 - i]);

            if(ans[i] > 9){
                if(i + 1 >= sz(ans)) ans.pb(0);
                ans[i + 1] += ans[i] / 10;
                ans[i] %= 10;
            }
        }

        for(int i = n - 1; i < sz(ans); ++i){
            if(ans[i] > 9){
                if(i + 1 >= sz(ans)) ans.pb(0);
                ans[i + 1] += ans[i] / 10;
                ans[i] %= 10;
            }
        }

        while(!ans.back()) ans.pop_back();
        reverse(all(ans));
        ans.pop_back();
        for(ll d : ans) cout << d; cout << '\n';
    }
}