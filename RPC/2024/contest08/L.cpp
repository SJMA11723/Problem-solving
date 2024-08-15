#include <bits/stdc++.h>

using namespace std;

int main(){
//    ios_base::sync_with_stdio(0);
//    cin.tie(0);
//    cout.tie(0);


    string s; cin >> s;
    int n=s.size();


//    char c;
//    while( cin >> c&& ( c=='1' || c=='0') ) n++;
//    cout << n << '\n';

    int64_t  num =32;
    int cant =1;
    while( num < n ){
        cant++;
        num*=2;
    }

    while( cant-- ) cout << "long" << " \n"[cant==0];


}

// 10 00111 01010 11110 10001 10101 01111
