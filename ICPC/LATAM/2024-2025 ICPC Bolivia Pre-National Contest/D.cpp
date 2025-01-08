#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n; cin >> n;
    while(n--){
        int a; cin >> a;
        if(a == 1){
            cout << "1 complicado\n";
            continue;
        }
        int64_t sum = -a;
        for(int d = 1; d * d <= a; ++d){
            if(a % d) continue;
            sum += d;
            if(d * d != a) sum += a / d;
        }
        if(sum == a){
            cout << a << " perfecto\n";
            continue;
        }

        int64_t sum2 = -sum;
        if(sum == 1) sum2 = 0;
        for(int d = 1; d * d <= sum; ++d){
            if(sum % d) continue;
            sum2 += d;
            if(d * d != sum) sum2 += sum / d;
        }

        if(a == sum2){
            cout << a << " romantico";
            if(a < sum) cout << " abundante";
        } else if(a < sum) cout << a << " abundante";
        else cout << a << " complicado";
        cout << '\n';
    }
}
