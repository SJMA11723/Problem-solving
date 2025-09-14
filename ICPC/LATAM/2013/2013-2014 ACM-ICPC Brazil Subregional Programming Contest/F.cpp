// Source: https://usaco.guide/general/io
 
#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <math.h>
#include <map>
#define DEBUG if (deb)
#define INF 2000000000
#define LINF 2000000000000000000
bool deb = true;
using namespace std;
#define pb push_back
typedef long long ll;
 
 
pair<ll,ll> lucky(int l, int r, int k){
    int len = r-l+1;
    if((len) < k) return {0,0};
    int m = (l+r)/2;
 
    if(len %2 == 0){
        auto[freq, sum] = lucky(l,m,k);
        if(freq){
            return {2*freq, (sum)+((ll)m*freq+sum)};
        }
        else{
            return {2*freq, sum};
        }
    }
    else{
        auto[freq, sum] = lucky(l,m-1,k);
        if(freq){
            return {1+2*freq, (sum) + (m) +((ll)m*freq+sum)};
        }
        else{
            return {1+ 2*freq, m + sum};
        }       
    }
}
int main()
{
 
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin>>n;


    int arr[n];
    for(int x = 0; x < n; x++)cin>>arr[x];

    ll preff[n];
    set<int>s;
    preff[0] = arr[0];
    s.insert(preff[0]);
    for(int x = 1; x < n; x++){
        preff[x] = preff[x-1]+arr[x];
        s.insert(preff[x]);
    }

    ll sum = preff[n-1];
    if(sum%3 != 0){
        cout<<"0\n";
        return 0;
    }
    ll side = sum/3;


    
    ll ans = 0;
    for(auto x : preff){
        if(s.count(x+side) && s.count(x+2*side)) ans++;
    } 

    cout<<ans<<"\n";

}   