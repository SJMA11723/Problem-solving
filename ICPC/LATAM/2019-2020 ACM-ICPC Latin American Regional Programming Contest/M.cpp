#include<bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);


    int n,d;
    cin >> n >> d;

    int h[n];
    for( int &i:h ) cin >> i;

    int ans =0;
    for( int i=0; i<n; i++ ){
        //j llega al sigueinte que no cumple
        int j=i+1;
        while( j<n && ( h[j] <= h[j-1] + d ) ) j++;

//        //si llego a n
//        if( j==n-1 &&  (h[j] <= h[i] + d) ) j++;

        ans = max( j-i,  ans  );
//        cout <<  i <<  ' ' << j << ' ' << j-i << '\n';
    }
    cout << ans << '\n';
}
