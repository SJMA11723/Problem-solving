#include <bits\stdc++.h>

using namespace std;


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n; cin >> n;

    string arr[n];

    int hay[ 'Z' - 'A' + 30 ]={};

    for( int i=0; i<n; i++ ){
        cin >> arr[i];
        hay[ arr[i][0] - 'A' ]++;
    }

    bool esverdad = false;


    for( int i=0; i<n; i++ ){
        //ver i esta palabra es un acornimos
        bool este = true;
        for( int j=0; j< arr[i].size(); j++ ){
            if(  hay[ arr[i][j] - 'A' ] == 0  ){
                este = false;
                break;
            }
        }

        if( este ){
            esverdad = true;
            break;
        }
    }


    if( esverdad ) cout << "Y\n";
    else cout << "N\n";


}
