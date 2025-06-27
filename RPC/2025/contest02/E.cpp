#include<bits/stdc++.h>
using namespace std;



int main(){
    ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);
//    while( true ){
    int n,k,p; cin >> n >> k >> p;

    vector< pair<int,string> > xd;

    xd.push_back({  p*( n-k + 1 + 3 + n +1) + (100-p)*( n-k +1 ) , "continue"  });
    xd.push_back({  p*( 1 + n-k + 1) + (100-p)*( 1+ n-k  +1 + 3 + n +1 ) , "backspace"  });
    xd.push_back({  p*( 3 + n +1 ) + (100-p)*( 3+n +1) , "restart"  });

//    cout << xd[0].second << "  " << xd[0].first <<'\n';
//    cout << xd[1].second << "  " << xd[1].first <<'\n';
//    cout << xd[2].second << "  " << xd[2].first <<'\n';
    sort(xd.begin(),xd.end());

    cout << xd[0].second << '\n';
//    }
}
