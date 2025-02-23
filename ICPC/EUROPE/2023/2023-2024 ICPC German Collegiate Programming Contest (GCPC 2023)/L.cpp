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

vector<int>
preffixFunction(const string& s)
{
  int n = s.size();
  vector<int> pi(n);

  for (int i = 1; i < n; ++i) {
    int j = pi[i - 1];
    while (j && s[i] != s[j])
      j = pi[j - 1];
    pi[i] = j + (s[i] == s[j]);
  }

  return pi;
}
int
main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  string s;
  cin >> s;
  bool preff[s.size()];
  bool suff[s.size()];
  int n = s.size();
  vector<bool> last;
  // 1 open
  // 0 closed
  for (int x = 0; x < n; x++) {
    if (s[x] == '(') {
      // 1 (
      last.pb(1);
    } else {
      // 0 )
      if (last.back() == 1)
        last.pop_back();
    }

    if (last.empty())
      preff[x] = true;
    else
      preff[x] = false;
  }

  for (int x = n - 1; x >= 0; x--) {
    if (s[x] == ')') {
      // 1 )
      last.pb(1);
    } else {
      // 0 (
      if (last.back() == 1)
        last.pop_back();
    }

    if (last.empty())
      suff[x] = true;
    else
      suff[x] = false;
  }

  DEBUG for (auto x : preff) cout << x << " ";
  DEBUG cout << "\n";
  DEBUG for (auto x : suff) cout << x << " ";
  DEBUG cout << "\n";
  vector<int> lps = preffixFunction(s);
  string str = s + s;
  DEBUG cout<<str<<"\n";
  int m = str.size();

  set<int> bannedsuffix;

  int ans = 0;
  int j = 0;
  int i = 0;
  while (i < m) {
    if (str[i] == s[j]) {
      i++;
      j++;
      if (j == n) {
        bannedsuffix.insert((i-n));
        j = lps[j - 1];
        ans++;
      }
    } else if (j == 0)
      i++;
    else
      j = lps[j - 1];
  }

  DEBUG for (auto x : bannedsuffix) cout << x << "\n";

  for(int x = 1; x < n; x++){
    if((suff[x] && preff[x-1]) && (bannedsuffix.count(x) == 0)){  
      
      for(int i = x; i < n; i++){
        cout<<s[i];
      }
      for(int i = 0; i < x; i++){
        cout<<s[i];
      }
      return 0;
    }
  }

  cout<<"no\n";
}