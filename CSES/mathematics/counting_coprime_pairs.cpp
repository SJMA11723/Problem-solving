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
#define pb push_back
#define sz(x) (int)(x).size()
#define MAXVAL 1000000

const ll MOD = 1e9 + 7;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n; cin >> n;
    int arr[n], cnt[MAXVAL + 1] = {};
    for(int &x : arr){
        cin >> x;
        cnt[x]++;
    }

    ll pairs[MAXVAL + 1] = {};
    for(int i = 1; i <= MAXVAL; ++i){
        for(int j = i; j <= MAXVAL; j += i){
            pairs[i] += cnt[j];
        }
        pairs[i] = pairs[i] * (pairs[i] - 1) / 2;
    }

    for(int i = MAXVAL - 1; 0 < i; --i){
        for(int j = 2 * i; j <= MAXVAL; j += i){
            pairs[i] -= pairs[j];
        }
    }
    cout << pairs[1] << '\n';
}