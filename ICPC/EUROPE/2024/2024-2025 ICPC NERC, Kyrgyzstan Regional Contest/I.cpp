#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<pii> vpii;
typedef vector<pll> vpll;

#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
#define pb push_back

const int MOD = 1e9 + 7;

bool check(vi &arr, ll K){
    ll sum = 0, maxi = 0;
    for(int i = 0; i < arr.size(); ++i){
        ll x = K - arr[i];
        maxi = max(maxi, x);
        sum += x;
    }
    return (sum % 2 == 0) && sum >= 2 * maxi;
}

int main(){
    ios_base::sync_with_stdio();
    cin.tie();
    cout.tie();

    int n,d, maxi=0; cin >> n >> d; 
    vi num(n,0);
    while( d-- ){
        int a,b; cin >> a >> b;
        a--, b--,
        num[a]++;
        num[b]++;
        maxi = max(maxi, num[a]);
        maxi = max(maxi, num[b]);
    }

    if(n & 1){
        int l = maxi - maxi / 2, r = 1e6 + 1;
        bool odd = check(num, r);
        while(l < r){
            int mid = l + (r - l) / 2;
            if(check(num, 2ll * mid + odd)) r = mid;
            else l = mid + 1;
        }
        cout << 2ll * l + odd << '\n';
    } else {
        int l = maxi, r = INT_MAX;
        while(l < r){
            int mid = l + (r - l) / 2;
            if(check(num, mid)) r = mid;
            else l = mid + 1;
        }
        cout << l << '\n';
    }
}