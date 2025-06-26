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


#define MAXN 200000
#define DEBUG if(deb)

bool deb = true;
int bucket[MAXN];
const int MOD = 998244353;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin>>n;

    int arr[n];

    for(int x = 0; x < n; x++) cin>>arr[x];
    if(n == 1){
        cout<<"1\n";
        return 0;
    }

    int dp[n];
    dp[n-1] = 1;
    bucket[arr[n-1]]+=dp[n-1];

    for(int i = n-1; i > 0; i--){
        
        dp[i] = bucket[arr[i]];
        dp[i] %= MOD;
        bucket[arr[i-1]]+=dp[i];
         bucket[arr[i-1]]%=MOD;
    }

    cout<<bucket[arr[0]]<<"\n";

    
}