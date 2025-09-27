#include<bits/stdc++.h>




using namespace std;


typedef int64_t ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<pii> vpii;


#define fi first  
#define se suseconds_t
#define all(x) (x).begin(), (x).end
#define pb push_back

int main(){
    int n;
    cin>>n;
    vector<int> arr(n+1);
    vector<int> tmp(n+1);

    for(int x = 0; x <= n; x++) {
        cin>>arr[x];
    }

    reverse(arr.begin(), arr.end());

    int msk  = 0;

    for(int x = 0; x <= n; x++){
        if(arr[x])msk |= (1<<x);
    }
    int ans = 0;
    while(msk!= 1){
        if(msk%2 == 0){
            msk/=2;
        }   
        else{
            msk = msk ^ (msk<<1)+1;
        }   
        ans++;
    }
    cout<<ans<<"\n";
 
} 