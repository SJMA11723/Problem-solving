#include<bits/stdc++.h>

using namespace std;



int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    ifstream cin("foreign.in");
    ofstream cout("foreign.out");

    string arr; cin >> arr;
    int n = arr.size();

    int64_t cntw[n+1], cntc[n+1]; cntw[n] = cntc[n] = 0;

    int xd = 1;
    for( int i = n - 1; i >= 0; i-- ){
        cntw[i] = cntw[i+1];
        cntc[i] = cntc[i+1];
        if( arr[i] == 'W') cntw[i]+=xd;
        else cntc[i]+=xd;
        xd++;
    }

    int div = 1; long double ans = 0, tmp=0;
    for( int i= n-1; i>=0; i--, div++){
        tmp = 0;
        if( arr[i] == 'C' ) tmp+= cntw[i];
        else tmp+= cntc[i];

        tmp += ans;
        tmp /= div;
        ans += tmp;
    }
    cout << fixed<< setprecision(11) << tmp << '\n';



}