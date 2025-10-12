/**
* Author: Mäthgic Crüe
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
    int t; cin >> t;
    while(t--){
        int n, m; cin >> n >> m;
        int ans[n][m], num = 1;
        for(int i = 0; i < n; ++i){
            int ni = i;
            int nj = 0;
            while(0 <= ni && nj < m){
                ans[ni][nj] = num++;
                ni--;
                nj++;
            }
        }

        for(int j = 1; j < m; ++j){
            int ni = n - 1;
            int nj = j;

            while(0 <= ni && nj < m){
                ans[ni][nj] = num++;
                ni--;
                nj++;
            }
        }

        cout << "Yes\n";
        for(int i = 0; i < n; ++i)
        for(int j = 0; j < m; ++j)
        cout << ans[i][j] << " \n"[j + 1 == m];
    }
}
