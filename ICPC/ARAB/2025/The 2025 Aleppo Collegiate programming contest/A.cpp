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
        int n; cin >> n;
        if(n == 1){
            cout << "1\n1\n";
            continue;
        } else if(n == 2){
            cout << "2\n1 2\n";
            continue;
        }

        cout << n << '\n';
        ll last = 1;
        for(int i = 2; i <= n; ++i){
            cout << i << ' ';
            last = lcm(last, i);
        }
        cout << last << '\n';
    }
}