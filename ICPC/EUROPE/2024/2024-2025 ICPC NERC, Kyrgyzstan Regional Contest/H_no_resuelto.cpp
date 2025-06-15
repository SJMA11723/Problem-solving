#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<pii> vpii;
typedef vector<pll> vpll;

#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
#define pb(x) push_back(x)

const int MOD = 1e9 + 7;

int main(){
    ios_base::sync_with_stdio();
    cin.tie();
    cout.tie();

    int n,m,d;cin >> n >> m >> d;
    set<int> A2B, B2A;

    for( int i=0; i<n; i++){
        int x;cin >> x;
        A2B.insert(x-d);
    }
   for( int i=0; i<m; i++){
        int x;cin >> x;
        B2A.insert(x);
   }

    int meLaEncuentro = *A2B.rbegin();
    int tiempo = 0;
    char donde = 'B';
    int camiones = 0;
    while( true   ){
        
        //cout << tiempo << " " <<  donde  << " " << camiones << "\n";
        
        if( donde == 'B' ){
            auto  it=  B2A.lower_bound( tiempo );
            if( it!= B2A.end()  ) tiempo = *it;
            // ya no hay otro camion
            else{
                break;
            }
            if(  tiempo + d >=  meLaEncuentro ) break;

            
            //cout << tiempo << " B -> A " << tiempo+d << '\n';

            tiempo= tiempo+ d;
            donde = 'A';
            camiones++;

            tiempo++;
            
        }

        else if( donde == 'A' ){
           
            auto it =  A2B.lower_bound( tiempo );
            if( it!= A2B.end()  ) tiempo = *it;
            // ya no hay otro camion
            else{
                // eso no puede pasar 
                //cout << "xxddd\n";
                return 1;
            }

             // si estoy en A ver si llego a B antes que marie llege a A
            if( tiempo +d >=  meLaEncuentro ){
                //cout << "me la encontre\n";
                break;
            }

            //cout << tiempo << " A -> B " << tiempo+d << '\n'; 
            tiempo= tiempo+ d;
            donde = 'B';
            camiones++;

            tiempo++;
        }
        

    }

    cout << donde  << " " << camiones << "\n";

}


