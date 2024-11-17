#include<bits/stdc++.h>
#define NMAX 60000
///57356
using namespace std;

// Función para calcular los factores primos de un número
vector<int> factorizar(int n) {
    vector<int> factores;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            factores.push_back(i);
            while (n % i == 0) n /= i;
        }
    }
    if (n > 1) factores.push_back(n);
    return factores;
}

// Función para contar los coprimos hasta "limite" usando inclusión-exclusión
int contarCoprimos(int limite, const vector<int>& factores) {
    int m = factores.size();
    int coprimos = limite;
    for (int mask = 1; mask < (1 << m); mask++) {
        int prod = 1, bits = 0;
        for (int i = 0; i < m; i++) {
            if (mask & (1 << i)) {
                if ((long long)prod * factores[i] > limite) {
                    prod = limite + 1; // Excede el límite
                    break;
                }
                prod *= factores[i];
                bits++;
            }
        }
        if (prod > limite) continue;
        if (bits % 2 == 1) coprimos -= limite / prod; // Inclusión
        else coprimos += limite / prod; // Exclusión
    }
    return coprimos;
}

// Función para encontrar el k-ésimo coprimo
int encontrarKEsimoCoprimo(int n, int k) {
    vector<int> factores = factorizar(n);

    // Búsqueda binaria para encontrar el rango donde está el k-ésimo coprimo
    int izquierda = 1, derecha = n * 2;
    while (izquierda < derecha) {
        int medio = (izquierda + derecha) / 2;
        if (contarCoprimos(medio, factores) < k) {
            izquierda = medio + 1;
        } else {
            derecha = medio;
        }
    }

    return izquierda;
}


vector<int> primos;
vector<int> lp(NMAX+1,0);
void criba_lineal( ){
    primos.clear();
    for( long long i = 2; i<= NMAX; i++){
        if(  !lp[i]  ){
            lp[i] = i;
            primos.push_back(i);
        }
        for( int j=0; i* (long long)primos[j] <= NMAX ; j++  ){
            lp[  i*primos[j] ] = primos[j];
            if( primos[j] == lp[i] )
                break;
        }
    }

}
int dp[NMAX+1];

int phi( int n ){
    if( n<= 1) return 1;
    if( !dp[n] ){
        int pot=1, p=lp[n], n0=n;
        while( n0%p == 0 ){
            pot*=p;
            n0/=p;
        }
        pot/=p;
        dp[n]= pot * (p-1)*phi(n0);
    }
    return dp[n];
}

int gcd( int a, int b){
    if( !b ) return a;
    return gcd(b, a%b);
}

int main(){
    ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    criba_lineal();
    //for(int i=0; i<=NMAX; i++) cout << lp[i] << " \n"[i==NMAX];

//    int64_t acum = 0;
//    int nn=0;
//    while( acum <= 1'000'000'000  ){
//        nn++;
//        acum += 1ll*phi(nn+1);
//        cout << nn << ' ' << phi(nn+1) << ' ' << acum << '\n';
//    }

    int N = NMAX-10;

    int64_t hay[N+1];
    hay[0]=0;
    for( int i=1; i<=N; i++  ){
        hay[i] = hay[i-1] + phi(i+1);
    }

    int t,n; cin >> t;
    while( t-- ){
        cin >> n;
        ///buscamos el ultimo menor igual
        // hay[l] < n <= hay[r]
        int l=0, r= N;
        while( l +1 < r ){
            int mid = (l+r)/2;
            if( hay[mid] < n  ) l = mid;
            else r =mid;
        }
        //cout << l << '\n';

        ///entonces empieza en la diagonal r
//        int tenemos = hay[l];
//        for( int x=1; x<= r; x++){
//            int y = r+1-x;
//            if( gcd(x,y) == 1 ) tenemos++;
//            if( tenemos == n  ){
//                cout << x << ' ' << y << '\n';
//                break;
//            }
//        }
        int x = encontrarKEsimoCoprimo(r+1, n-hay[l] );
        int y = r+1-x;
        cout << x << ' ' << y << '\n';
    }
}
