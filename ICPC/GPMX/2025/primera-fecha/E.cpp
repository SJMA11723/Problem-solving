
#include<bits/stdc++.h>

using namespace std;

int main(){
    int n,m;

    cin>>n>>m;

    int arr[n];

    for(int x = 0; x < n; x++) cin>>arr[x];


    int ans = -1;

    for(int x = 0; x < n; x++) {
        if(arr[x]>= m){
            ans = x+1;
            break;
        }
    }

    cout<<ans<<"\n";

}




