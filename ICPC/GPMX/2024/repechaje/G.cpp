#include<bits/stdc++.h>
#define MUCHO 100005

using namespace std;

void criba(int n, vector<int> &lp){
    lp.clear();
    if(n < 2) return;
    lp.resize(n + 1);
    vector<int> primos;
    for(int64_t i = 2; i <= n; ++i){
        if(!lp[i]){
            lp[i] = i;
            primos.push_back(i);
        }
        for(int j = 0; i * primos[j] <= n; ++j){
            lp[i * primos[j]] = primos[j];
            if(primos[j] == lp[i]) break;
        }
    }
}

int n;
int arr[MUCHO];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for(int c=0; c < n; c++){
        cin >> arr[c];
    }

    vector<int> lp;
    criba(1e7, lp);

    int candi = __gcd(arr[0], arr[1]);
    arr[0]/=candi;
    arr[1]/=candi;
    set<int> primes;

    while(arr[0] > 1){
        int p = lp[arr[0]];
        primes.insert(p);
        while(arr[0] % p == 0) arr[0] /= p;
    }

    while(arr[1] > 1){
        int p = lp[arr[1]];
        primes.insert(p);
        while(arr[1] % p == 0) arr[1] /= p;
    }

    for(int c=2; c < n; c++){
        if(arr[c] % candi){
            cout << "NO\n";
            return 0;
        }

        arr[c] /= candi;

        bool coprimos = true;
        while(arr[c] > 1){
            int p = lp[ arr[c] ];
            if(primes.count(p)) coprimos = false;
            primes.insert(p);
            while(arr[c] % p == 0) arr[c] /= p;
        }

        if(!coprimos){
            cout << "NO\n";
            return 0;
        }
    }
    cout << "YES\n";
}
