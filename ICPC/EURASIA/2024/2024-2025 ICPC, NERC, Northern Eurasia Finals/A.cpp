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
    int arr[n];
    for(int &x : arr) cin >> x;

    vector<int> order(n);
    vpii ans;
    iota(all(order), 1);
    for(int i = n - 1; 0 <= i; --i){
        int pos = -1;
        for(int j = n - 1; 0 <= j; --j){
            if(order[j] == arr[i]){
                pos = j;
                break;
            }
        }
        order.erase(order.begin() + pos);
        order.insert(order.begin(), arr[i]);
        while(0 < pos) ans.pb({arr[i], order[pos--]});
    }

    cout << sz(ans) << '\n';
    for(auto &[a, b] : ans) cout << a << ' ' << b << '\n';
}