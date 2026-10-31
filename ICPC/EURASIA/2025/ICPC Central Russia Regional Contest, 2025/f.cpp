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

const int MOD = 1e9 + 7;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin>>n;

    map<string, int> m = {{"single",1},{"double", 2}, {"triple", 3}, {"tetris", 4}};

    int arr[n];

    for(int i = 0; i < n; i++){
        string s;
        cin>>s;
        arr[i] = m[s];
    }
    int lim = 130;
    int lev = 0;
    int cnt = 0;
    ll points = 0;
    ll p[5] ={0, 760, 1900,5700,22800};
    for(int i = 0; i < n; i++){
        if(cnt >= lim){
            p[1]+=40;
            p[2]+=100;
            p[3]+=300;
            p[4]+=1200;
            lim+=10;
            lev++;
        }
        points+=p[arr[i]];
        cnt+=arr[i];
    }
    if(cnt >= lim) lev++;
    cout<<points<<" "<<lev+18<<"\n";
}