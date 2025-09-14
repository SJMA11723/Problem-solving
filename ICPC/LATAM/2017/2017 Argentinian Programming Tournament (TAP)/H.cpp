// Source: https://usaco.guide/general/io

#include <bits/stdc++.h>
using namespace std;

int main() {
int n;
    cin>>n;

    int arr[n+1];
    for(int x = 1; x <= n; x++) cin>>arr[x];
    arr[0] = 0;
    int ans = 0;
    bool up = false;
    for(int i = 1; i <= n; i++){
        if(arr[i] > arr[i-1] && !up) {
            ans++;
            up = true;
        }
        else if(arr[i] < arr[i-1]){
            up = false;
        }
    }

    cout<<ans<<"\n";
}
