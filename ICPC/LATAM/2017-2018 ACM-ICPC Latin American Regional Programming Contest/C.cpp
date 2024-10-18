#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int k, n; cin >> k >> n;
    int arr[n];
    int freqs[k + 1] = {};
    for(int &x : arr){
        cin >> x;
        freqs[x]++;
    }

    int target = (n + 1) / k;
    if((n - 1) % k == 0) target = (n - 1) / k;
    else if(n % k == 0) target = n / k;

    int menor = -1, mayor = -1;
    for(int i = 1; i <= k; ++i){
        if(freqs[i] + 1 < target || target < freqs[i] - 1){
            cout << "*\n";
            return 0;
        }

        if(freqs[i] < target){
            menor = i;
        } else if(freqs[i] > target){
            mayor = i;
        }
    }

    if(menor == -1){
        freqs[mayor]--;
        if(*min_element(freqs + 1, freqs + k + 1) == *max_element(freqs + 1, freqs + k + 1))
            cout << '-' << mayor << '\n';
        else cout << "*\n";
    } else if(mayor == -1){
        freqs[menor]++;
        if(*min_element(freqs + 1, freqs + k + 1) == *max_element(freqs + 1, freqs + k + 1))
            cout << '+' << menor << '\n';
        else cout << "*\n";
    }
    else {
        freqs[menor]++;
        freqs[mayor]--;

        if(*min_element(freqs + 1, freqs + k + 1) == *max_element(freqs + 1, freqs + k + 1))
            cout << '-' << mayor << " +" << menor << '\n';
        else cout << "*\n";
    }
}
