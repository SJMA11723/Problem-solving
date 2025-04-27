#include<bits/stdc++.h>
using namespace std;

typedef pair<int, int> pi;
#define s second
#define f first
#define all(x) (x).begin(), (x).end()

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);


    int t; cin >> t;

    while( t-- ){
        int n; cin >> n;
        char c;
        int ans =0, act =1;
        for( int i=0; i<n; i++ ){
            cin >> c;
            if( c == 'T' ){
                ans+= act;
                act =1;
            }
            else{
                act*=2;
            }
        }
        cout << ans <<'\n';
    }
}
