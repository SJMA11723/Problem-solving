#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef int64_t ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<pii> vpii;
typedef vector<pll> vpll;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define sz(x) (int)(x).size()

const int MOD = 1e9 + 7;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n,k;
    cin>>n>>k;


    int arr1[n], arr2[n];

    for(int x = 0; x < n; x++) cin>>arr1[x];
    for(int x = 0; x < n; x++) cin>>arr2[x];

    sort(arr1, arr1+n);
    sort(arr2, arr2+n);
    int ans = 0;
    for(int i = 0; i < n; i++){
        int c = arr1[i]+arr2[i];

        if(k-c>= 0) {
            k-=c;
            ans++;
        }
        else break;
    }
    cout<<ans<<"\n";
}