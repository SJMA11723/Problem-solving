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
#define sz(x) (x).size()
#define all(x) (x).first(), (x).end()
#define pb push_back
#define DEBUG if(deb)


bool deb = true;
const int MOD = 1e9 + 7;

int main(){
    if(!deb) ios_base::sync_with_stdio(0);
    if(!deb) cin.tie(0);
    if(!deb) cout.tie(0);

    int n,  b;
    cin>>n>>b;

    int arr[n-1];
    for(int i = 0; i < n-1; i++) cin>>arr[i];
    int pos = 0;
    bool allneg = true;
    int mini = 1000000000;
    for(auto x: arr){
        if(x >= 0) {
            pos+=x;
            allneg = false;
        }
        else{
            mini = min(mini, abs(x));
        }   
    }

    if(allneg){
        if(b>= mini) cout<<(b-mini);
        else cout<<"-1";
    }
    else{
        cout<<(b+pos);
    }

    cout<<"\n";


}