#include<bits/stdc++.h>
using namespace std;

int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n,w,l,x,y,tx,ty;

    cin >> n;
    cin >> w >> l >> tx >> ty;
    double uno= 1.00;
    vector<double> A;
    for( int i=0; i<n; i++ ){
        cin >> x >>y;
        A.push_back( sqrt( uno*(x-tx)*(x-tx) + uno*(y-ty)*(y-ty) ) ); //multipicar por 1 para que si dea dobule
    }

    vector<double> R;
    for( int i=0; i<n; i++ ){
        cin >> x >> y;
        R.push_back( sqrt( uno*(x-tx)*(x-tx) + uno*(y-ty)*(y-ty) ) );
    }

    sort( A.begin(), A.end() );
    sort( R.begin(), R.end() );

    /*cout << "\n";
    for( int64_t a:A ) cout << a << " ";
    cout << "\n";
    for( int64_t a:A ) cout << a << " ";
    cout << "\n\n";*/

    if( A[0]< R[0] ){
        cout << "A ";
        int cnt=0;
        for( int64_t a:A ){
            if( a<R[0] ) cnt++;
        }
        cout << cnt << "\n";

    }else{
        cout << "R ";
        int cnt=0;
        for( int64_t r:R ){
            if( r<A[0] ) cnt++;
        }
        cout << cnt << "\n";
    }
    /// Falta agrega lo de la preciison cudiado, ya mero, ahorita vuelvo, no tardo

    return 0;
}
