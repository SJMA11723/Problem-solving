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
typedef vector<vi> vvi;
typedef vector<vll> vvll;
typedef vector<pii> vpii;
typedef vector<pll> vpll;

//7typedef tree<int, null_type, less<int>, rb_tree_tag, +

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);


    int n;
    cin>>n;

    vector<bool> isthere(n, false);

    for(int i = 0; i < n; i++){
        int t;
        cin>>t;
        t--;
        isthere[t]= true;
    }
    int ans = 0;
    for(int i = 0; i < n; i++) if(!isthere[i]) ans++;

    cout<<ans<<"\n";
}