#include<bits/stdc++.h>
#define pii pair<int,int>
using namespace std;


int main(){
//    ios_base::sync_with_stdio(0);
//    cin.tie(0);
//    cout.tie(0);


    int n,m,o;
    cin >> n >> m >>o;

    int cant[n];
    for( int &x : cant) cin >> x;


    vector< pii > dishes[m];
    for( int i=0; i<m; i++){
        int mi;
        cin >> mi;
        while( mi-- ){
            int li,qi;
            cin >> li >> qi;
            dishes[i].push_back( {li-1,qi} ); //ingrediente y cantida
        }
    }


    int ans =0 ;


    bool BREAK = false;
    ///para cada orden
    while( o-- ){
        int oi, di; // cantidad de paltillos y un paltillo
        cin >> oi;

        if(  BREAK ) continue; //esto es un brake

        bool estaOrden = true;
        ///revisar cada plantillo, y para cada paltillo
        while( oi-- ){
            cin >> di; //un platillo

            if( estaOrden == false ) continue; //esto es un brake

            bool estePlato = true;
            for(  pii xd : dishes[di-1]  ){
                if( estePlato== false) continue; //esto es un brake
                ///revisar cada ingredeinte
                if(  cant[xd.first] - xd.second <0  ){
                    estePlato = false;
//                    break;
                }
                cant[xd.first] -= xd.second;
            }

            if(  !estePlato ){
                estaOrden = false;
//                break;
            }


        }
        //si no se tyermina algunplatillo entonces no se termina la orden
        if(  !estaOrden ){
//            break;
            BREAK = true;
        }
        else   ans++;


    }

    cout << ans << '\n';

}
