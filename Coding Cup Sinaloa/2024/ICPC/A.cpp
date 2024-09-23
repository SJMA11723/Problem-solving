#include<bits/stdc++.h>

using namespace std;

string vocales = "AEIOUaeiou";
bool isVocal( char c ){
    for( char a : vocales )
        if(  c == a  ) return true;
    return false;
}

string consontantes = "bBcCdDfFgGhHjJkKlLmMnNpPqQrRsStTvVwWxXyYZz";
bool isCons( char c ){
    for( char a : consontantes )
        if(  c == a  ) return true;
    return false;
}

char toMayus(  char c ){
    if(  'a'<= c && c <= 'z'  ) return c + ('A'-'a');
    return c;
}

char toMinus( char c ){
    if(  'a'<= c && c <= 'z'  ) return c ;
    return c - ('A'-'a');
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    string s,t;
    bool con, voc;

    getline(cin, t);
    if( t == "vocales"){
        con = false;
        voc = true;
    }else{
        con = true;
        voc = false;
    }


    while(  getline( cin, s ) ){
        for( char a: s){
            if( isVocal(a) ){
                if( voc ) cout << toMayus(a);
                else cout << toMinus(a);

            }
            else if( isCons(a) ){
                if( con ) cout << toMayus(a);
                else cout << toMinus(a);
            }
            else{
                cout << a;

            }
        }
        cout << '\n';
    }

}
