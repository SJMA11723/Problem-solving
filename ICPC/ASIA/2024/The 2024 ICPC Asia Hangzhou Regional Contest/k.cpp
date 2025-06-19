#include <bits/stdc++.h>

using namespace std;

typedef int64_t ll;
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



int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int t; cin >> t;

    while( t-- ){
        int n,m,k; cin >> n >> m >>k;
        
        int cnt = 1;
        
        int vectoresRow[n][m];

       
        for( int i=0; i<n*m; i++){
            int p; cin >> p; p--;
            int x = p/m, y = p%m;
            vectoresRow[x][y] =  cnt++;
        }
    

        if( k >= m-1 ){
            cout << m << '\n';
            continue;
        }

        int ans = m*n;
        for( int i=0; i<n; i++ ){
            sort( vectoresRow[i], vectoresRow[i]+m );
            ans = min( ans,  max(m,vectoresRow[i][m-1-k]) );
            //cout << i << " " << max(m,vectoresRow[i][m-1-k]) << '\n';
        }

        cout << ans << '\n';

   /*      for( int i=0; i<n;i++)
        for( int j=0; j<m;j++) cout << vectoresRow[i][j] << " \n"[j==m-1]; */

    

    }


}