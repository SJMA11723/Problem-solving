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
#define f first
#define s second
#define pb push_back
#define forn(i, a, b) for (int i = int(a); i < int(b); i++)
#define LLINF 9223372036854775807
#define MOD 998244353
#define MAX 100000
typedef long long int ll;
bool deb = false;
using namespace std;
int
main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  vector<ll> nums;

  nums.pb(0);


  
  for(int num = 1; num < 10; num++){
    for(int i = 1; i < 10; i++){
      string temp = "";
      for(int j = 0; j < i; j++ ){
        temp.pb('0'+num);
      }
      if(stoi(temp) == 10) continue;
      nums.pb(stoi(temp));
    }
  }
  ll i = 100;
  for(int x = 0; x < 8; x++){
    nums.pb(i);
    i*=10;
  }
  sort(nums.begin(), nums.end());

  //for(auto n : nums) cout<<n<<" ";
  int n;
  cin>>n;
  i = 0;
  int ans = i;
  while( i < nums.size() &&n >= nums[i]){
    ans = i;
    i++;
  }

  cout<<ans+1<<"\n";
  
}