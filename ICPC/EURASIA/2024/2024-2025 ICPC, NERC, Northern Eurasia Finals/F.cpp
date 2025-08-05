#include <bits/stdc++.h>

using namespace std;

typedef int64_t ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<pii> vii;
typedef vector<vector<int>> vvi;

#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define sz(x) (int)(x).size()
#define INF 10000000
#define lsb(S) ((S) & -(S))
#define DEBUG if (debb)

bool debb = false;

template <typename A, typename B>
ostream& operator<<(ostream& os, const pair<A, B>& p) {
  return os << '(' << p.fi << ", " << p.se << ')';
}
template <typename C,
          typename T = typename enable_if<!is_same<C, string>::value,
                                          typename C::value_type>::type>
ostream& operator<<(ostream& os, const C& v) {
  string sep;
  for (const T& xx : v)
    os << sep << xx, sep = " ";
  return os;
}
#define deb(...) logger(#__VA_ARGS__, __VA_ARGS__)
template <typename... Args>
void logger(string vars, Args&&... values) {
  cout << "[Debug]\n\t" << vars << " = ";
  string d = "[";
  (..., (cout << d << values, d = "] ["));
  cout << "]\n";
}


int main() {
  if (!debb)
    ios_base::sync_with_stdio(false);
  if (!debb)
    cin.tie(0);

    int t;
    cin>>t;

    while(t--){

        int n;
        cin>>n;

        string a,b;
        cin>>a>>b;

        int state[n];
        for(int i = 0; i < n; i++){
            if(a[i] == '.' && b[i] == '.') state[i] = 0;
            else if(a[i] == '.' && b[i] == '#') state[i] = 1;
            else if(a[i] == '#' && b[i] == '.') state[i] = 2;
            else state[i] = 3;
        }
        int dp[n][4];  
        for(int msk = 0; msk < 4; msk++){
            if(((msk&state[n-1]) == 0) && (((msk^state[n-1]) == 3) || ((msk^state[n-1]) == 0))) dp[n-1][msk] = 1;
            else dp[n-1][msk] = 0;
        }

        for(int i = n-2; i >= 0; i--){
            for(int msk = 0; msk < 4; msk++){
                
                if((msk&state[i]) == 0){
                    int nmsk = msk ^ state[i];
                    DEBUG deb(i, msk,nmsk);
                    switch(nmsk){
                        case 0: 
                            dp[i][msk] = dp[i+1][0]+dp[i+1][3];
                            if(dp[i][msk] > 1) dp[i][msk] = 2;
                            break;
                        case 1:
                            dp[i][msk] = dp[i+1][2];
                            break;
                        case 2: 
                            dp[i][msk] = dp[i+1][1];
                            break;
                        case 3:
                            dp[i][msk] = dp[i+1][0];
                            break;
                    }
                }
                else dp[i][msk] = 0;
            }
        }
        if(dp[0][0] == 1) cout<<"Unique\n";
        else if( dp[0][0] == 0) cout<<"None\n";
        else cout<<"Multiple\n";
    }
}