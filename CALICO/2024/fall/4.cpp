#include<bits/stdc++.h>

using namespace std;


int main(){
    ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    int t; cin >> t;

    while( t--){
        double vida,cura,d,v,torm;
        cin >> vida >> cura >> d >> v >> torm;

        //cuanto dano total hace = tierpo que pasa en tormenta * dano porsegundo
        double dano_recivido = (d/v) * torm;

        ///si logra llegar sin curarse
        if( dano_recivido <= vida ){
            cout << setprecision(6) << fixed;
            cout  << d/v << '\n';
            continue;
        }


        // tasa de curtacion efectivas sputs de vida / segundos
        double cura_efectivo = cura- torm;


        ///si mientras s ecura recive aun mas dano
        if(  cura_efectivo <= 0 ){
            cout << "-1\n";
            continue;
        }

        double necesario_curar = dano_recivido - vida;

        cout << setprecision(6) << fixed;
        cout << (d/v  +   necesario_curar/cura_efectivo ) << '\n';
    }
}
