#include<bits/stdc++.h>

using namespace std;

typedef int64_t ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<pii> vpii;
typedef vector<pll> vpll;

#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define sz(x) (int)(x).size()


void ultimoInicio(vpll & tareas, vll & inicios ) {

    ll anterior = (1LL << 60);  // inf  63, aqui debe tomar el di mas grande

    for( int i = sz(tareas) - 1; i >= 0; --i ){

        ll di = tareas[i].first;
        ll ai = tareas[i].second;

        ll fin  = min(di, anterior);
        ll ini = fin - ai;
        inicios[i] = ini;
        anterior   = ini;

    }
}


int resolver(ll tq,  vll &inicios,  vll &aa,  vll &suml, vpll &tasks){
//    cout << tq << ' ';
    // primer tal que su inicio es mayor igual al tiempo dado
    int pos = int( lower_bound(all(inicios), tq) - inicios.begin() );


    pos--; // la ultima tarra que inicia menor escricto que tq
//    cout << pos << ' ';

    // timepo para series  = tiempo dado - tiempo que se teine que hacer antes
    ll tiempolibre = tq;

    if( pos != -1 ){
        if( pos > 0 ) tiempolibre -= aa[pos-1+1];

        ll tiempoUltimaTarea = min( tq - inicios[pos]  , tasks[pos].se ) ;

        tiempolibre -= tiempoUltimaTarea;
    }

    //if(tiempolibre < 0) return 0;

//    cout << tiempolibre << ' ';

    // el prefijo ams grande de serie que podemos ver
    int x = int( upper_bound(all(suml), tiempolibre) - suml.begin() ) - 1;
    if (x < 0) x = 0;
//    cout << x << '\n';
    return x;
}


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t; cin >> t;


    while( t-- ){
        int n,m,q; cin >> n >> m >>q;

        vll a(n), d(n), l(m), tk(q);

        for( ll & x : a ) cin >> x;
        for( ll & x : d ) cin >> x;
        for( ll & x : l ) cin >> x;
        for( ll & x : tk ) cin >> x;


        // ordenar tareas
        vpll tasks(n);
        for (int i = 0; i < n; ++i) tasks[i] = {d[i], a[i]};
        sort(all(tasks));


        // calcualr los ultimos iniciso de todas las tareas
        vll inicios(n);
        ultimoInicio( tasks, inicios );
        //for( int i=0; i <n; i++) cout << inicios[i] << ' '; cout << "\n";


        // suma acumulada
        vll aa(n+1, 0);
        for( int i=1; i <=n; i++) aa[i] = aa[i-1] + tasks[i-1].se;
//        for( int i=0; i <=n; i++) cout << aa[i] << ' '; cout << "\n";

        vll suml(m+1, 0);
        for( int j=1; j <=m; j++) suml[j] = suml[j-1] + l[j-1];
//        for( int i=0; i <=m; i++) cout << suml[i] << ' '; cout << "\n";


        // responder
        cout << resolver( tk[0], inicios, aa, suml, tasks );
        for( int i=1; i < q; ++i ){
            cout << ' ' << resolver( tk[i], inicios, aa, suml, tasks );
        }
        cout << '\n';
//        cout << '\n';

    }

}


/*
1
2 3 1
2 2
5 3
2 1 1
4


3 4 5
8 trabajo
10
2duracion <---
9


2min tienenque empezar
10 termina proque dura 8

9 tiempo acutla - 8 trabajo = 1  pero al seire dura 2


0 1 2 3 4 5 6 7 8 9 10\
 S S T T         T  T

 0 1 2 3 4 5 6 7 8 9 10\
 S T T         T  T


           t               t
0 0 0 T T T T T T  0 0 0 0 0 00





*/
