#/**
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

const ll MOD = 1e9 + 7;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n; cin >> n;
    int arr[n], maxi = 0, val_maxi = -1;
    map<int, int> cnt;
    for(int &x : arr){
        cin >> x;
        cnt[x]++;
        if(maxi < cnt[x]){
            maxi = cnt[x];
            val_maxi = x;
        }
    }

    sort(arr, arr + n);
    int pos = maxi % n;
    int ans = 0;
    for(int i = 0; i < n; ++i){
        if(arr[i] < arr[pos]) ans++;
        pos++;
        if(pos == n) pos = 0;
    }
    cout << ans << '\n';
}