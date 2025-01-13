#include<bits/stdc++.h>
#define COMODIN 100
using namespace std;

int n,k;
int cartas [13+1][4];

// A23456789DQJK  X
// 1 2 3 4 5 6 7 8 9 10 11 12 13 14
// A 2 3 4 5 6 7 8 9 D  Q  J  K   *
// 1 2 3 4 5 6 7 8 9 A  B  C  D   X
int elTurno( int idx, int carta ){
    /// si tienes el comodin dalo
    // (nota que si ya lo tienes no te lo acaban de dar)
    for( int c=0; c<=3; c++ ){
        if( cartas[idx][c] == COMODIN  ){
            cartas[idx][c] = carta;
            return COMODIN;
        }
    }


    /// buscar la que menos aparece y dar esa

    // contar
    map<int, int> cnt;
    for( int c=0; c<=3; c++ )
        cnt[ cartas[idx][c] ]++;
    if( carta!= COMODIN ) cnt[ carta ]++;

    // ordenar las que hay de menor a mayor
    vector< pair<int, int> > xd;
    for(  int i=1; i<= 13; i++){
        if( cnt.count(i) >= 1 )
            xd.push_back( make_pair(cnt[i],i) );
    }
    sort( xd.begin(), xd.end() );

    // si la que menos aparece es la que recives
    if( xd[0].second ==  carta ) return carta;

    // si tienes que dar una de las cartas que tienes
    for( int c=0; c<=3; c++ ){
        if( cartas[idx][c] == xd[0].second  ){
            cartas[idx][c] = carta;
            return xd[0].second;
        }
    }
    return xd[0].second; ///
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    vector< pair<int, int>  > posiblesGanadorers;
    cin >> n >> k;
    // A23456789DQJK  X
    char caracter;
    for( int i=0; i<n; i++  ){
        for( int c=0; c<=3; c++ ){
            cin >> caracter;
            if( caracter == 'A') cartas[i][c] = 1;
            else if( caracter == 'D') cartas[i][c] = 10;
            else if( caracter == 'Q') cartas[i][c] = 11;
            else if( caracter == 'J') cartas[i][c] = 12;
            else if( caracter == 'K') cartas[i][c] = 13;
            else cartas[i][c] =  caracter - '0' ;
        }

        // si no es el que recibe el comodin al principio
        if( i != k-1 ){
            // si tiene cuatro iguales
            if( cartas[i][0] ==  cartas[i][1]
            && cartas[i][1] ==  cartas[i][2]
            && cartas[i][2] ==  cartas[i][3] ){
                posiblesGanadorers.push_back( {cartas[i][0], i} );
            }
        }
    }

    // si hay algun ganador iniciando justo
    if( posiblesGanadorers.size() >= 1  ){
        sort( posiblesGanadorers.begin(), posiblesGanadorers.end() );
        cout << posiblesGanadorers[0].second + 1 << '\n';
        return 0;

    }



    bool hayGanador = false;
    int jugadorActual = k-1;
    int pasarCarta = COMODIN;

    while( !hayGanador ){
        // el jugador actual recive una carta y da una
        pasarCarta = elTurno( jugadorActual, pasarCarta );
//        cout << "turno de: " << jugadorActual << '\n';
//        for( int i=0; i<n; i++  ){
//        for( int c=0; c<=3; c++ ){
//            cout << cartas[i][c] << ' ';
//        } cout << '\n';
//        } cout << '\n';


        if( cartas[jugadorActual][0] ==  cartas[jugadorActual][1]
        && cartas[jugadorActual][1] ==  cartas[jugadorActual][2]
        && cartas[jugadorActual][2] ==  cartas[jugadorActual][3] ){

            cout << jugadorActual + 1 << '\n';
            hayGanador = true;
            //return 0;
        }
        // el sigueinte jugador
        jugadorActual++;
        if( jugadorActual == n ) jugadorActual=0;
    }

}
