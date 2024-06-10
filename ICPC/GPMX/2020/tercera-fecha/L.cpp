#include<bits/stdc++.h>
using namespace std;

int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n,tam;
    cin >> n;

    unordered_set<string> posiblesPalabras;
    int contadorDeGeneradores=0;
    string s,ss;
    for( int i=0; i<n; i++ ){
        cin >> s;

        /*cout << posiblesPalabras.count(s) << "\n";
        for(string t:posiblesPalabras) cout << t << " ";
        cout <<"\n";*/

        if( posiblesPalabras.count(s) ) continue;

        contadorDeGeneradores++;
        //meter todas las permutaciones ciruclaes posibles
        ss = s+s;
        tam=s.size();
        for( int j=0; j<s.size(); j++){
            posiblesPalabras.insert(ss.substr(j,tam ) );
        }
    }

    cout << contadorDeGeneradores << '\n';

    return 0;
}
