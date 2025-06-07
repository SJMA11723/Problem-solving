#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<pii> vpii;
typedef vector<pll> vpll;

#define all(x) (x).begin(), (x).end()

const int64_t MOD = 1e9 + 7;

int num( char c ){
    return ( (c=='X')?10 : (c-'0')  );
}


bool valid( string isbn ){
    int n = isbn.size();

    int pos = 10, cnt = 0, sum = 0, ant=false, seguido=false, numbers = 0;
    for( char c : isbn ){
        if( c == '-' ){
            cnt++;
            if( ant  ) seguido = true;
            ant = true;
            continue;
        }
        sum += pos*num(c);
        pos--;
        ant= false;
        numbers++;
    }

    // si no tiene 10 digitos
    if( numbers != 10 ) return false;

    // si tiene dos separadores seguidos
    if( seguido ) return false;


    // si tiene mas de tres separadores
    if(  cnt > 3 ) return false;

    // si tiene sepradores al principio o finals
    if(  isbn[0] == '-' || isbn[n-1] == '-'  ) return false;

    //  si tiene 3 separadores entonces el final debe ser -4   guin numeor
    if( cnt == 3 && isbn[  n -2  ] != '-'  ) return false;

    // verificar la suma
    return (sum%11== 0);
}

void cambiar( string &isbn ){
    int n = isbn.size();

    int pos = 1, sum = 0;
    for( int i=0; i<n-1; i++ ){
        char c = isbn[i];
        if( c == '-' ){
            continue;
        }
        sum += pos*num(c);

        if( pos == 1 ) pos =3;
        else pos=1;

    }

    isbn[n-1] =  ( ( 10 - (sum%10) )%10 ) + '0';
}

int main(){
    ios_base::sync_with_stdio();
    cin.tie();
    cout.tie();

    int t; cin >> t;

    while( t-- ){
        string isbn10; cin >> isbn10;

        if( valid( isbn10) ){
            string isbn13 = "978-" + isbn10;
            cambiar( isbn13 );
            cout <<'\t'<< isbn13 << '\n';

        }else{
            cout <<'\t' << "invalid\n";
        }

    }

}
