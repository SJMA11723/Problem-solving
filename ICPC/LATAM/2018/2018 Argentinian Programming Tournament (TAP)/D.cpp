#include<bits/stdc++.h>
using namespace std;

int n,m;

int f( int g, int e){
    if( m-1 < g  ) return 0;
    if( g <= m-1 < g +e ) return 1;
    return 2;
}


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);


    cin >> n >> m;

    int xd= (n-m) + 2*(m-1) ;

    int ans = INT_MAX;
    for( int g=0; g<=n-1; g++ ){
    for( int e=0; g + e <=n-1; e++ ){
//        cout <<  g << ' ' << e << ": ";
//        cout << xd + f(g,e) << "     " << 2*g+e  << "        ";
        if( xd + f(g,e) < 2*g+e ){
            ans = min( ans, 2*g+e );
//            cout << "  sepuede\n";
        }
//        cout <<"\n";
    }
    }
//    cout << ans << " xd\n";
    if ( ans %2 == 0 )cout <<  ans/2 << ".0\n";
    if ( ans %2 == 1 )cout <<  ans/2 << ".5\n";
}
