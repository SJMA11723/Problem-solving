#include<bits/stdc++.h>
using namespace std;


typedef int64_t ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<pii> vpii;
typedef vector<pll> vpll;


#define all(x) (x).begin(), (x).end()
#define fi first
#define se second

const int MOD = 1e9 + 7;


int main(){
    ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);


    int64_t r;  cin >> r;
    int n; cin >> n;
    vll arr(n+1);
    vll summ(n+1);
    arr[0]= 0;
    summ[0]= 0;
    for( int i=1; i<= n; i++ ){
        cin >> arr[i];
        summ[i] = arr[i];
        summ[i] += summ[i-1];
    }

    int64_t ini = 0;
    int buscado = -1;
    // [ i   j ]
    for( int i=n; i>=1 && buscado == -1 ; i--){
        int64_t sum = 0;


        for( int j=i; j<=n && buscado == -1; j++){
            sum += arr[j];
//            cout << i << " " << j <<  "   " << sum << '\n';
            if( sum <= -r && ( j==n || arr[j+1] > 0   ) ){
                buscado= j;
                ini = 0;
                break;
            }
            if( sum >= r &&  (  j==n || arr[j+1] < 0   )  ){
                buscado = j;
                ini = r;
                break;
            }


        }
    }

//    cout << buscado << '\n';
    if( buscado == -1 ){
        cout <<"uncertain\n";
    }else{
        int64_t mov= 0;
        if( buscado+1 <= n ) mov = summ[n]- summ[buscado];
//        cout << mov << '\n';
        mov+= ini;

        cout << mov << '\n';

    }

}
