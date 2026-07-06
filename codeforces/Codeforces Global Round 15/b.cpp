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

const int MOD = 1e9 + 7;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        int winner = 0;
        vvi arr(n, vi(5));
        for(int &x : arr[0]) cin >> x;
        for(int i = 1; i < n; ++i){
            for(int &x : arr[i]) cin >> x;
            
            int cnt = 0;
            for(int j = 0; j < 5; ++j) cnt += arr[i][j] < arr[winner][j];
            if(cnt >= 3) winner = i;
        }
        bool ok = 1;
        for(int i = 0; i < n; ++i){
            if(i == winner) continue;
            int cnt = 0;
            for(int j = 0; j < 5; ++j) cnt += arr[i][j] < arr[winner][j];
            if(cnt >= 3){
                ok = 0;
                break;
            }
        }

        cout << (ok ? winner + 1 : -1) << '\n';
    }
}