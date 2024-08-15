#include <bits/stdc++.h>

using namespace std;

bool esMayus( char c){
    if( 'A'<= c&& c<= 'Z' ) return true;
    else return false;
}

char volverMayus( char c ){
    if( esMayus(c) )return c;
    return c + 'A'-'a';
}

bool iguales( char c, char a){
    if( c == ' ' ) return c==a;
    return volverMayus(c) == volverMayus(a);
}


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    string s;
    getline(cin, s);

    //cout << volverMayus('f') << volverMayus( 'E' ) << volverMayus('j') << volverMayus( 'z' ) <<'\n';
//    cout << esMayus('H') << esMayus( 'E' ) << esMayus('j') << esMayus( 'z' ) <<'\n';

    int costo=0;
    int anteriormayus= false;
    for( int i=0; i<s.size(); i++   ){

        if(  s[i] == ' '){
            if(  !i || s[i-1]!=' ' ) costo++;
            continue;
        }

        //mantener presionado la misma letra
        if( i && iguales( s[i], s[i-1])  ) costo+=0;
        else costo+=1;


        //blocmayus
        if( esMayus( s[i] ) ){
            costo++;
            if( anteriormayus  ) costo--;

            anteriormayus=true;
        }else{
            anteriormayus=false;
        }





    }
    cout << costo << '\n';

}
