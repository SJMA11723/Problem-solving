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
typedef vector<pii> vii;
typedef vector<pll> pvll;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define sz(x) (int)(x).size()

const int MOD = 1e9 + 7;


int a[105];


int DP( int l,  int r){
   
    if( l== r )return 1;

    int res = r - l + 1;
    int min_a = 101;
    for( int i=l; i<=r; i++ )
        min_a = min( a[i], min_a );

    //cout << l <<  " " << r  << "  "  <<'\n';

    int ans = 1;
    
    int i=l;
    while( i <=r ){
        if( a[i] ==min_a ){
            i++;
            //continue;
        } 
        else{ 
            int j= i ;
            while( j<=r && a[j] > min_a ) j++;
            ans +=  DP(i,j-1);
            //cout << "   " << DP(i,j-1) << '\n';
            i = j;
        }
    }

    //cout << l <<  " " << r  <<'\n';
    return ans;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n; cin >> n;
    for( int i=0; i<n; i++ ){
        cin >> a[i];
    }

    cout << DP(0,n-1) << '\n';
    
    
}

