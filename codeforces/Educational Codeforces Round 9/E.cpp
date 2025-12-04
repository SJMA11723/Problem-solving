/**
* Author: Jorge Raul Tzab Lopez
* Github: https://github.com/SJMA11723
*/

#include <bits/stdc++.h>

using namespace std;

typedef complex<double> comp;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<pii> vpii;
typedef vector<pll> vpll;

#define all(x) (x).begin(), (x).end()
#define fi first
#define se second
#define pb push_back
#define sz(x) (int)(x).size()

const double PI = acos(-1);
const ll MOD = 1e9 + 7;

void fft(vector<comp> &a, bool inv = false) {
    int n = sz(a);
    
    int L = 31 - __builtin_clz(n);
    
    vector <comp> roots(n);
    for(int i = 0; i < n/2; i++) {
        roots[i + n/2] = polar(1.0, 2.0 * PI * i / n * (inv ? -1.0 : 1.0));
    }

    for(int i = n / 2 - 1; i >= 1; i--) {
        roots[i] = roots[2 * i];
    }
    
    vi rev(n);
    for(int i = 0; i < n; i++) {
        rev[i] = rev[i / 2] / 2 + ((i & 1) << (L-1));
    }

    for(int i = 0; i < n; i++) {
        if(i < rev[i]) swap(a[i], a[rev[i]]);
    }

    for(int len = 1; len < n; len *= 2) {
        for(int i = 0; i < n; i += 2*len) {
            for(int j = 0; j < len; j++) {
                comp z = a[i + j + len] * roots[len + j];
                a[i + j + len] = a[i + j] - z;
                a[i + j] += z;
            }
        }
    }

    if(inv)
        for(int i = 0; i < n; i++)
            a[i] /= n;
}

vector<comp> convolution(vector<comp> A, vector<comp> B){
    int N = 1 << (32 - __builtin_clz(sz(A) + sz(B) - 1));
    A.resize(N), B.resize(N);
    fft(A);
    fft(B);
    vector<comp> C(N);
    for(int i = 0; i < N; ++i) C[i] = A[i] * B[i];
    fft(C, 1);
    return C;
}

vll poly_mult(vll &_A, vll &_B){
    vector<comp> A(sz(_A)), B(sz(_B));
    for(int i = 0; i < sz(_A); ++i) A[i] = _A[i];
    for(int i = 0; i < sz(_B); ++i) B[i] = _B[i];
    vector<comp> C = convolution(A, B);
    vll res(sz(C));
    for(int i = 0; i < sz(C); ++i) res[i] = ll(round(real(C[i]))) ? 1 : 0;
    return res;
}

vll bin_exp_it(vll &A, int n){
    vll res = {1}, powA = A;
    while(n){
        if(n & 1) res = poly_mult(res, powA);
        powA = poly_mult(powA, powA);
        n >>= 1;
    }
    return res;
}


// Recursivo da MLE (TLE)
vll bin_exp(vll &A, int n){
    if(!n) return {1};
    vll tmp  = bin_exp(A, n / 2);
    tmp = poly_mult(tmp, tmp);
    if(n & 1) return poly_mult(A, tmp);
    return tmp;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, k; cin >> n >> k;
    vll A(1001);
    for(int i = 0; i < n; ++i){
        int x; cin >> x;
        A[x] = 1;
    }
    vll ans = bin_exp_it(A, k);

    for(int i = 0; i < sz(ans); ++i)
        if(ans[i]) cout << i << " \n"[i + 1 == sz(ans)];
}