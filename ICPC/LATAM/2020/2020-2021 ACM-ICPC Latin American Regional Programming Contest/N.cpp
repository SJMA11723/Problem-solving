#include<bits/stdc++.h>


using namespace std;

void aDinero( string money, int&a, int &b  ){
    a = stoi( money.substr( 1, money.find(".") - 1 )  );
    b = stoi( money.substr( money.find(".") +1  )  );

}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n; cin >> n;
    string money;
    cin >> money;

    int total, totalP;
    aDinero( money, total, totalP );
//    cout << total << ' ' << totalP <<'\n';

    int ans=0;
    while( n-- ){
        int a,b;
        string m; cin >> m,
        aDinero(m,a,b);
        total+= a;
        totalP+= b;

        while(  totalP >= 100  ){
            totalP-=100;
            total++;
        }

//        cout << total << ' ' << totalP <<'\n';
        if( totalP  ) ans++;

    }

    cout << ans << '\n';
}



