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

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n; cin >> n;
    stack<int> st;
    int arr[n], L[n], R[n];
    for(int i = 0; i < n; ++i){
        cin >> arr[i];
        while(sz(st) && arr[st.top()] <= arr[i]){
            R[st.top()] = i;
            st.pop();
        }
        st.push(i);
    }
    while(sz(st)){
        R[st.top()] = -1;
        st.pop();
    }

    for(int i = n - 1; 0 <= i; --i){
        while(sz(st) && arr[st.top()] <= arr[i]){
            L[st.top()] = i;
            st.pop();
        }
        st.push(i);
    }
    while(sz(st)){
        L[st.top()] = -1;
        st.pop();
    }


    ll pref[n]; pref[0] = arr[0];
    for(int i = 1; i < n; ++i) pref[i] = pref[i - 1] + arr[i];

    ll ans = 0;
    for(int i = 0; i < n; ++i){
        int l, r;
        if(R[i] != -1 && i + 1 != R[i]){
            l = i + 1;
            r = R[i] - 1;
            ll h = min(arr[l - 1], arr[r + 1]);
            ans = max(ans, h * (r - l + 1) - (pref[r] - pref[l - 1]));
        }
        
        if(L[i] != -1 && L[i] + 1 != i){
            l = L[i] + 1;
            r = i - 1;
            ll h = min(arr[l - 1], arr[r + 1]);
            ans = max(ans, h * (r - l + 1) - (pref[r] - pref[l - 1]));
        }
    }
    cout << ans << '\n';
}