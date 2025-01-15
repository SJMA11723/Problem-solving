/**
* Author: Jorge Raul Tzab Lopez
* Github: https://github.com/SJMA11723
*/

#include <bits/stdc++.h>

using namespace std;

const int MOD = 998244353;
const int MOD2 = 998244352;

struct matrix{
    vector<vector<int>> mat;
    int n, m;
    matrix(int _n, int _m, bool I = false){
        n = _n;
        m = _m;
        mat.resize(n, vector<int>(m));
        if(I) for(int i = 0; i < n; ++i) mat[i][i] = 1;
    }

    vector<int>& operator[](int i){
        return mat[i];
    }

    matrix operator*(matrix &B){
        matrix res(n, B.m);
        for(int i = 0; i < n; ++i){
            for(int j = 0; j < B.m; ++j){
                for(int k = 0; k < m; ++k){
                    res[i][j] += 1ll * mat[i][k] * B[k][j] % MOD2;
                    if(res[i][j] >= MOD2) res[i][j] -= MOD2;
                }
            }
        }
        return res;
    }
};

matrix bin_exp(matrix &A,  int64_t n){
    if(!n) return matrix(A.n, A.n, true);
    matrix tmp = bin_exp(A, n / 2);
    if(n % 2) return tmp * tmp * A;
    return tmp * tmp;
}

namespace blackbox{
    int power(int a, int b, int m) {
  int res = 1;
  while (b > 0) {
    if (b & 1) res = 1LL * res * a % m;
    a = 1LL * a * a % m;
    b >>= 1;
  }
  return res;
}
// p is prime
int primitive_root(int p) {
  vector<int> fact;
  int phi = p - 1,  n = phi;
  for (int i = 2; i * i <= n; ++i) {
    if (n % i == 0) {
      fact.push_back(i);
      while (n % i == 0) n /= i;
    }
  }
  if (n > 1) fact.push_back(n);
  for (int res = 2; res <= p; ++res) { // this loop will run at most (logp ^ 6) times i.e. until a root is found
    bool ok = true;
    // check if this is a primitive root modulo p
    for (size_t i = 0; i < fact.size() && ok; ++i)
      ok &= power(res, phi / fact[i], p) != 1;
    if (ok)  return res;
  }
  return -1;
}
// returns any or all numbers x such that x ^ k = a (mod m)
// existence: a = 0 is trivial, and if a > 0: a ^ (phi(m) / gcd(k, phi(m))) == 1 mod m
// if solution exists, then number of solutions = gcd(k, phi(m)).
// here m is prime, but it will work for any integer which has a primitive root
int discrete_root(int k, int a, int m) {
  if (a == 0) return 1;
  //int g = primitive_root(m);
  int g = 3;
  int phi = m - 1; // m is prime
  // run baby step-giant step
  int sq = (int) sqrt (m + .0) + 1;
  vector<pair<int,int>> dec (sq);
  for (int i = 1; i <= sq; ++i) dec[i - 1] = make_pair (power (g, 1LL * i * sq % phi * k % phi, m), i);
  sort(dec.begin(), dec.end());
  int any_ans = -1;
  for (int i = 0; i < sq; ++i) {
    //cout << i << endl;
    int my = power (g, 1LL* i * k % phi, m) * 1LL * a % m;
    auto  it = lower_bound (dec.begin(), dec.end(), make_pair (my, 0));
    if (it != dec.end() && it->first == my) {
      any_ans = it->second * sq - i;
      break;
    }
  }
  if (any_ans == -1) return -1; //no solution
  // for any answer
  int delta = (m - 1) / __gcd (k, m - 1);
  return power (g, any_ans % delta, m);

  // // for all possible answers
  // int delta = (m - 1) / __gcd(k, m - 1);
  // vector<int> ans;
  // for (int cur = any_ans % delta; cur < m-1; cur += delta) ans.push_back(power(g, cur, m));
  // sort(ans.begin(), ans.end());
  // // assert(ans.size() == __gcd(k, m - 1))
  // return ans;
}
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int k; cin >> k;
    matrix A(k, k);
    for(int i = 0; i < k; ++i){
        int x; cin >> x;
        A[k - 1][k - 1 - i] = x;
        if(i + 1 < k) A[i][i + 1] = 1;
    }
    int n, m; cin >> n >> m;

    A = bin_exp(A, n - 1);
    int ans = blackbox::discrete_root(A[0][k - 1], m, MOD);
    cout << ans << '\n';
}
