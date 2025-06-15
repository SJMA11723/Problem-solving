#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<pii> vpii;
typedef vector<pll> vpll;

#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
#define pb push_back

const int MOD = 1e9 + 7;

// O( n log log n)
void criba(int n, vector<int> &primos){
    primos.clear();
    if(n < 2) return;
    vector<bool> no_primo(n + 1);
    no_primo[0] = no_primo[1] = true;
    for(long long i = 3; i * i <= n; i += 2){
        if(no_primo[i]) continue;
        for(long long j = i * i; j <= n; j += 2 * i)
            no_primo[j] = true;
    }
    primos.push_back(2);
    for(int i = 3; i <= n; i += 2){
        if(!no_primo[i])
            primos.push_back(i);
    }
}


void mayorSubcadena(  int act , vi &dp, vector< vi >  &Ady, vi& dp_ans ){
    int maxi = 0;
    for( int hijo : Ady[act] ){
        if( dp[act]==-1 ) mayorSubcadena( hijo, dp, Ady, dp_ans );
        if( dp[hijo] > maxi ){
            maxi =   dp[hijo];
            dp_ans[act] = hijo;
        }
    }
    dp[act] = maxi+1;
}

int main(){
/*     ios_base::sync_with_stdio();
    cin.tie();
    cout.tie(); */

    int n; cin >> n;
    int m = 2000001;
    int arr[m] ={};

    for( int i=1; i<=n; i++ ){
        int a; cin>> a;
        arr[a] = i;
    }

    vi primos;
    criba( m, primos );

    // crear grafo
    vector< vi >  Ady (m+1, vector<int>(0) );

    for( int & p: primos ){
        int num = p;
        int ant = -1;
        while( num < m ){
            // si si esta en el input
            if( arr[num] != 0  ){
                if( ant != -1 ) Ady[num].pb(ant);
                ant = num;
            }

            // sigueinte
            num+= p;
        }

    }

    for( int i=1; i<m; i++ ){
        if( arr[i]!= 0)  Ady[m].pb(i);
    }

    // ver el grafo
/*     for( int i=1; i<=m; i++ ){
        cout << i << " : ";
        for( int x: Ady[i] ) cout << x << " ";
        cout << "\n";
    }  */


    vi dp(m+1,-1);
    vi dp_ans(m+1,0);
    mayorSubcadena(m, dp, Ady, dp_ans);

    /* for( int i=1; i<=m; i++ ) cout << i << " " << dp[i]  << "\n"; */

    vi ans;

    cout << dp[m]-1 << '\n';


    int act =  dp_ans[m];
  
    // si de casulaidad el primero es 0
    if( act == 0 ){
        cout << "1\n";
        return 0;
    }

    while( act ){
        //cout << " " << arr[act];
        ans.pb(act);    
        act =  dp_ans[act];
    }

    for( int i=ans.size()-1; i>=0; i--){
        cout << arr[ans[i]] << " \n"[i==0];
    }


}