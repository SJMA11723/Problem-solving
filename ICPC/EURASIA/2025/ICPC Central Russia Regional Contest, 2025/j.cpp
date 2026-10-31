#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<vi> vvi;
typedef vector<vll> vvll;

#define fi first
#define se second
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
#define rep(i, a, b) for(int i = (a); i < (b); ++i)
#define INF 1e9
const int MOD = 1e9 + 7;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin>>n;

    int arr[n];
    for(int i = 0; i < n; i++) cin>>arr[i];

    int dp[n][n];

    for(int i = 0; i < n; i++){
        dp[i][i] = 1;
        if(i > 0) dp[i][i-1] = 0;
    }

    for(int sz = 2; sz <= n; sz++){
        //printf("kek\n");
        for(int l = 0; l+sz-1 < n; l++){
            int r = l+sz-1;
            //printf("ahdjasjdj %d %d %d\n", l, r, sz);
            dp[l][r] = INF;
            int alpha = 2*!((arr[l] % arr[r] == 0) || (arr[r] % arr[l] == 0));
            
            dp[l][r] = min({alpha+dp[l+1][r-1], 1+dp[l+1][r], 1+dp[l][r-1]});
            //printf("different %d, dp%d\n", alpha, dp[l][r]);
            for(int i = l; i < r; i++) dp[l][r] = min(dp[l][r], dp[l][i]+dp[i+1][r]);
        }
    }

    cout<<dp[0][n-1]<<"\n";
    if(dp[0][n-1] == 0) return 0;
    //reconstruction
    vector<pair<int,int>> st;
    st.push_back({0, n-1});
    vector<int> ans;
    while(!st.empty()){
        auto [l, r] = st.back();
        st.pop_back();
        if(l == r){
            ans.pb(l);
            continue;
        }
        if(l > r) continue;

        int dpval = dp[l][r];
        int alpha = 2*!((arr[l] % arr[r] == 0) || (arr[r] % arr[l] == 0));
        if(dpval == alpha + dp[l+1][r-1]){
            if(alpha){
                ans.push_back(l);
                ans.push_back(r);
            }
            st.push_back({l+1,r-1});
            
        }
        else if(dpval == 1+dp[l+1][r]){
            ans.push_back(l);
            st.push_back({l+1,r});
        }
        else if(dpval == 1+dp[l][r-1]){
            ans.push_back(r);
            st.push_back({l, r-1});
        }
        else{
            for(int i = l; i < r; i++){
                if(dpval == dp[l][i]+dp[i+1][r]){
                    st.push_back({l,i});
                    st.push_back({i+1,r});
                    break;
                }
            }
        }
    }

    sort(ans.begin(), ans.end());
    for(auto x : ans){
        cout<<x+1<<" ";
    }
    cout<<"\n";
}