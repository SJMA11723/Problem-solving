#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<pii> vpii;
typedef vector<pll> vpll;

#define all(x) (x).begin(), (x).end()
#define fi first
#define se second
#define is_on(S, j) (S & (1ll << (j)))

const int64_t MOD = 1e9 + 7;

bool xd( int mid, int pos, int l , int r,   vi & arr){
    if( mid == l-1) return false; // 0
    if( mid == r+1) return true; // 1
    return is_on(arr[mid], pos);
}
// aqui bsuqeuda binaria
int encuentra( int l, int r, int pos, vi & arr ){
    int primer_uno = -1;
    for( int i=l; i<=r && primer_uno == -1; i++){
        if(  is_on(arr[i], pos) ) primer_uno = i;
    }
    if(  primer_uno == -1 ) primer_uno = r+1;
    return primer_uno;
//    r++;
//    while(  l +1  <  r ){
//        int mid = (l+r)/2;
//        if( xd(mid,pos, l, r, arr) ) r = mid;
//        else l = mid;
//    }
//    return r;
}


void solve( int l, int r, int pos, ll & ans, vi &arr ){

    if( l >= r  ) return;

    //                       l           r
    // buscar donde pasa de  0 0 0 0 1 1 1
    // si no hay uno entonces pone r+1
    int primer_uno = encuentra(l,r,   pos, arr);

    int cnt_0 = primer_uno - l;
    int cnt_1 = r - (primer_uno-1) ;

    ans+= 1ll*cnt_0*cnt_1*pos;

//    cout << "pos:" << pos << "  " <<  l << " " << primer_uno -1 << "   " << primer_uno << " " << r <<  '\n';

    solve( l, primer_uno -1 , pos-1,  ans, arr );
    solve( primer_uno, r , pos-1,  ans, arr );

}

int main(){
    ios_base::sync_with_stdio();
    cin.tie();
    cout.tie();

    int t; cin >> t;

    while( t-- ){


        int n; cin >> n;
        vi arr(n); for( int &x : arr) cin >> x;
        sort( all(arr) );


        ll ans=0;
        solve( 0, n-1, 30,   ans, arr);
        cout << ans <<'\n';

    }



}

/*


2
5
15 3 6 8 10
pos:3  0 4
pos:3  0 1   2 4
pos:2  0 1
pos:2  0 1   2 1
pos:1  0 1
pos:1  0 -1   0 1
pos:0  0 1
pos:0  0 -1   0 1
pos:2  2 4
pos:2  2 4   5 4
pos:1  2 4
pos:1  2 2   3 4
pos:0  3 4
pos:0  3 4   5 4
8
4
1 2 3 4
pos:3  0 3
pos:3  0 3   4 3
pos:2  0 3
pos:2  0 3   4 3
pos:1  0 3
pos:1  0 0   1 3
pos:0  1 3
pos:0  1 1   2 3
5



2
5
15 3 6 8 10
1  4
2  7
3  6
4  2
5  0
19

4
1 2 3 4
1  4
2  4
3  1
4  0
9

*/
