#include <iostream>
#include <vector>
#define INF 3000000000000000000
#define MAXN 5010
#define MAXK 21
#define DEBUG if (deb)

long long dp[MAXN][MAXK];
bool days[5010];
bool deb = false;
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n, k;
  cin >> n >> k;
  int arr[n + 1];
  arr[0] = -1;
  pair<int, int> ord[n + 1];
  for (int x = 1; x <= n; x++) {
    cin >> arr[x];
    ord[x] = {arr[x], x};
  }
  sort(arr, arr + n + 1);
  sort(ord, ord + n + 1);

  for (int i = 0; i <= n; i++) {
    dp[i][0] = INF;
  }
  for (int j = 0; j <= k; j++) {
    dp[0][j] = 0;
  }

  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= k; j++) {
      dp[i][j] = INF;
      // j-sticks left, putting stick at pos i
      long long cost = 0;
      for (int x = i; x >= 1; x--) {
        cost += (long long)(arr[i] - arr[x]) * (arr[i] - arr[x]);
        DEBUG printf("cost %lld at %d %d %d\n", cost, i, j, x);
        DEBUG printf("dp[%d] [%d]= %lld \n", x - 1, j - 1, dp[x - 1][j - 1]);
        dp[i][j] = min(dp[i][j], cost + dp[x - 1][j - 1]);
        dp[i][j] = min(dp[i][j], (long long)INF);
        DEBUG printf("my dp[%d][%d] = %lld\n", i, j, dp[i][j]);
      }
    }
  }

  int i = n, j = k;

  while (i > 0) {
    DEBUG printf("%d->", i);
    days[i] = true;
    int minx = -1;
    long long mintrans = INF;
    long long cost = 0;
    for (int x = i; x >= 1; x--) {
      cost += (long long)(arr[i] - arr[x]) * (arr[i] - arr[x]);
      long long transition = cost + dp[x - 1][j - 1];
      if (transition < mintrans) {
        mintrans = transition;
        minx = x - 1;
      }
    }
    i = minx;
    j--;
  }

  int preans[n + 1];
  int pivot;
  int lol = 0;
  for (int i = n; i >= 0; i--) {
    if (days[i]) {
      lol++;
      DEBUG printf("ll%d\n", arr[i]);
      pivot = arr[i];
    }
    preans[i] = pivot;
  }

  int ans[n + 1];

  for (int x = 0; x <= n; x++) {
    auto [val, ogidx] = ord[x];
    ans[ogidx] = preans[x];
  }

  for (int x = 1; x <= n; x++)
    cout << ans[x] << " ";
}