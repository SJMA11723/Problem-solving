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
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n = 10;

    set<int> s {1,2,3,4};
    for(int x = 0; x < n; x++){
        int t;
        cin>>t;

        s.erase(t);
    }


    int ans = s.size();

    cout<<ans<<"\n";


}