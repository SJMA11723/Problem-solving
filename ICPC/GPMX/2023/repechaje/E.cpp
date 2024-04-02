/**
* Author: Jorge Raul Tzab Lopez
* Github: https://github.com/SJMA11723
*/

#include <bits/stdc++.h>
#define MAXF 1000'001

using namespace std;

int sum_d(int n){
    int sum = 0;
    while(n){
        sum += n % 10;
        n /= 10;
    }
    return sum;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, k; cin >> n >> k;
    int cub[MAXF] = {};
    for(int i = 0; i < n; ++i){
        int x; cin >> x;
        cub[x]++;
    }

    int maxi = MAXF - 1;
    while(k && maxi){
        while(maxi && !cub[maxi]) maxi--;
        k = max(0, k - cub[maxi]);
        cub[maxi - sum_d(maxi)] += cub[maxi];
        cub[maxi] = 0;
    }
    cout << sum_d(maxi) << '\n';
}
