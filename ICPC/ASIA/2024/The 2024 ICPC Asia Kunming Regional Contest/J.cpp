#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    string player;
    cin >> player;

    int perm[n];
    bool vis[n];
    for (int i = 0; i < n; i++) {
      cin >> perm[i];
      perm[i]--;
      vis[i] = false;
    }
    int g = 0;
    for (int i = 0; i < n; i++) {
      if (vis[i])
        continue;
      int nxt = i;
      g++;
      while (!vis[nxt]) {
        vis[nxt] = true;
        nxt = perm[nxt];
      }
    }

    if (player == "Alice") {
      if (g == n - 1)
        cout << "Alice\n";
      else
        cout << "Bob\n";
    } else {
      if (g > 1 || (n - g) > 2)
        cout << "Bob\n";
      else
        cout << "Alice\n";
    }
  }
  return 0;
}