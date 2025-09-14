#include<bits/stdc++.h>

using namespace std;


bool match( string n, string s ){

    for( int i=0; i<7; i++ ){
        if(   n[i] == 'G' && s[i] == 'g' ) return false;
        if(   n[i] == 'g' && s[i] ==  'G'  ) return false;
    }
    return true;
}


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    vector<string> numeros = {
        "GGGgGGG",
        "gggggGG",
        "gGGGGGg",
        "ggGGGGG",
        "GggGgGG",
        "GgGGGgG",
        "GGGGGgG",
        "ggGggGG",
        "GGGGGGG",
        "GgGGGGG" };


    int N; cin >> N;

    while( N -- ){
        string s; cin >> s;

        int funciona = 0;
        int ans = -1;
        for( int i=0; i<10; i++){
            if( match(  numeros[i], s  ) ){
                funciona++;
                ans = i;
            }
        }

        if( funciona == 1 ) cout << ans;
        else cout << "*";

    }
    cout <<'\n';


}