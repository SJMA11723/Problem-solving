
#include <bits/stdc++.h>

using namespace std;

int queEs( int a, int b, int c){
    if( a==b && b== c) return 3;
    if( a==b || b==c || a==c) return 2;
    return 0;
}

string ans( int a, int b, int c){
    int xd[3]={a,b,c};
    sort( xd, xd+3 );
    string ans = to_string(xd[0]);
    ans+=" ";
    ans+= to_string(xd[1]);
    ans+=" ";
    ans+=to_string(xd[2]);
    return ans;
}


string siguientePareja( int a, int b, int c){
    int pareja, nopareja;

    if( a==b ) pareja=a, nopareja=c;
    if( b==c ) pareja=b, nopareja=a;
    if( c==a ) pareja=c, nopareja=b;

    if( pareja == 13 && nopareja == 12 )
        return ans(1,1,1);

    nopareja++;
    if( nopareja<=13 && nopareja!=pareja )
        return ans(pareja,pareja,nopareja);
    nopareja++;
    if( nopareja<=13 && nopareja!=pareja )
        return ans(pareja,pareja,nopareja);

    pareja++;
    nopareja=1;
    return ans(pareja,pareja,nopareja);
}

string siguienteTrio( int a, int b, int c){
    return ans( a+1, a+1, a+1 );
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);


    int a,b,c;

    cin >> a >> b >> c;


    while( a || b || c  ){
        if( a==13 && b==13 && c==13  )
            cout << "*\n";
        else{
            int what = queEs( a,b,c );

            if(  what == 0 )
                cout << "1 1 2\n";
            else if( what == 2)
                cout << siguientePareja(a,b,c) << '\n';
            else
                cout << siguienteTrio(a,b,c) << '\n';

        }

        cin >> a >> b >> c;
    }

}
