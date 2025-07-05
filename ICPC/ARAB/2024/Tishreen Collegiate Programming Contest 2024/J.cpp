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
typedef vector<pii> vii;
typedef vector<vector<int>> vvi;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define sz(x) (int)(x).size()
#define DEBUG if(debbb)
#define MAXN 300000
#define INF 100000000
const int MOD = 1e9 + 7;
bool debbb = false;

template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p){return os << '(' << p.fi << ", " << p.se << ')';}
template<typename C, typename T = typename enable_if<!is_same<C, string>::value, typename C::value_type>::type>
ostream& operator<<(ostream &os, const C &v){string sep; for(const T &x : v) os << sep << x, sep = " "; return os;}
#define deb(...) logger(#__VA_ARGS__, __VA_ARGS__)
template<typename ...Args>
void logger(string vars, Args&&... values){
    cout << "[Debug]\n\t" << vars << " = ";
    string d = "[";
    (..., (cout << d << values, d = "] ["));
    cout << "]\n";
}


int nextbit[MAXN][23];
int prefbit[MAXN][23];
long long sum(int l, int r, long long* arr){
    long long ans = arr[r];
    if(l > 0) ans-= arr[l-1];
    return ans;
}

int next(int i, int g){
    int ans = INF;
    for(int j = 0; j < 23; j++){
        if(!(g&(1<<j))){
            ans = min(ans, nextbit[i][j]);
        }
    }

    return ans;
}


void printnext(int n){
    for(int j = 0; j < 23; j++){
        for(int i = 0; i < n; i++){
            printf("%d ", nextbit[i][j]);
        }
        printf("\n");
    }
}

void printpreff(int n){
    for(int j = 0; j < 23; j++){
        for(int i = 0; i < n; i++){
            printf("%d ", prefbit[i][j]);
        }
        printf("\n");
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);


    
    int t;
    t = 1;


    while(t--){
        int n;
        cin>>n;
        int a[n],b[n];

        for(int x = 0; x < n; x++) cin>>a[x];
        for(int x = 0; x < n; x++) cin>>b[x];


        long long pref[n];
        pref[0] = (long long)a[0]*a[0];
        for(int i = 1; i < n; i++){
            pref[i] = pref[i-1]+(long long)a[i]*a[i];
        }
        for(int j = 0; j < 23; j++){
            if(b[0]& (1<<j)) prefbit[0][j] = 1;
            else prefbit[0][j]=0;
        }


        for(int i = 1; i < n; i++){
            for(int j = 0; j < 23; j++){
                if(b[i]& (1<<j)) prefbit[i][j] = prefbit[i-1][j]+1;
                else prefbit[i][j]= prefbit[i-1][j];
            }
        }
        
        for(int j = 0; j < 23; j++){
            nextbit[n-1][j] = INF;
            int next = nextbit[n-1][j];
            for(int i = n-2; i >=0; i--){
                if(prefbit[i][j]!= prefbit[i+1][j]){
                    next = i+1;
                }   
                nextbit[i][j] = next;
            }
        }
        //printnext(n);
        long long ans = 0;
        for(int l = 0; l < n; l++){
            int ri = l;
            long long g = 0;
            while(ri < n){
                DEBUG deb(l, ri);
                long long f = sum(l, ri, pref);
                g |= b[ri];
                int nn = next(ri, g);
                if(f >= g*g) {
                    DEBUG deb("continue");
                    ri = nn;          
                    continue;
                }

                int ini = l, fin = min(nn-1, n-1);
                int rf = l;
                while(ini <=fin){
                    int mit = (ini+fin)/2;
                    long long fm = sum(l, mit, pref);
                    if(fm < g*g){
                        rf = mit;
                        ini = mit+1;
                    }
                    else{
                        fin = mit-1;
                    }
                }
                DEBUG deb(ri, rf);
                ans+=(rf-ri)+1;
                ri = next(ri, g);
            }
        }

        cout<<ans<<"\n";
    }



    

}