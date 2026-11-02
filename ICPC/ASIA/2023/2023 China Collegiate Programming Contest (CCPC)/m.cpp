#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<vi> vvi;
typedef vector<vll> vvll;
#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
#define pb push_back
#define rep(i, a, b) for(int i = (a); i < (b); ++i)
#define repr(i, a, b) for(int i = (b) - 1; a <= i; --i)
const int MOD = 1e9 + 7;


bool validate(pair<int,int>* arr, int n, int mit){
    int half = n/2 +1;
    bool a[n], b[n];
    int narr[n];
    int cnt = 0;
    for(int i = 0; i < n; i++){
        a[i] = arr[i].fi >= mit;
        b[i] = arr[i].se >= mit;

        if(a[i] == b[i]) {
            if(a[i]) cnt++;
            narr[i] = 0;
        }
        else if(a[i] && !b[i]){
            cnt++;
            narr[i] = -1;
        }
        else {
            narr[i] = 1;
        }
        //printf("%d ", narr[i]);
    }

    //printf("\n");
    
    ll max_sum = 0, sum = 0;
    rep(i, 0, n){
        sum = max(1ll*narr[i], sum + narr[i]);
        max_sum = max(max_sum, sum);
    }
    //printf("cnt %d, maxsum %d\n", cnt, max_sum);
    return cnt+max_sum >= half;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin>>n;

    pair<int,int> arr[n];
    int mini= 1e9+10, maxi = 0;
    for(int i = 0; i < n; i++){
        int a,b;
        cin>>a>>b;

        mini = min(min(a,b), mini);
        maxi = max(max(a,b), maxi);
        arr[i] = {a,b};
    }
    //printf("hey\n");
    int ini = mini, fin = maxi;
    int ans = 0;
    while(ini <= fin){
        
        int mit = (ini+fin)/2;
        //printf("ouch %d\n", mit);
        if(validate(arr,n, mit)){
            //printf("yes\n");
            ans = mit;
            ini = mit+1;
        }
        else{
            //printf("no\n");
            fin = mit-1;
        }
    }

    cout<<ans<<"\n";


}