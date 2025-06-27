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
#define MAX 100000000
typedef long long int ll;
bool deb = false;
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  int n, k;
  cin >> n >> k;
  int days[n + 1], cost[n + 1];
  for (int x = 0; x < n; x++) {
    int d, c;
    cin >> days[x] >> cost[x];
  }

  int pmaxcover[k], pdays[k],pcost[k];

  for(int x = 0; x < k; x++){
    cin>>pmaxcover[x]>>pdays[x]>>pcost[x];
  }
  days[n] = INF;
  cost[n] = 0;
  int dp[n + 1];
  dp[n] = 0;

  for(int i = n-1; i >= 0; i--){

    dp[i] = cost[i]+dp[i+1];
    DEBUG printf("prevdp %d\n", dp[i]);
    for(int j = 0;  j  < k; j++){
      
      int maxc = pmaxcover[j];
      int maxdays = pdays[j];
      int passcost = pcost[j];
      
      int upto = days[i] + maxc -1;
      int ini = i, fin = n;
      int ans = i;
      while(ini <= fin){
        int mit = (ini+fin)/2;
        if(upto >= days[mit]){
          ans = mit;
          ini = mit+1;
        }
        else{
          fin = mit-1;
        }
      }
      DEBUG printf("closest %d using %d railpass\n", ans, j);
      int dist = (ans-i)+1;
      DEBUG printf("pdist %d\n", dist);
      dist = min(dist, maxdays);
      DEBUG printf("uppdist %d\n", dist);
      DEBUG printf("dist %d dp %d = %d vs transition dp %d = %d \n",dist,  i, dp[i], min(i+dist,n), passcost+ dp[min(i+dist, n)]);
      DEBUG printf("%d %d\n", passcost, dp[min(i+dist, n)]);
      dp[i] = min(dp[i], passcost + dp[min(i+dist, n)]);
      
    }

  }
  cout<<dp[0]<<"\n";
}