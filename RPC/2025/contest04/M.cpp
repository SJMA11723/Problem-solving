#include <bits/stdc++.h>
#define DEBUG if (deb)
#define pb push_back
#define no cout << "NO\n"
#define yes cout << "YES\n"
#define MAXC 28
#define MAXN 300000

using namespace std;
typedef long long ll;

bool deb = true;
string s;

bool func(ll* arr, int n, ll k, ll val){
    ll cnt = 0;
    for(int x = 0; x < n; x++){
        cnt+=arr[x]/val + (arr[x]%val != 0);
    }
    return cnt <= k;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
   
    ll n,k;
    cin>>n>>k;
    ll arr[n];
    ll s = 0;
    for(int x = 0; x < n; x++) {
        cin>>arr[x];
        s+=arr[x];
    }

    ll ini = 1, fin = s;
    ll ans = 0;
    while(ini <= fin){
      ll mit = (ini+fin)/2;
      if(func(arr, n, k, mit)){
        fin = mit-1;
        ans = mit;
      }  
      else{
        ini = mit+1;
      }
    }

    cout<<ans<<"\n";
}