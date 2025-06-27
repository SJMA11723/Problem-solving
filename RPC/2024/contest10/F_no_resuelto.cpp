#include <bits/stdc++.h>

using namespace std;

bool check(int c1, int m1, int c2, int m2, int n){
    uint64_t l = 0, r = (1 << n) + 1;
//    uint64_t b = c1 + m1;
//    uint64_t d = c2 + m2;
//    uint64_t a = c1;
//    uint64_t c = c2;

    long double b = c1 + m1;
    long double d = c2 + m2;
    long double a = c1;
    long double c = c2;


    if(a * d > c * b){
        swap(a, c);
        swap(b, d);
    }

    uint64_t mini = min((1ull << n) * a * d, (1ull << n) * c * b);

    while(l < r){
        uint64_t mid = l + (r - l) / 2;
        if((long double)mid / (1ll << n) < a / b) l = mid + 1;
        else r = mid;
    }

    //cout << n << ' ' << l << ' ' << ((long double)l / (1ll << n) <= c / d) << '\n';

    //return l * b * d <= max((1ull << n) * a * d, (1ull << n) * c * b);
    return (long double)l / (1ll << n) <= c / d;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int c1, m1, c2, m2;
    cin >> c1 >> m2 >> c2 >> m2;

    int l = 0, r = 22;
    while(l < r){
        int mid = l + (r - l) / 2;
        if(check(c1, m1, c2, m2, mid)) r = mid;
        else l = mid + 1;
    }
    cout << l << '\n';
}
