#include <bits/stdc++.h>

using namespace std;

long long n, m, a, d, f, c;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> m >> n >> a >> d >> f >> c;

    long long V = (m * a) / __gcd(m, a) / a, H = (n * d) / __gcd(n, d) / d;
    cout << (V * H) / __gcd(V, H);
}