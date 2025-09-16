#include <bits/stdc++.h>
#define DEBUG if(deb)


bool deb = true;
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;

    cin>>n;


    //int i = 2;

    int res = n;

    vector<int> div;
    bool isPrime = true;

//    while(i*i<=n){
//
//        if(n%i == 0) isPrime = false;
//        if(res%i == 0){
//            res/=i;
//            //DEBUG printf("%d\n",i);
//            if(primes.empty() || primes.back()!= i) primes.push_back(i);
//        }
//        else{
//            i++;
//        }
//    }
//
//   if(res > 1)primes.push_back(res);

    bool ap[n + 1] = {};
    for(int i = n - 1; 0 < i; --i){
        if(n % i || ap[i]) continue;

        div.push_back(i);
        for(int d = 2; d * d <= i; ++d){
            if(i % d) continue;
            ap[d] = true;
            ap[i / d] = true;
        }
    }

    if(div.back() == 1 && div.size() > 1) div.pop_back();
    {
        cout << div.size() << '\n';
        for(int d : div) cout << "1 " << d << '\n';
    }
}