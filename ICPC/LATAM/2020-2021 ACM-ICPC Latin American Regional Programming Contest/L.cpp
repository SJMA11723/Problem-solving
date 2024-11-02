#include<bits/stdc++.h>
#define NN 200'005

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n,x; cin  >> n >> x;

    map<int, int> comienzos;
    map<int, int> finales;


    int ultimoAcabar=0;
    while(n--){
        int s,d; cin >> s >>d;
        comienzos[s]++;
        finales[s+d]++;
    }

//    for( auto x : comienzos ) cout << x.first << ' ' << x.second << "   "; cout << '\n';
//    for( auto x : finales ) cout << x.first << ' ' << x.second << "   "; cout << '\n';


    /// cuantos molestan encada momento
    int ocupados[NN];
    memset( ocupados, 0, sizeof(ocupados) );
//    for( int x: t) cout << x << ' ';

    int cnt=0;
    for( int i=0; i< NN; i++ ){
        if( comienzos.find(i) != comienzos.end()  ) cnt += comienzos[i];
        ocupados[ i ]+= cnt;
        if( finales.find(i) != finales.end()  ) cnt -= finales[i];

//        cout << cnt << '\n';
    }

//    for( int x: t ) cout << x << ' ';cout << '\n';



    int ans= INT_MAX, id=-1;
    for( int i=0; i<=480; i++ ){
        int posAns=0;
        for( int j=i; j< NN; j+= x  ){
            posAns += ocupados[j];
        }
        if( posAns < ans   ){
            ans = posAns;
            id = i;
        }

    }


    cout << id << ' ' << ans  << '\n';


}



