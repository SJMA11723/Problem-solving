#include<bits/stdc++.h>
using namespace std;

typedef pair<int, int> pi;
#define s second
#define f first
#define all(x) (x).begin(), (x).end()

int ppp( string fuerza ){
    if( fuerza == "ppp" ) return 0;
    if( fuerza == "pp" ) return 1;
    if( fuerza == "p" ) return 2;
    if( fuerza == "mp" ) return 3;
    if( fuerza == "mf" ) return 4;
    if( fuerza == "f" ) return 5;
    if( fuerza == "ff" ) return 6;
    if( fuerza == "fff" ) return 7;
    else return 7;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n,m,xd; cin >> n >> m;
    vector<pi> notas(n);
    for( int i=0; i<n; i++ ){
        cin >> xd;
        notas[i] = {xd, -100};
    }

    int idx; string fuerza;
    for( int i=0; i<m; i++ ){
        cin >> idx >>  fuerza;
        notas[idx-1].s = -1*ppp( fuerza );
    }

    // poner fuerza a las notas
    for( int i=0; i<n; i++ ){
        if( notas[i].s == -100 ) notas[i].s =  notas[i-1].s;
    }

//    for( int i=0; i<n; i++ )
//        cout << notas[i].f << " " << notas[i].s << "\n";

    sort( notas.begin(), notas.end() );

//    for( int i=0; i<n; i++ )
//        cout << notas[i].f << " " << notas[i].s << "\n";

    // hacer prefix para cada tipo de nota
    // prefix[j][i] = cuantas notas de dinamico j hay en [i:n]
    int cuantasNotas[8][n+1];
    for( int j=0; j<8; j++) cuantasNotas[j][n] = 0;

    for( int i=n-1;i>= 0 ; i--){
        for( int j=0; j<8; j++) cuantasNotas[j][i] = 0;

        cuantasNotas[ -notas[i].s ][i] = 1;

        for( int j=0; j<8; j++){
            cuantasNotas[j][i] += cuantasNotas[j][i+1];
        }
    }

    // para cada indice i,  hay una nota *,j el rango [i+1:n] tiene notas mayores
    // contar cuentyas tirne tipo < j
    int64_t inconsistent = 0;

    for( int i=0; i<n; i++ ){
        int laFuerza = -notas[i].s;
//        cout << i << " : ";
        for(  int j=0 ; j< laFuerza; j++){
            inconsistent += 1ll*cuantasNotas[j][i+1];
//            cout << cuantasNotas[j][i+1] << " ";
        }
//        cout << "\n";
    }

    cout << inconsistent << '\n';


}




/*
8 8
80 70 60 50 40 30 20 10
1 ppp
2 pp
3 p
4 mp
5 mf
6 f
7 ff
8 fff

10 7 fff
20 6 ff
30 5 f
40 4 mf
50 3 mp
60 2 p
70 1 pp
80 0 ppp



9 8
90 80 70 60 50 40 30 20 10
1 ppp
2 pp
3 p
4 mp
5 mf
6 f
7 ff
8 fff






3
3
10 10 10
1 ppp
2 fff
3 p

10 fff -7
10 p -2
10 ppp -0

10 ppp 0
10 p 2
10 fff 7



8 6
10 p
15 p
20 f <--
30 ff
19 p
20 p  <--
35 f
40 ff





*/
