#include<bits/stdc++.h>
using namespace std;

char lud( char c ){
    if(  'a' <= c && c <='z' ) return 'l';
    if(  'A' <= c && c <='Z' ) return 'u';
    if(  '0' <= c && c <='9' ) return 'd';
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);


    int n,m;
    cin >> n;

    string p[n], name[n];
    for( int i=0; i<n; i++ ) cin >> p[i] >> name[i];


    cin >> m;
    string s;
    while( m-- ){
        cin >> s;

        bool coincide = false;

        //buscar un patron
        for( int i=0; i<n; i++ ){
            //probamos la p_i

            if( s.size()!= p[i].size() ) continue;

            //comparar
            bool igual = true;
            for( int j=0; j<s.size(); j++ ){
                if(  lud(s[j]) != p[i][j] ){
                    igual = false;
                    break;
                }
            }

            //su hay match
            if( igual ){
                coincide = true;
                cout << name[i] <<'\n';
                break;
            }
        }

        //ya dejamos de bsucar patron y no encontramos
        if( !coincide ) cout << "Liar!\n" ;
    }

}
