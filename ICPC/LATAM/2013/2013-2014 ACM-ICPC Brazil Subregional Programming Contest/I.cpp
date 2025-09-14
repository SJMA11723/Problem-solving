#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);


    int  n,c,t,tt;
    cin >>  n >> c >> t >> tt;
    vector<int> hueco (n+1);
    hueco[0]=INT_MIN;
    for( int i=1; i<=n; i++ ) cin >> hueco[i] ;
    sort(hueco.begin(), hueco.end());



    // para cada posible comienzo
    int ans = INT_MAX;
    for( int s=1; s<=n; s++ ){
        int dp[n+1] = {};

        dp[0]= 0;
        dp[1]= min(t,tt) ;

        for( int i=2; i<=n; i++ ){
            // poner una de t o tt
            int id1 = lower_bound( hueco.begin(), hueco.end(), hueco[i]-t ) - hueco.begin();
            int id2 = lower_bound( hueco.begin(), hueco.end(), hueco[i]-tt ) - hueco.begin();
            dp[i] = min( t+dp[id1-1], tt+dp[id2-1]);
        }

//        for( int x: dp ) cout << x << ' ';  cout << '\n';
//        cout << dp[n] << '\n';
        ans = min( ans, dp[n] );


        // hacer que e sigueinte hueco sea el primero
        int mini = hueco[2];
        for( int i=1; i<=n; i++ ){
            hueco[i] =  hueco[i] - mini + 1;
            if( hueco[i] <= 0 ) hueco[i] += c;
        }
        sort(hueco.begin(), hueco.end());
//        for( int x : hueco ) cout << x << ' '; cout << '\n';
    }

    cout << ans << ' ';
}
