#include<bits/stdc++.h>


using namespace std;


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n,m; cin >> n >> m ;

    vector<int> xd;

    for(  int i=1; i<=n; i++ ){
        int a; cin >> a;
        xd.push_back(a);

    }

    for(  int i=n+1; i<=2*m; i++ ){
        xd.push_back(0);
    }


    sort(  xd.begin(), xd.end());
//    for( int x: xd ) cout << x << ' ';
//    cout << '\n';


    int ans = 0;
    for( int i=0; i<m; i++ ){
        ans = max( ans, xd[i] + xd[2*m-i - 1]  );

    }

    cout << ans << '\n';

}
