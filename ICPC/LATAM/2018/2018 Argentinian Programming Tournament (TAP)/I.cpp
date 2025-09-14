#include<bits/stdc++.h>
using namespace std;


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    char a;
    int n; cin >> n;
    // P I N
    int cnt[3]={};

    for( int i=0; i<n; i++ ){
        cin >> a;
        if(  a == 'P' ) cnt[0]++;
        if(  a == 'I' ) cnt[1]++;
        if(  a == 'N' ) cnt[2]++;
    }

    if(  cnt[0] >  cnt[1] + cnt[2]  ){ //P
        cout << "SI\n";
    }else if (  cnt[2] >=  cnt[1] + cnt[0]  ){ // N
        cout << "NO\n";
    }else{
        cout << "INDECISOS\n";
    }



}
