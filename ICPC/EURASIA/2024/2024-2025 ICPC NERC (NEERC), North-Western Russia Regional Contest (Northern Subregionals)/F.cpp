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
#define sz(x) (int)(x).size()
#define pb push_back

const int MOD = 1e9 + 7;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n; cin >> n;

    int arr[n];
    char c;
    int h,mm;

    for( int i=0; i<n; i++ ){
        cin >> h >> c >> mm;
        arr[i] =h*60+mm;
    }

    for( int i=2; i<n; i++ ){
        if(  arr[i] - arr[i-2] <= 10){
            cout << "0\n";
            return 0;
        }
    }

     for( int i=1; i<n; i++ ){
        if(  arr[i] - arr[i-1] <= 10){
            cout << "1\n";
            return 0;
        }
    }

    cout << "2\n";
    
    
    

}