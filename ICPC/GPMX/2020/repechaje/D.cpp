#include<bits/stdc++.h>

using namespace std;

int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t; cin >> t;
    while(t--){
        int K; cin >> K;
        K += 2;
        while(K % 2 == 0) K /= 2;

        set<int> primos;
        for(int i = 3; i * i <= K && K > 1; i += 2){
            if(K % i) continue;

            while(K % i == 0) K /= i;
            primos.insert(i);
        }
        if(K > 1) primos.insert(K);

        if(primos.empty()){
            cout << "-1\n";
            continue;
        }

        int cnt = 1;
        for(int p : primos){
            cout << p;
            if(cnt < primos.size()) cout << ' ';
            cnt++;
        }
        cout << '\n';
    }

    return 0;
}
