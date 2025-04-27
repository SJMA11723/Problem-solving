#include<bits/stdc++.h>

using namespace std;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);



    int t;  cin >> t;

    while( t-- ){
        int n; cin >> n;
        long double minx,miny,maxx,maxy,xx,yy;
        minx = miny =1ll*1000000;
        maxx = maxy =-1ll*1000000;

        for( int i=0; i<n; i++ ){
            cin >> xx >>yy ;
            minx = min( xx, minx);
            maxx = max( xx, maxx);
            miny = min( yy, miny);
            maxy = max( yy, maxy);
        }

        cout << fixed << setprecision(6) << (maxx-minx)*(maxy-miny) << '\n';
    }

}
