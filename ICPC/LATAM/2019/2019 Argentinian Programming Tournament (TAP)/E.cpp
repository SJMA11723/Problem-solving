#include<iostream>
#include<algorithm>
#include<set>
#include<vector>
#include<cstdlib>
#include<map>
#include<cmath>
#include<deque>
#include<iomanip>
#include<numeric>
 
#define DEBUG if(deb)
#define f first
#define s second
#define pb push_back
#define forn(i,a,b) for(int i = int(a); i < int(b);i++)
#define LLINF 9223372036854775807
#define MOD 1000000007
typedef long long int ll;
bool deb = false;
using namespace std;




int main() {
    int n,m;
    cin>>n>>m;
    int x, y;
    cin>>x>>y;

    int pA = x*m+n*y, qA = 2*n*m;

    int pB = x+y, qB= n+m;

    if(pA*qB == pB*qA){
        cout<<"C\n";
    }
    else if(pA*qB > pB*qA){
        cout<<"A\n";
    }
    else{
        cout<<"B\n";
    }

}