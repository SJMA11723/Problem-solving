#include <bits/stdc++.h>
#define isOn( S, j ) ( S&( 1<<(j)) )
#define setBit( S, j ) ( S |=( 1<<(j)) )
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

//    cout << (1<<16)*500 << '\n';
    int N,a,b;
    int hayBits[33]={};


    cin >> N;
    for( int i=0; i<N; i++){
        cin >> a;
        for( int j=0; j <=30; j++ ){
            if( isOn(a,j) ) hayBits[j]++;
        }
    }

    for( int i=0; i<N; i++){
        b = 0;
        for( int j=0; j <=30; j++ ){
            if( hayBits[j] ){
                setBit(b,j);
                hayBits[j]--;
            }
        }
        cout << b << " \n"[i==N-1];
    }

}
