#include<bits/stdc++.h>
using namespace std;

int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int k;
    cin >> k;

    int64_t C[k];
    int64_t P[k];
    for( int i=0; i<k; i++ ) cin >> C[i];
    for( int i=0; i<k; i++ ) cin >> P[i];


    if( P[0]==0 ){
        cout << "0\n";
    }else{
        int64_t mini = P[0]/C[0];
        int64_t pp=P[0],cc=C[0];
        for( int i=1; i<k; i++ ){
            pp+=P[i];
            cc+=C[i];
            mini = min( mini, pp/cc );
        }
        cout << mini <<"\n";
    }


    return 0;
}
