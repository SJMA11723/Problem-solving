#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <deque>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <set>
#include <vector>

#define DEBUG if (deb)
#define pb push_back
#define forn(i, a, b) for (int i = int(a); i < int(b); i++)
#define LLINF 9223372036854775807
#define INF 2000000000
#define MOD 998244353
#define MAX 10000000
typedef long long int ll;
bool deb = false;
using namespace std;

long long func(long long n) {
    return ((n*(n+1))/2);
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  long long n;
  cin >> n;

  long long ini = 0, fin = min((long long)MAX, n);
  long long ans = 0;
  while(ini <= fin){
    long long mit = (ini+fin)/2;

    if(func(mit) <= n){
        ini = mit+1;
        ans = mit;
    }
    else{
        fin = mit-1;
    }
  }
  cout<<ans<<"\n";
}