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
    int n; cin >> n;
    
    if(n == 1){
        ll x; cin >> x;
        if(x == 1) cout << "*\n";
        else cout << x << " 1\n";
        return 0;
    }
    
    ll q; cin >> q;
    ll arr[n];
    arr[0] = q;
    set<ll> mset;
    mset.insert(q);
    for(int i = 1; i < n; ++i){
        ll x; cin >> x;
        arr[i] = x;
        mset.insert(x);
        q = q / __gcd(q, x) * x;
    }

    sort(arr, arr + n);

    if(arr[0] != 1){
        cout << arr[n - 1] << " 1\n";
        return 0;
    }

    for(int i = 0; i < n; ++i){
        if(!mset.count(q / arr[i])){
            cout << q << ' ' << q / arr[i] << '\n';
            return 0;
        }
    }
    ll root = sqrt(q);
    if(root * root == q && !mset.count(root)){
        cout << q << ' ' << root << '\n';
        return 0;
    }

    for(int i = 0; i + 1 < n; ++i){
        ll factor = arr[i + 1] / arr[i];
        ll root = sqrt(factor);
        if(root * root == factor){
            cout << arr[n - 1] << ' ' << arr[i] * root << '\n';
            return 0;
        }
    }
    cout << arr[n - 1] * arr[1] << ' ' << arr[n - 1] * arr[1] << '\n';
}