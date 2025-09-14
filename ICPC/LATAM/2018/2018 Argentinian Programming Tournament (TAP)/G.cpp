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
#define x first
#define y second
#define pb push_back
#define forn(i, a, b) for (int i = int(a); i < int(b); i++)
#define LLINF 9223372036854775807
#define MOD 998244353
typedef long long int ll;

bool deb = false;
using namespace std;

typedef pair<int, int> point;

int
dotprod(point p1, point p2)
{
  return p1.x * p2.x + p1.y * p2.y;
}

point
diff(point p1, point p2)
{
  return { p1.x - p2.x, p1.y - p2.y };
}
bool
valid(point p1, point p2, point p3)
{

  // incide en p1
  point p1A = diff(p1, p2);
  point p1B = diff(p2, p3);

  // incide en p1
  point p2A = diff(p1, p2);
  point p2B = diff(p3, p1);

  // incide en p3
  point p3A = diff(p1, p3);
  point p3B = diff(p3, p2);


   DEBUG{

    printf("1 %d %d\n", p1A.x,p1A.y);
    printf("1 %d %d\n", p1B.x,p1B.y);

    printf("2 %d %d\n", p2A.x,p2A.y);
    printf("2 %d %d\n", p2B.x,p2B.y);

    printf("3 %d %d\n", p3A.x,p3A.y);
    printf("3 %d %d\n", p3B.x,p3B.y);
   }
  if (dotprod(p1A, p1B) == 0)
    return true;
  if (dotprod(p2A, p2B) == 0)
    return true;
  if (dotprod(p3A, p3B) == 0)
    return true;

  return false;
}

int
main()
{
  int n;
  cin >> n;
  vector<point> v;

  for (int i = 0; i < n; i++) {
    int xx, yy;
    cin >> xx >> yy;

    v.pb({ xx, yy });
  }

  int ans = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      for (int k = 0; k < n; k++) {
        if (i == j || i == k || j == k)
          continue;

          DEBUG printf("check %d %d %d\n", i,j,k);
        ans += valid(v[i], v[j], v[k]);
      }
    }
  }

  ans /= 6;

  cout << ans << "\n";
}
